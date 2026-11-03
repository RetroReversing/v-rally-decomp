typedef struct { u32 w0, w1; } Gfx;
typedef struct { f32 m[4][4]; } MtxF;
typedef struct { u32 w[16]; } Blk40;

typedef struct Ctx { u8 pad0[0x14]; Gfx *dl; u8 pad18[0x60]; s16 unk78; } Ctx;

typedef struct Ent { s32 x, y, z; s16 unkC, unkE, unk10; s16 pad12; } Ent;

typedef struct Node {
    s32 unk0;
    struct Node *unk4;
    u8 unk8[0x30];
    f32 unk38, unk3C, unk40;
    u8 pad44[4];
    MtxF unk48;
    Ent *unk88;
    u8 pad8C[4];
    s32 unk90;
} Node;

typedef struct Tex { u8 pad[6]; u16 unk6; u16 unk8; } Tex;
typedef struct Mdl { u8 pad[4]; Tex **unk4; } Mdl;
typedef struct Shd { u8 pad[0xC]; Mdl *unkC; u8 unk10; } Shd;

typedef struct Q { u8 pad[8]; u8 *unk8; u8 padC[4]; Node **unk10; } Q;

typedef struct R {
    Q *unk0;
    s32 *unk4;
    Node *wheels[4];
    Ent ent[4];
    Shd *unk68;
    s32 pad6C;
    s32 unk70;
    u8 pad74[0xC];
    s32 unk80;
} R;

typedef struct Part { u8 pad[0x10]; u8 unk10[0x14]; s32 unk24, unk28, unk2C; u8 pad30[0x3C]; u8 *unk6C; u8 pad70[0x1A]; u16 unk8A; } Part;

typedef struct W {
    Part *parts[12];
    u8 pad30[0x80];
    s32 unkB0, unkB4, unkB8; s32 padBC[2];
    s32 unkC4, unkC8, unkCC; s32 padD0[2];
    s32 unkD8, unkDC, unkE0; s32 padE4[2];
    s32 unkEC, unkF0, unkF4;
} W;

typedef struct Type { s32 unk0; u8 pad4[0x1C]; s32 unk20; u8 pad24[8]; s32 unk2C; } Type;
typedef struct Pos { u8 pad[0x54]; s32 unk54, unk58, unk5C; } Pos;
typedef struct Dist { u8 pad[0x30]; s32 unk30; } Dist;
typedef struct Trk { u8 pad[0x1F4]; s32 unk1F4; u8 pad1F8[0x10]; s32 unk208; u8 pad20C[0x10]; s32 unk21C; u8 pad220[0x10]; s32 unk230; } Trk;

typedef struct Obj {
    struct Obj *unk0;
    struct Obj *unk4;
    u8 pad8[0x40];
    Type *unk48;
    u8 pad4C[8];
    s32 *unk54;
    u8 pad58[4];
    Pos *unk5C;
    s32 *unk60;
    u8 pad64[8];
    Dist *unk6C;
    u8 pad70[0x10];
    Trk *unk80;
    u8 pad84[4];
    R *unk88;
    W *unk8C;
} Obj;

typedef struct Game { u8 pad[0x20]; u16 unk20; u8 pad22[2]; Obj *unk24; u8 pad28[0x150]; s32 unk178; } Game;
typedef struct Mode { u8 pad[0xE]; u16 unkE; u8 pad10[8]; u16 unk18; u16 unk1A; u16 unk1C; u16 unk1E; u8 pad20[0xC]; u16 unk2C; } Mode;
typedef struct Ext { u8 pad[0x384]; u8 unk384; } Ext;

extern Game *D_800C7F84;
extern u8 D_8009C0A8[];
extern u8 D_8009C1A0[];
extern s32 D_8009FF30;
extern Ext *D_800A0384;
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];

#define gGame D_800C7F84
#define gMode (*(Mode **)(D_800C02AE + 0x32F2))
#define gB7D3B (*(u8 *)(D_800C02AE + 0x7D3B))
#define gB7678 (*(u8 *)(D_800C02AE + 0x7678))
#define gB7FC8 (*(u8 *)(D_800AE850 + 0x7FC8))
#define gMtx72B0 ((f32 (*)[4])(D_800AE850 + 0x72B0))
#define gCol ((u16 *)(D_800A73E0 + 0x6BE6))

