/* Port-only C (WebAssembly build): written from the assembly so it behaves as the game does, not matching C.
 * The project still has this function open for agents to match. */
#include "common.h"
#include "gap.h"
/* port: rewritten from the asm (the m2c draft dropped arg0 from the signature, gave the callees the
 * wrong arity, and did byte offsets as s32-pointer arithmetic). Every callee takes one argument at
 * most: view_get_ctx_id(view) -> ctx id, gfx_get_dl(ctx) -> display-list pointer,
 * gfx_set_dl(ctx, dl) stores it back, func_80009E54() hands out a fresh 0x60-byte record,
 * osVirtualToPhysical(addr) is osVirtualToPhysical. */
s32 view_get_ctx_id(void *);
s32 gfx_get_dl(s32);
void gfx_set_dl(s32, s32);
s32 func_80009E54(void);
s32 osVirtualToPhysical(void *);
extern M2C_UNK D_8009B5D0;
extern M2C_UNK D_800AE850;

/* The object's texture descriptor at obj+0xC, re-read every time like the asm does. */
#define TEX(obj)        M2C_FIELD(obj, u8 **, 0xC)
#define TEX_FMT(t)      M2C_FIELD(t, u16 *, 0x4)
#define TEX_STRIDE(t)   M2C_FIELD(t, u16 *, 0x6)
#define TEX_HEIGHT(t)   M2C_FIELD(t, u8 *, 0x9)
#define TEX_ROWS(t)     M2C_FIELD(t, u16 *, 0xC)
#define TEX_CHUNKS(t)   M2C_FIELD(t, u16 *, 0xE)
#define TEX_BASE(t)     (*M2C_FIELD(t, s32 **, 0x14))

/* One display-list command: two 32-bit words at p, which advances past them. */
#define GCMD(p, a, b) { u32 *g_ = (u32 *)(p); (p) += 8; g_[0] = (u32)(a); g_[1] = (u32)(b); }

/* Copies a 0x60-byte object record (24 words), backwards when dst overlaps the end of src. */
static void copy_record(u8 *dst, u8 *src) {
    u32 *s;
    u32 *d;
    s32 n = 0x18;

    if (((u32) dst < (u32) (src + 0x60)) & ((u32) src < (u32) dst)) {
        s = (u32 *) (src + 0x60);
        d = (u32 *) (dst + 0x60);
        do {
            s--;
            d--;
            n--;
            *d = *s;
        } while (n != 0);
    } else {
        s = (u32 *) src;
        d = (u32 *) dst;
        do {
            u32 v = *s++;
            n--;
            *d++ = v;
        } while (n != 0);
    }
}

/* Fills chunk i (all but the last) of a tall texture split into chunks of TEX_ROWS rows. half is 1 for
 * the 4-bit format (0x10), whose byte offset is half the texel count; 0 for the 8-bit one (0x100). */
static void set_chunk(u8 *rec, u8 *obj, s32 y, s32 i, s32 half) {
    u8 *t;
    s32 off;

    M2C_FIELD(rec, s16 *, 0x34) = (s16) (TEX_ROWS(TEX(obj)) * 4 - 1);
    M2C_FIELD(rec, s16 *, 0x4C) = (s16) (TEX_ROWS(TEX(obj)) << 5);
    t = TEX(obj);
    off = (s32) (i * TEX_ROWS(t)) * TEX_STRIDE(t);
    M2C_FIELD(rec, s32 *, 0x2C) = TEX_BASE(t) + (half ? off / 2 : off);
    t = TEX(obj);
    off = (s32) (i * TEX_ROWS(t)) * TEX_STRIDE(t);
    M2C_FIELD(rec, s32 *, 0x38) = TEX_BASE(t) + (half ? off / 2 : off);
    M2C_FIELD(rec, s16 *, 0x48) = (s16) ((y + i * TEX_ROWS(TEX(obj))) * 4);
}

/* The last chunk: whatever rows of TEX_HEIGHT the earlier chunks didn't cover. */
static void set_last_chunk(u8 *rec, u8 *obj, s32 y, s32 i, s32 half) {
    u8 *t = TEX(obj);
    s32 rows = (u8) (TEX_HEIGHT(t) - (TEX_CHUNKS(t) - 1) * TEX_ROWS(t));
    s32 off;

    M2C_FIELD(rec, s16 *, 0x4C) = (s16) (rows << 5);
    M2C_FIELD(rec, s16 *, 0x34) = (s16) (rows * 4 - 1);
    M2C_FIELD(rec, s16 *, 0x48) = (s16) ((y + i * TEX_ROWS(TEX(obj))) * 4);
    t = TEX(obj);
    off = (s32) (i * TEX_ROWS(t)) * TEX_STRIDE(t);
    M2C_FIELD(rec, s32 *, 0x2C) = TEX_BASE(t) + (half ? off / 2 : off);
    t = TEX(obj);
    off = (s32) (i * TEX_ROWS(t)) * TEX_STRIDE(t);
    M2C_FIELD(rec, s32 *, 0x38) = TEX_BASE(t) + (half ? off / 2 : off);
}

