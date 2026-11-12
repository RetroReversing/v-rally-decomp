extern s32 D_800A1860;
extern s32 D_800A1864;
extern s32 D_800A1868;
extern s32 D_800A186C;
extern s32 D_800A1870;
extern s32 D_800A1874;
extern f32 sSavedCosX;
extern f32 sSavedCosY;
extern u8 gGameState[];
extern u8 gOrderState[];
extern u8 stream_state[];
void *func_8002DA98(void *arg0, void *arg1);
void *mtx3_transform_vec3(void *arg0, void *arg1, void *arg2);
typedef struct { s32 b[3]; s32 c[3]; f32 t1; f32 t2; } LookS;
#define G (*(LookS *)(stream_state + 0x5D32))
#define CAM(i) (((s32 *)(gOrderState + 0x6E8C))[i])
#define AMB (*(u16 *)(gGameState + 0x6BE6))

typedef struct { s16 x, y, z, pad; s32 unk8; u32 col; } V16;
typedef struct { u32 col; s16 x, y, z; s16 pad; u8 rest[12]; } V24;
typedef struct {
    u8 pad0[0x30];
    V24 *v24[12];
    V16 *v16[12];
    u16 n16[12];
    u16 n24[12];
} LObj;

static inline u32 brightness_to_u32(f32 brightness, f32 integer_limit) {
    u32 converted;
    if (!(brightness >= integer_limit))
        converted = (u32)(s32)brightness;
    else {
        converted = (u32)(s32)(brightness-integer_limit);
        converted |= 0x80000000u;
    }
    return converted;
}

/* Lights a light object's vertices. Two sets are lit: 12 groups of 16-bit
 * vertices (v16, n16) and 12 groups of 24-bit vertices (v24, n24). For each
 * vertex, the light direction (from the light position toward the light
 * target) is compared with the direction to the vertex: inside the cone the
 * colour is full brightness, in the falloff ring it is blended toward the
 * ambient level, and outside it is ambient. The result is packed into the
 * vertex's colour word. */
void light_object_vertices(void *owner, s32 mode)
{
    LObj *o = owner;
    s16 p[3];
    s16 q[3];
    typedef struct { s16 rotation[9]; s16 alignment; s32 translation[3]; } Matrix;
    Matrix m;
    u8 stack_padding[16];
    f32 dx, dy, dz, len, s;
    f32 integer_limit;
    f32 ex, ey, ez, dot, f, amb, k, g1;
    s32 i, j, n, j2;
    s32 full;
    u32 c;
    u32 lo, hi;
    LookS *L;
    u16 *ap;
    V16 *v;
    V24 *w;

    func_8002DA98(gOrderState + 0x6E78, &m);
    p[0] = (u32)D_800A1860 - (u32)CAM(0);
    p[1] = (u32)D_800A1864 - (u32)CAM(1);
    p[2] = (u32)D_800A1868 - (u32)CAM(2);
    mtx3_transform_vec3(&m, p, p);
    q[0] = (u32)D_800A186C - (u32)CAM(0);
    q[1] = (u32)D_800A1870 - (u32)CAM(1);
    q[2] = (u32)D_800A1874 - (u32)CAM(2);
    mtx3_transform_vec3(&m, q, q);
    dx = p[0] - q[0];
    s = dx * dx;
    dy = p[1] - q[1];
    s += dy * dy;
    dz = p[2] - q[2];
    s += dz * dz;
    len = __builtin_sqrtf(s);
    dx /= len;
    dy /= len;
    dz /= len;
    integer_limit=2147483648.0f; full = 0xFF;
    ap = &AMB;
    {
    LookS *g = &G;
    g->b[0] = p[0];
    L = g;
    }
    G.b[1] = p[1];
    G.b[2] = p[2];
    G.c[0] = q[0];
    G.c[1] = q[1];
    G.c[2] = q[2];
    G.t1 = sSavedCosX;
    G.t2 = sSavedCosY;
    for (i = 0; i < 12; i++) {
        n = o->n16[i];
        v = o->v16[i];
        j = 0;
        if (n != 0) {
            do {
                k = 255.0f;
                ex = L->b[0] - v->x;
                s = ex * ex;
                ey = L->b[1] - v->y;
                s += ey * ey;
                ez = L->b[2] - v->z;
                s += ez * ez;
                len = __builtin_sqrtf(s);
                ex /= len;
                ey /= len;
                ez /= len;
                dot = ex * dx + ey * dy + ez * dz;
                c = full;
                if (L->t1 < dot) {
                    lo = c << 8;
                    hi = c << 16; hi += 1;
                } else if (L->t2 < dot) {
                    g1 = (dot - L->t2) / (1.0f - L->t2);
                    amb = *ap;
                    if (len < 1200.0f) {
                        g1 = len * g1 * 0.00083333335f;
                    }
                    c = (u8)brightness_to_u32(g1 * (k - amb) + amb, integer_limit);
                    lo = c << 8;
                    hi = c << 16; hi += 2;
                } else {
                    c = (u8)*ap;
                    lo = c << 8;
                    hi = c << 16; hi += 4;
                }
                lo += hi;
                lo += c << 24;
                v->col = lo;
                v++;
                j++;
            } while (j < n);
        }
        w = o->v24[i];
        n = o->n24[i];
        j2 = 0;
        if (n != 0) {
            do {
                k = 255.0f;
                ex = L->b[0] - w->x;
                s = ex * ex;
                ey = L->b[1] - w->y;
                s += ey * ey;
                ez = L->b[2] - w->z;
                s += ez * ez;
                len = __builtin_sqrtf(s);
                ex /= len;
                ey /= len;
                ez /= len;
                dot = ex * dx + ey * dy + ez * dz;
                c = full;
                if (L->t1 < dot) {
                    lo = c << 8;
                    hi = c << 16; hi += 1;
                    lo += hi; lo += c << 24; w->col = lo;
                } else if (L->t2 < dot) {
                    amb = *ap;
                    f = k - amb; f -= (L->t1 - dot) * f / (L->t1 - L->t2);
                    g1 = f + amb;
                    c = (u8)brightness_to_u32(g1, integer_limit);
                    lo = c << 8;
                    hi = c << 16; hi += 2;
                    lo += hi; lo += c << 24; w->col = lo;
                } else {
                    c = (u8)*ap;
                    lo = c << 8;
                    hi = c << 16; hi += 4;
                    lo += hi; lo += c << 24; w->col = lo;
                }

                w++;
                j2++;
            } while (j2 < n);
        }
    }
}
