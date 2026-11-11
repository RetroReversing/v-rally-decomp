#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 scaleMatrixByVec();
s32 mat3x3_from_euler();
extern u8 *gRecords;

/* Initialises the transform of object dst from the source object src: the
 * view scale is derived from src's speed (+0xDC) and the view mode, the
 * rotation and scale vectors are built from it, and the sub-blocks of dst
 * are cleared. */
void func_80023F58(void *src, void *dst, s32 unused)
{
    s16 rot[3];
    s32 scale[9];
    s32 val90;
    u32 pad_a2;
    s32 speed;
    u16 mode;
    void *blk_2C;
    void *blk_0C;
    void *blk_20;
    void *blk_34;
    void *blk_48;
    void *blk_5C;
    void *blk_70;
    void *blk_98;
    void *blk_AC;
    void *blk_C0;
    void *blk_D4;

    pad_a2 = unused;
    blk_2C = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_2C + 0) = 0;
    *(s32 *)((char *)blk_2C + 4) = 0x32;
    val90 = *(s32 *)((char *)src + 0x90);
    {
        const u8 *gptr;
        gptr = gRecords;
        *(s32 *)((char *)blk_2C + 8) = val90;
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        mode = *(u16 *)(gptr + 0x16);
    }
    speed = *(s32 *)((char *)src + 0xDC);
    switch (mode) {                            /* irregular */
    case 0:
        pad_a2 = 0;
        speed -= *(s32 *)((char *)src + 0xDC) / 10;
    case 1:
        break;
    case 2:
        pad_a2 = 0;
        speed += *(s32 *)((char *)src + 0xDC) / 10;
        break;
    }
    M2C_FIELD(*(void * *)((char *)dst + 0x84), s32 *, 0x40) = speed;
    M2C_FIELD(*(void * *)((char *)dst + 0x84), s32 *, 0x44) = (s32) (0x3E8000 / speed);
    mat3x3_from_euler(&rot[0], *(void * *)((char *)dst + 0x84));
    scale[0] = (*(s32 *)((char *)src + 0x128) * speed) / 1000;
    scale[1] = (*(s32 *)((char *)src + 0x174) * speed) / 1000;
    scale[2] = (*(s32 *)((char *)src + 0x1C0) * speed) / 1000;
    scaleMatrixByVec(*(void * *)((char *)dst + 0x84), &scale[0]);
    scale[0] = 0x20000 / scale[0];
    scale[1] = 0x20000 / scale[1];
    scale[2] = 0x20000 / scale[2];
    mat3x3_from_euler(&rot[0], *(void * *)((char *)dst + 0x84) + 0x20);
    scaleMatrixByVec(*(void * *)((char *)dst + 0x84) + 0x20, &scale[0]);
    blk_0C = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_0C + 0xC) = 0;
    *(s32 *)((char *)blk_0C + 0x10) = 0;
    *(s32 *)((char *)blk_0C + 0x14) = 0;
    blk_20 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_20 + 0x20) = 0;
    *(s32 *)((char *)blk_20 + 0x24) = 0;
    *(s32 *)((char *)blk_20 + 0x28) = 0;
    blk_34 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_34 + 0x34) = 0;
    *(s32 *)((char *)blk_34 + 0x38) = 0;
    *(s32 *)((char *)blk_34 + 0x3C) = 0;
    blk_48 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_48 + 0x48) = 0;
    *(s32 *)((char *)blk_48 + 0x4C) = 0;
    *(s32 *)((char *)blk_48 + 0x50) = 0;
    M2C_FIELD(*(void * *)((char *)dst + 0x84), s32 *, 0x48) = (s32) *(s32 *)((char *)src + 0x20C);
    M2C_FIELD(*(void * *)((char *)dst + 0x2C), s32 *, 0x50) = 0;
    M2C_FIELD(*(void * *)((char *)dst + 0x2C), s32 *, 0x4C) = (s32) (*(s32 *)((char *)src + 0x258) << 5);
    blk_5C = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_5C + 0x5C) = 0;
    *(s32 *)((char *)blk_5C + 0x60) = 0;
    *(s32 *)((char *)blk_5C + 0x64) = 0;
    blk_70 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_70 + 0x70) = 0;
    *(s32 *)((char *)blk_70 + 0x74) = 0;
    *(s32 *)((char *)blk_70 + 0x78) = 0;
    blk_98 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_98 + 0x98) = 0;
    *(s32 *)((char *)blk_98 + 0x9C) = 0;
    *(s32 *)((char *)blk_98 + 0xA0) = 0;
    blk_AC = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_AC + 0xAC) = 0;
    *(s32 *)((char *)blk_AC + 0xB0) = 0;
    *(s32 *)((char *)blk_AC + 0xB4) = 0;
    blk_C0 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_C0 + 0xC0) = 0;
    *(s32 *)((char *)blk_C0 + 0xC4) = 0;
    *(s32 *)((char *)blk_C0 + 0xC8) = 0;
    blk_D4 = *(void * *)((char *)dst + 0x2C);
    *(s32 *)((char *)blk_D4 + 0xD4) = 0;
    *(s32 *)((char *)blk_D4 + 0xD8) = 0;
    *(s32 *)((char *)blk_D4 + 0xDC) = 0;
    M2C_FIELD(*(void * *)((char *)dst + 0x80), s32 *, 0x388) = (s32) ((speed * 0xA) / 22);
    M2C_FIELD(*(void * *)((char *)dst + 0x88), s32 *, 0x84) = 0;
}
