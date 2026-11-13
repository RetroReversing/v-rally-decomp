/* Per-voice effect parameter slot. Written by alFxParamHdl; field meanings are partly open. */
typedef struct AlFxParam {
    s32 start;      /* 0x00: masked address, low 3 bits cleared */
    s32 end;        /* 0x04: masked address, low 3 bits cleared */
    s16 v8, vA, vC, vE;
    f32 rate;       /* 0x10 */
    s32 p14, p18;
    f32 decay;      /* 0x1C: per-sample decay step */
    void *buf;      /* 0x20: s16 buffer, filled by alFxFillDecay */
    s32 p24;
} AlFxParam;

/* Effect bank: parameter table lives at +0x20. */
typedef struct AlFxBank {
    u8 pad00[0x20];
    AlFxParam *params;
} AlFxBank;

extern u8 *D_800A2500;
extern f64 D_800A71F0;
extern f64 D_800A71F8;

void alFxFillDecay(void *);

/* Writes one field of effect parameter slot (id - 2): id picks the slot
 * (8 fields per slot), and the field index picks what is stored. */
s32 alFxParamHdl(AlFxBank *bank, s32 id, s32 *src) {
    s32 n = id - 2;
    s32 field = n % 8;
    s32 val;

    id = n / 8;
    val = *src;
    switch (field) {
    case 0:
        bank->params[id].start = val & ~7;
        break;
    case 1:
        bank->params[id].end = val & ~7;
        break;
    case 3:
        bank->params[id].v8 = val;
        break;
    case 2:
        bank->params[id].vA = val;
        break;
    case 4:
        bank->params[id].vC = val;
        break;
    case 5:
        bank->params[id].rate = (f32)((f64)((f32)val / 1000.0f) * 2.0 / (f64)*(s32 *)(D_800A2500 + 0x44));
        break;
    case 6: {
        f64 t = (f64)(f32)val / D_800A71F0;
        s32 diff = bank->params[id].end - bank->params[id].start;
        f64 d = (f64)diff;
        if (diff < 0) {
            d += D_800A71F8;
        }
        bank->params[id].decay = (f32)(t * d);
        break;
    }
    case 7:
        if (bank->params[id].buf != NULL) {
            *(s16 *)bank->params[id].buf = val;
            alFxFillDecay(bank->params[id].buf);
        }
        break;
    }
    return 0;
}
