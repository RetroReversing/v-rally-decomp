typedef struct {
    u16 flagB : 1;
    u16 flagC : 1;
    u16 flagA : 1;
    u16 pad : 3;
    u16 mode : 2;
    u16 sel0 : 4;
    u16 sel1 : 4;
    u16 sel2 : 4;
    u16 sel3 : 4;
    u8 countA[3];
    u8 countB[3];
    u8 activeBits;
    s16 sums[4];
    u8 pad12[0x1BA - 0x12];
    s8 code;
} LinkPacket;

typedef struct {
    u8 pad0[0xA];
    union {
        u16 w;
        u8 b[2];
    } v;
    u8 pad0C[0x28 - 0xC];
} RecordEntry;

typedef struct {
    u8 pad0[0xE];
    u16 mode;
    u8 pad10[0x32 - 0x10];
    u8 sel0;
    u8 sel1;
    u8 sel2;
    u8 sel3;
    u8 pad36[0x44 - 0x36];
    RecordEntry e[1];
} GameRecords;

typedef struct { u8 a; u8 b; u8 c; } LinkFlags;

extern LinkPacket D_800C7112;
extern GameRecords *gRecords;
extern LinkFlags D_800B6818;
extern u16 D_800B6610[];
extern u8 D_800B6628[][4];
extern s32 D_800B6768;
extern s32 D_800B676C;

/* Fills gLinkPacket from the link flags, the selected records and the per-slot tables. */
void buildLinkPacket(void)
{
    LinkPacket *pkt;
    u8 slotCount;
    u8 slotBase;
    u8 i;
    u8 j;
    s8 bits;
    s16 sum;

    if (D_800B6818.b != 0)
    {
        slotCount = 4;
        slotBase = 8;
    }
    else
    {
        slotCount = 8;
        slotBase = 0;
    }
    pkt = &D_800C7112;
    pkt->flagC = D_800B6818.c;
    pkt->flagA = D_800B6818.a;
    pkt->flagB = D_800B6818.b;
    pkt->mode = gRecords->mode;
    pkt->sel0 = gRecords->sel0;
    D_800C7112.code = gRecords->e[gRecords->sel0].v.b[1] & 0xF;
    if (gRecords->mode == 2)
    {
        pkt->sel1 = gRecords->sel1;
        D_800C7112.code += (gRecords->e[gRecords->sel1].v.b[1] & 0xF) << 4;
    }
    else
    {
        pkt->sel1 = gRecords->e[gRecords->sel1].v.w;
    }
    pkt->sel2 = gRecords->e[gRecords->sel2].v.w & 0xF;
    pkt->sel3 = gRecords->e[gRecords->sel3].v.w;
    bits = 0;
    for (i = 0; i < slotCount; i++)
    {
        if (D_800B6610[slotBase + i] == 1)
        {
            bits |= 1 << i;
        }
    }
    pkt->activeBits = bits;
    for (j = 0; j < 4; j++)
    {
        sum = 0;
        for (i = 0; i < slotCount; i++)
        {
            sum += D_800B6628[slotBase + i][j] << (i * 2);
        }
        pkt->sums[j] = sum;
    }
    {
        s32 t = D_800B6768;
        pkt->countA[0] = t;
        pkt->countA[2] = t >> 16;
        pkt->countA[1] = t >> 8;
        t = D_800B676C;
        pkt->countB[2] = t >> 16;
        pkt->countB[1] = t >> 8;
        pkt->countB[0] = t;
    }
}
