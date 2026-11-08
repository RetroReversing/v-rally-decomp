typedef struct { u32 w0, w1; } Gfx;
typedef struct { char pad[0x14]; Gfx *gfx; } DLBuf;
typedef struct { char pad[0x38]; char mtx[0xE0]; f32 x, y, z; } Camera; /* x at 0x118 */
typedef struct { char pad[4]; u16 mode; } Config;
typedef struct { char pad[6]; u16 w; u16 h; } Tex;
typedef struct { char pad[4]; Tex **tex; } Model;
typedef struct {
    u16 active;      /* 0x00 */
    char pad2[2];
    u16 c4, c6, c8;  /* 0x04 */
    char padA[8];
    u16 texIdx;      /* 0x12 */
    char pad14[4];
    u16 size;        /* 0x18 */
    char pad1A[4];
    u8 alpha;        /* 0x1E */
    u8 pad1F;
    Model *model;    /* 0x20 */
} Entry;
typedef struct { char pad[0x54]; s32 x, y, z; } Pos;
typedef struct { char pad[0x5C]; Pos *pos; } Obj;
typedef struct { s8 a; s8 b; s16 c; s16 d; u16 e; u16 f; u16 g; } Draw;

Gfx *func_80006008(DLBuf *);
void func_80006014(DLBuf *, Gfx *);
void *func_8001BD1C(void);
void guMtxIdentF(f32 (*)[4]);
void func_80010BFC(void *, void *, f32 (*)[4]);
void func_800061FC(DLBuf *, void *);
void func_800075BC(DLBuf *, Tex *, s32);
void func_80019C90(DLBuf *, void *, Draw *, u16, u16);
extern char D_8009EAB0[];
extern Config *D_800C811C;
extern Camera *D_800C7F84;
extern u16 D_800ADFC6[3];
extern const f64 D_800A4A50;
extern const f64 D_800A4A58;
extern s32 D_800AFA8C;

#define CLMP(v) ((v) >= 256 ? 255 : (v))
#define GCMD(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (b); }

/* Draws a list of sprite entries for one object. `count` entries are walked
 * (every second one when `twice` is set). The first active entry opens the
 * display list and sets the tint from the colour table D_800ADFC6 (doubled,
 * clamped to 255) according to the config mode. Then, if the object is within
 * range of the camera, its transform is loaded once, and each active entry is
 * drawn with its texture and size. */
void func_8002EE00(Obj *obj, Entry *e, s32 count, DLBuf *buf, s32 arg4, u8 twice)
{
    f32 mf[4][4];
    Draw draw;
    Gfx *dl;
    Gfx *p;
    void *m;
    u8 done;
    u8 started;
    s32 r, g, b;
    u32 c;
    s32 d;
    s32 dy, dz;
    f32 x;

    done = 0;
    started = 0;
    if (twice) {
        count = (u32)count >> 1;
    }
    while (count--) {
        if (e->active != 0) {
            if (!started) {
                dl = func_80006008(buf);
                started = 1;
                GCMD(dl++, 0xDE000000, (u32)D_8009EAB0);
                switch (D_800C811C->mode) {
                case 2:
                    GCMD(dl++, 0xFA000000, -1);
                    GCMD(dl++, 0xFB000000,
                         (((u32)({ r = D_800ADFC6[0] * 2; if (r >= 256) r = 255; r; }) & 0xFF) << 24) |
                         (((u32)({ g = D_800ADFC6[1] * 2; if (g >= 256) g = 255; g; }) & 0xFF) << 16) |
                         (((u32)({ b = D_800ADFC6[2] * 2; if (b >= 256) b = 255; b; }) & 0xFF) << 8) |
                         ((u32)e->alpha & 0xFF));
                    break;
                case 1:
                    GCMD(dl++, 0xFA000000, -1);
                    p = dl++;
                    p->w0 = 0xFB000000;
                    r = D_800ADFC6[0] * 2;
                    if (r >= 256) r = 255;
                    d = r << 24;
                    g = D_800ADFC6[1] * 2;
                    if (g >= 256) g = 255;
                    c = d | ((g & 0xFF) << 16);
                    b = D_800ADFC6[2] * 2;
                    if (b >= 256) b = 255;
                    p->w1 = c | ((b & 0xFF) << 8) | e->alpha;
                default:
                    GCMD(dl++, 0xFB000000, e->alpha | 0xFFFFFF00);
                    GCMD(dl++, 0xFA000000, -1);
                    break;
                }
                func_80006014(buf, dl);
            }
            if (!done) {
                done = 1;
                m = func_8001BD1C();
                guMtxIdentF(mf);
                x = obj->pos->x;
                if (!(abs((s32)(x - D_800C7F84->x)) < D_800A4A50)) return;
                if (!(abs((s32)((f32)obj->pos->y - D_800C7F84->y)) < D_800A4A58)) return;
                if (!(abs((s32)((f32)obj->pos->z - D_800C7F84->z)) < D_800A4A50)) return;
                mf[3][0] = x;
                mf[3][1] = obj->pos->y;
                mf[3][2] = obj->pos->z;
                func_80010BFC(m, D_800C7F84->mtx, mf);
                func_800061FC(buf, m);
            }
            if (done == 1) {
                D_800AFA8C++;
                func_800075BC(buf, e->model->tex[e->texIdx], 0);
                draw.a = 3;
                draw.b = 0;
                draw.c = e->size * 2;
                draw.d = e->size * 2;
                draw.e = e->c4;
                draw.f = e->c6;
                draw.g = e->c8;
                func_80019C90(buf, D_800C7F84->mtx, &draw, e->model->tex[0]->w, e->model->tex[0]->h);
            }
        }
        e++;
        if (twice) {
            e++;
        }
    }
}
