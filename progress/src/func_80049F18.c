typedef struct {
    u8 data[5][0x2A];
    s16 vals[5];
    u8 count;
    u8 pad;
} Rec;
typedef struct {
    u8 pad0[4];
    u8 obj[6];
    Rec recs[4];
    u8 pad1[0x3A4 - 0x382];
    f32 x3A4;
} Mgr;
extern Mgr *gRaceCtx;
void memset(void *, s32, s32);
void strCpy(void *, void *);
s32 font_text_width(void *, void *, u8, f32, u8);

/* Clears the value slots of the four records, then fills each of the `count` entries of every
 * record: decodes the entry into a scratch buffer and stores font_text_width's result in vals. */
void func_80049F18(void)
{
    u8 scratch[0x2A];
    u8 i;
    u8 j;
    Mgr *m;
    s16 v;

    memset(scratch, 0, 0x2A);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            gRaceCtx->recs[i].vals[j] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < gRaceCtx->recs[i].count; j++) {
            strCpy(scratch, gRaceCtx->recs[i].data[j]);
            gRaceCtx->recs[i].vals[j] = font_text_width((void *)(gRaceCtx->pad0 + 4), (void *)(scratch), (u8)(1), (f32)(gRaceCtx->x3A4), (u8)(0));
        }
    }
}