/* Draws a sprite object (obj, a 0x60-byte record) at (x, y) into view's display list. flags: bit 0/2
 * pick the render mode, 0x10 an extra othermode, 0x80/0x40 set obj[0x57], 0x20 loads the texture
 * per chunk (segment 2 = chunk record) instead of drawing the object directly. color (RGBA bytes)
 * is the primitive colour, or a fixed combine when NULL. A texture taller than one chunk is drawn
 * as TEX_CHUNKS records, each a copy of obj shifted down by TEX_ROWS rows. */
void func_8000A840(void *view, s32 x, s32 y, u8 *obj, s32 flags, u8 *color) {
    s32 ctx;
    u8 *dl;
    u8 *rec;
    u8 *t;
    s32 n;
    s32 i;
    s32 half;
    u32 mode;

    ctx = view_get_ctx_id(view);
    dl = (u8 *) gfx_get_dl(ctx);
    GCMD(dl, 0xDE000000, &D_8009B5D0);
    if (flags & 1) {
        mode = (flags & 4) ? 0x503048 : 0x0F0A4000;
    } else {
        mode = (flags & 4) ? 0x5041C8 : 0x504240;
    }
    GCMD(dl, 0xE200001C, mode);
    if (flags & 0x10) {
        GCMD(dl, 0xE200001C, 0);
        GCMD(dl, 0xE3000A01, 0x200000);
    } else {
        GCMD(dl, 0xE3000A01, 0);
    }
    if (flags & 0x80) {
        obj[0x57] = 0x10;
    }
    if (flags & 0x40) {
        obj[0x57] = 1;
    }
    if (color != NULL) {
        GCMD(dl, 0xFCFFFE61, 0xFF64F3FF);
        GCMD(dl, 0xFA000000, ((u32) color[0] << 24) | ((u32) color[1] << 16) | ((u32) color[2] << 8) | color[3]);
    } else {
        GCMD(dl, 0xFC119623, 0xFF2FFFFF);
        GCMD(dl, 0xFA000000, -0x80);
    }
    GCMD(dl, 0xFB000000, 0x80);
    GCMD(dl, 0xE3001001, 0x8000);
    GCMD(dl, 0xE7000000, 0);
    GCMD(dl, 0x05000017, obj + 0x10);

    *(s16 *) (obj + 0x40) = (s16) (x * 4);
    *(s16 *) (obj + 0x48) = (s16) (y * 4);
    t = TEX(obj);
    n = TEX_CHUNKS(t);

    if (flags & 0x20) {
        /* Textured through segments: each chunk's record is a sprite of its own. */
        if (n == 1) {
            rec = (u8 *) func_80009E54();
            copy_record(rec, obj);
        } else {
            if (TEX_FMT(t) == 0x10) {
                half = 1;
            } else if (TEX_FMT(t) == 0x100) {
                half = 0;
            } else {
                goto seg_done;
            }
            i = 0;
            if (n - 1 > 0) {
                do {
                    rec = (u8 *) func_80009E54();
                    copy_record(rec, obj);
                    set_chunk(rec, obj, y, i & 0xFF, half);
                    GCMD(dl, 0x05000017, osVirtualToPhysical(rec + 0x28));
                    GCMD(dl, 0xDC170000, osVirtualToPhysical(M2C_FIELD(rec, void **, 0x58)));
                    GCMD(dl, 0x02000000, osVirtualToPhysical(rec + 0x40));
                    GCMD(dl, 0xE7000000, 0);
                    i++;
                } while ((i & 0xFF) < TEX_CHUNKS(TEX(obj)) - 1);
            }
            rec = (u8 *) func_80009E54();
            copy_record(rec, obj);
            set_last_chunk(rec, obj, y, i & 0xFF, half);
        }
        GCMD(dl, 0x05000017, osVirtualToPhysical(rec + 0x28));
        GCMD(dl, 0xDC170000, osVirtualToPhysical(M2C_FIELD(rec, void **, 0x58)));
        GCMD(dl, 0x02000000, osVirtualToPhysical(rec + 0x40));
seg_done:
        GCMD(dl, 0xDC170000, osVirtualToPhysical((u8 *) &D_800AE850 + 0x20));
    } else {
        /* Drawn directly: 0x0800002F with the record's own (virtual) address. */
        if (n == 1) {
            rec = (u8 *) func_80009E54();
            copy_record(rec, obj);
            GCMD(dl, 0x0800002F, rec + 0x28);
        } else {
            if (TEX_FMT(t) == 0x10) {
                half = 1;
            } else if (TEX_FMT(t) == 0x100) {
                half = 0;
            } else {
                goto direct_done;
            }
            i = 0;
            if (0 < n - 1) {
                do {
                    rec = (u8 *) func_80009E54();
                    copy_record(rec, obj);
                    set_chunk(rec, obj, y, i & 0xFF, half);
                    GCMD(dl, 0x0800002F, rec + 0x28);
                    GCMD(dl, 0xE7000000, 0);
                    i++;
                } while ((i & 0xFF) < TEX_CHUNKS(TEX(obj)) - 1);
            }
            rec = (u8 *) func_80009E54();
            copy_record(rec, obj);
            set_last_chunk(rec, obj, y, i & 0xFF, half);
            GCMD(dl, 0x0800002F, rec + 0x28);
        }
    }
direct_done:
    GCMD(dl, 0xE7000000, 0);
    gfx_set_dl(ctx, (s32) dl);
}
