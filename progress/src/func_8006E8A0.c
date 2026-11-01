typedef struct {
    u16 f15 : 1;
    u16 f14 : 1;
    u16 f13 : 1;
    u16 pad : 3;
    u16 f8 : 2;
    u16 f4 : 4;
    u16 f0 : 4;
    u16 g12 : 4;
    u16 g8 : 4;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    s16 sums[4];
    u8 pad12[0x1BA - 0x12];
    s8 code;
} Packet;
typedef struct {
    u8 pad0[0xA];
    union {
        u16 w;
        u8 b[2];
    } v;
    u8 pad0C[0x28 - 0xC];
} Entry;
typedef struct {
    u8 pad0[0xE];
    u16 mode;
    u8 pad10[0x32 - 0x10];
    u8 sel0;
    u8 sel1;
    u8 sel2;
    u8 sel3;
    u8 pad36[0x44 - 0x36];
    Entry e[1];
} Game;
typedef struct { u8 a; u8 b; u8 c; } Flags3;
extern Packet D_800C7112;
extern Game *D_800C35A0;
extern Flags3 D_800B6818;
extern u16 D_800B6610[];
extern u8 D_800B6628[][4];
extern s32 D_800B6768;
extern s32 D_800B676C;

void func_8006E8A0(void)
{
    Packet *p;
    u8 n;
    u8 base;
    u8 i;
    u8 j;
    s8 bits;
    s16 sum;

    if (D_800B6818.b != 0)
    {
        n = 4;
        base = 8;
    }
    else
    {
        n = 8;
        base = 0;
    }
    p = &D_800C7112;
    p->f14 = D_800B6818.c;
    p->f13 = D_800B6818.a;
    p->f15 = D_800B6818.b;
    p->f8 = D_800C35A0->mode;
    p->f4 = D_800C35A0->sel0;
    D_800C7112.code = D_800C35A0->e[D_800C35A0->sel0].v.b[1] & 0xF;
    if (D_800C35A0->mode == 2)
    {
        p->f0 = D_800C35A0->sel1;
        D_800C7112.code += (D_800C35A0->e[D_800C35A0->sel1].v.b[1] & 0xF) << 4;
    }
    else
    {
        p->f0 = D_800C35A0->e[D_800C35A0->sel1].v.w;
    }
    p->g12 = D_800C35A0->e[D_800C35A0->sel2].v.w & 0xF;
    p->g8 = D_800C35A0->e[D_800C35A0->sel3].v.w;
    bits = 0;
    for (i = 0; i < n; i++)
    {
        if (D_800B6610[base + i] == 1)
        {
            bits |= 1 << i;
        }
    }
    p->b9 = bits;
    for (j = 0; j < 4; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += D_800B6628[base + i][j] << (i * 2);
        }
        p->sums[j] = sum;
    }
    {
        s32 t = D_800B6768;
        p->b3 = t;
        p->b5 = t >> 16;
        p->b4 = t >> 8;
        t = D_800B676C;
        p->b8 = t >> 16;
        p->b7 = t >> 8;
        p->b6 = t;
    }
}