Ctx *func_800056FC(s32);
void func_80005F14(Ctx *, s32);
Gfx *func_80006008(Ctx *);
void func_80006014(Ctx *, Gfx *);
void func_800061FC(Ctx *, void *);
void func_800068C0(Ctx *, u16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16);
u16 func_800070CC(Ctx *);
void func_800071EC(Ctx *, u16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16);
void func_800075BC(Ctx *, Tex *, s32);
void func_80008B28(Ctx *, u16, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(void *, MtxF *, void *);
void func_80016910(Ctx *, s32);
void func_800169DC(Ctx *, s32);
void *func_8001BD1C(void);
void func_8001C2C0(void *, void *, void *);
void func_8002DF40(void *, void *);
void func_8002E0B8(MtxF *, void *);
void func_80051D10(Ctx *, Obj *, MtxF *, s32);
s32 func_8007BA1C(Obj *);
s32 isBoundingBoxVisible(MtxF *, void *, s32);
u32 osVirtualToPhysical(void *);

#define ENVCOL(c, b, a) (((u32)((c)[0] * (b)) >> 8 << 24) | ((((u32)((c)[1] * (b)) >> 8) & 0xFF) << 16) | (((c)[2] * (b)) & 0xFF00) | ((a) & 0xFF))

void func_80016B3C(Obj *obj, Ctx *arg1, MtxF *fp)
{
    MtxF mf;
    u8 col[4];
    s16 v[4][4];
    s32 d[3];
    void *m1 = 0;
    void *m2 = 0;
    Pos *pos;
    s32 flags;
    Q *q;
    s32 alpha;
    u32 bright = 0;
    Ctx *ctx;
    Ctx *gfx;
    Gfx *g;
    Gfx *_g;
    Shd *shd;
    Part *part;
    Part *p;
    Node *s;
    void *m;
    void *m0;
    u8 *bb;
    s32 i;
    u32 j, k;
    s32 type;
    s32 dist;
    s32 t;
    s32 dx, dy, dz;

    q = obj->unk88->unk0;
    if (D_800A0384 != NULL && D_800A0384->unk384 == 0) {
        Node *w0, *w1;
        s32 n;
        for (n = 0; n < 4; n++) {
            Node *w = obj->unk88->wheels[n];
            Ent *e = &obj->unk88->ent[n];
            e->unkE = 0;
            e->unk10 = 0;
            w->unk88 = e;
            w->unk0 = 1;
            w->unk88->unkC -= obj->unk54[n] / 2;
        }
        w0 = obj->unk88->wheels[0];
        w1 = obj->unk88->wheels[1];
        w0->unk88->unkE = obj->unk88->unk70;
        w1->unk88->unkE = obj->unk88->unk70;
    }
    {
        Game *gm = gGame;
        *obj->unk88->unk4 = 1;
        gfx = func_800056FC(gm->unk178);
    }
    arg1->unk78 = 0;
    if (gMode->unk1E == 0 && gMode->unk1A == 1 && obj->unk48->unk0 == 7 && obj->unk48->unk20 == 8) return;
    if (gMode->unk1E == 0 && obj->unk48->unk0 == 7 && gMode->unk18 == 1) return;
    if (gMode->unk1E == 8 && obj->unk48->unk2C == gB7D3B) return;
    if (obj->unk48->unk0 == 5 && gMode->unkE == 2 && (gMode->unk1E == obj->unk48->unk0 || (gMode->unk1E != 0 && gMode->unk1E < 5))) return;

    if (D_8009FF30 != 2 && gB7678 == 0) {
        col[0] = gCol[0];
        col[1] = gCol[1];
        col[2] = gCol[2];
        col[3] = 0x3C;
    } else {
        col[0] = 0xFF;
        col[1] = 0xFF;
        col[2] = 0xFF;
        col[3] = 0x3C;
    }

    if (gMode->unk1E == 0 && gMode->unk1A == 1) {
        type = obj->unk48->unk0;
        if (type != 8) {
            if (type < 4 || type == 8) {
                Pos *a, *b;
                s32 t, dx, dy, dz;
                if (obj != gGame->unk24) return;
                a = obj->unk5C;
                obj = obj->unk4;
                b = obj->unk5C;
                dx = a->unk54 - b->unk54;
                dy = a->unk58 - b->unk58;
                dz = a->unk5C - b->unk5C;
                t = dx * dx + dy * dy + dz * dz;
                obj->unk6C->unk30 = t;
                obj = obj->unk0;
                obj->unk6C->unk30 = t;
            } else {
                if (obj->unk0 != gGame->unk24) return;
            }
        }
    } else if (gMode->unk1E == 5 && gB7FC8 == 0) {
        if (!(obj->unk48->unk0 < 4)) return;
        if (obj != gGame->unk24) return;
    }

    pos = obj->unk5C;
    bb = q->unk8 + 4;
    func_80010BFC(0, fp, pos);
    {
        s32 vis = isBoundingBoxVisible(fp, bb, gGame->unk178);
        obj->unk88->unk80 = vis;
    }
    if ((D_800C7F84->unk24 == obj || obj->unk88->unk80 == 0) && (D_800C7F84->unk20 & 8)) return;
    gfx->unk78 = 0;
    ctx = gfx;
    type = obj->unk48->unk0;
    flags = 0;
    if (type == 7) flags = 1;
    if (D_8009FF30 == 2) flags |= 2;
    if (obj->unk6C->unk30 > 4410000 || obj->unk48->unk0 != 7) {
        alpha = 0xFF;
    } else {
        alpha = (0xFF - (4410000 - obj->unk6C->unk30) * 0xFF) / 4410000;
    }
    {
        s32 n;
        for (n = 1; n < 12; n++) {
        }
    }
    shd = obj->unk88->unk68;
    g = func_80006008(ctx);
    { Gfx *_a = g++; _a->w0 = 0xDE000000; _a->w1 = (u32)D_8009C1A0; }
    { Gfx *_a = g++; _a->w0 = 0xFA000000; _a->w1 = (shd->unk10 << 24) | (shd->unk10 << 16) | (shd->unk10 << 8); }
    { Gfx *_a = g++; _a->w0 = 0xFB000000; _a->w1 = ENVCOL(col, bright, alpha); }
    func_80006014(ctx, g);
    part = obj->unk8C->parts[10];
    func_8002E0B8(&mf, part->unk10);
    m0 = func_8001BD1C();
    if (func_80010BFC(m0, fp, &mf) == 1) {
        u16 n;
        func_800075BC(ctx, shd->unkC->unk4[0], 0);
        func_800061FC(ctx, m0);
        v[0][0] = obj->unk8C->unkB0;
        v[0][1] = obj->unk8C->unkB4;
        v[0][2] = obj->unk8C->unkB8;
        t = obj->unk80->unk208 - 5;
        t -= part->unk28;
        if (v[0][1] < t - 20) v[0][1] = t;
        p = obj->unk8C->parts[11];
        d[0] = p->unk24 - part->unk24;
        d[1] = p->unk28 - part->unk28;
        d[2] = p->unk2C - part->unk2C;
        v[1][0] = obj->unk8C->unkC4 + d[0];
        v[1][1] = obj->unk8C->unkC8 + d[1];
        v[1][2] = obj->unk8C->unkCC + d[2];
        t = obj->unk80->unk1F4 - 5;
        t -= part->unk28;
        if (v[1][1] < t - 20) v[1][1] = t;
        p = obj->unk8C->parts[4];
        d[0] = p->unk24 - part->unk24;
        d[1] = p->unk28 - part->unk28;
        d[2] = p->unk2C - part->unk2C;
        v[2][0] = obj->unk8C->unkD8 + d[0];
        v[2][1] = obj->unk8C->unkDC + d[1];
        v[2][2] = obj->unk8C->unkE0 + d[2];
        t = obj->unk80->unk230 - 5;
        t -= part->unk28;
        if (v[2][1] < t - 20) v[2][1] = t;
        p = obj->unk8C->parts[5];
        d[0] = p->unk24 - part->unk24;
        d[1] = p->unk28 - part->unk28;
        d[2] = p->unk2C - part->unk2C;
        v[3][0] = obj->unk8C->unkEC + d[0];
        v[3][1] = obj->unk8C->unkF0 + d[1];
        v[3][2] = obj->unk8C->unkF4 + d[2];
        t = obj->unk80->unk21C - 5;
        t -= part->unk28;
        if (v[3][1] < t - 20) v[3][1] = t;
        n = func_800070CC(ctx);
        func_800068C0(ctx, n, v[0][0], v[0][1] - 8, v[0][2], v[1][0], v[1][1] - 8, v[1][2],
                      v[3][0], v[3][1] - 8, v[3][2], v[2][0], v[2][1] - 8, v[2][2]);
        func_800071EC(ctx, n, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        func_80008B28(ctx, n, 0, 0, shd->unkC->unk4[0]->unk6, 0, shd->unkC->unk4[0]->unk6,
                      shd->unkC->unk4[0]->unk8, 0, shd->unkC->unk4[0]->unk8);
    }

    if (obj == gGame->unk24 || D_8009FF30 != 2 || gB7678 != 0) {
        bright = 0;
        for (i = 0; i < 12; i++) {
            s32 t;
            part = obj->unk8C->parts[i];
            t = obj->unk60[i] * (part->unk8A - 1);
            t += obj->unk60[i + 12];
            bright += part->unk6C[t];
        }
        bright /= 12;
        bright -= 80;
        bright = bright * 255 / 100;
        if (bright >= 0x100) bright = 0xFF;
    } else {
        if (func_8007BA1C(obj) == 0xFF) {
            flags &= ~2;
            bright = 0xC4;
        } else {
            bright = 0xFF;
        }
    }
    if (obj->unk48->unk0 == 7) gfx = arg1;
    func_80016910(gfx, flags);
    g = func_80006008(gfx);
    { Gfx *_a = g++; _a->w0 = 0xFB000000; _a->w1 = ENVCOL(col, bright, alpha); }
    for (i = 0; i < 5; i++) {
        s = q->unk10[i];
        if (s->unk88 != NULL) {
            if (s->unk0 != 0) {
                func_8002DF40(&s->unk88->unkC, s->unk8);
                s->unk38 = s->unk88->x;
                s->unk3C = s->unk88->y;
                s->unk40 = s->unk88->z;
                s->unk0 = 0;
            }
            if (s->unk4 != NULL) {
                func_8001C2C0(&s->unk4->unk48, s->unk8, &s->unk48);
            }
            m = func_8001BD1C();
            func_80010BFC(m, fp, &s->unk48);
        } else {
            m = func_8001BD1C();
            if ((gMode->unk2C & 2) && gMode->unk1E == 0) {
                m1 = func_8001BD1C();
                m2 = func_8001BD1C();
                *(Blk40 *)&s->unk48 = *(Blk40 *)pos;
                s->unk48.m[3][1] -= 120.0f;
                func_80010BFC(m1, fp, &s->unk48);
                s->unk48.m[3][1] -= 120.0f;
                func_80010BFC(m2, fp, &s->unk48);
            }
            *(Blk40 *)&s->unk48 = *(Blk40 *)pos;
            func_80010BFC(m, fp, pos);
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                    (*(MtxF *)(D_800AE850 + 0x72B0)).m[j][k] = fp[2].m[j][k];
                }
            }
        }
        if (gGame->unk24 != obj || !(gGame->unk20 & 8)) {
            { Gfx *_a = g++; _a->w0 = 0xDA380007; _a->w1 = osVirtualToPhysical(m); }
            func_80006014(gfx, g);
            func_80005F14(gfx, q->unk10[i]->unk90);
            g = func_80006008(gfx);
            if (i == 0) {
                func_80006014(gfx, g);
                if ((gMode->unk2C & 2) && gMode->unk1E == 0) {
                    { Gfx *_a = gfx->dl++; _a->w0 = 0xDE000000; _a->w1 = (u32)D_8009C0A8; }
                    { Gfx *_a = gfx->dl++; _a->w0 = 0xFB000000; _a->w1 = 0xFFFFFF20; }
                    { Gfx *_a = gfx->dl++; _a->w0 = 0xDA380007; _a->w1 = osVirtualToPhysical(m1); }
                    func_80005F14(gfx, q->unk10[0]->unk90);
                    { Gfx *_a = gfx->dl++; _a->w0 = 0xDA380007; _a->w1 = osVirtualToPhysical(m2); }
                    func_80005F14(gfx, q->unk10[0]->unk90);
                }
                func_800061FC(arg1, m);
                func_80051D10(arg1, obj, fp, alpha);
                func_800169DC(gfx, flags);
                g = func_80006008(gfx);
                { Gfx *_a = g++; _a->w0 = 0xFB000000; _a->w1 = ENVCOL(col, bright, alpha); }
            }
        }
    }
    _g = g++; _g->w0 = 0xFB000000; _g->w1 = ((u8)gCol[0] << 24) | ((u8)gCol[1] << 16) | ((u8)gCol[2] << 8) | 0xFF;
    func_80006014(gfx, g);
    gfx = func_800056FC(gGame->unk178);
    _g = gfx->dl++; _g->w0 = 0xFB000000; _g->w1 = ((u8)gCol[0] << 24) | ((u8)gCol[1] << 16) | ((u8)gCol[2] << 8) | 0xFF;
}
