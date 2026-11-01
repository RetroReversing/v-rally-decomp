#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    u32 w0;
    u32 w1;
} Awords;
typedef union {
    Awords words;
    s64 force_union_align;
} Acmd;
typedef struct ALFilter_s {
    struct ALFilter_s *source;
    Acmd *(*handler)(void *, s16 *, s32, s32, Acmd *);
    void *setParam;
    s16 inp;
    s16 outp;
    s32 type;
} ALFilter;
typedef struct {
    ALFilter filter;
    void *state;
    s16 pan;
    s16 volume;
    s16 cvolL;
    s16 cvolR;
    s16 dryamt;
    s16 wetamt;
    u16 lratl;
    s16 lratm;
    s16 ltgt;
    u16 rratl;
    s16 rratm;
    s16 rtgt;
    s32 delta;
    s32 segEnd;
    s32 first;
    void *ctrlList;
    void *ctrlTail;
    void *sources;
    s32 motion;
} ALEnvMixer;
extern s32 osVirtualToPhysical(void *);
extern void func_800914E0(void *, void *, s32);
extern s16 _getRate(f64, f64, s32, u16 *);
extern s16 D_800A38A0[];
extern u8 D_800A7070[];
extern u8 D_800A7074[];

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define aSetBuffer(pkt, f, i, o, c) \
    { \
        Acmd *_a = (Acmd *)pkt; \
        _a->words.w0 = (_SHIFTL(8, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16)); \
        _a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); \
    }
#define aSetVolume(pkt, f, v, t, r) \
    { \
        Acmd *_a = (Acmd *)pkt; \
        _a->words.w0 = (_SHIFTL(9, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(v, 0, 16)); \
        _a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16); \
    }
#define aEnvMixer(pkt, f, s) \
    { \
        Acmd *_a = (Acmd *)pkt; \
        _a->words.w0 = (_SHIFTL(3, 24, 8) | _SHIFTL(f, 16, 8)); \
        _a->words.w1 = (u32)(s); \
    }

Acmd *func_80092BD0(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    ALEnvMixer *e = (ALEnvMixer *)filter;
    ALFilter *source = e->filter.source;

    if (e->motion != 1 || !outCount) {
        return ptr;
    }
    if (!source) {
        func_800914E0(D_800A7070, D_800A7074, 0x16F);
    }
    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, 0, *inp, *outp + 0x440, outCount << 1);
    aSetBuffer(ptr++, 8, *outp + 0x580, *outp + 0x6C0, *outp + 0x800);

    if (e->first) {
        e->first = 0;
        e->ltgt = (e->volume * D_800A38A0[e->pan]) >> 15; e->lratm = _getRate((f64)e->cvolL, (f64)e->ltgt, e->segEnd, &e->lratl);
        e->rtgt = (e->volume * D_800A38A0[128 - e->pan - 1]) >> 15; e->rratm = _getRate((f64)e->cvolR, (f64)e->rtgt, e->segEnd, &e->rratl);
        aSetVolume(ptr++, 6, e->cvolL, 0, 0);
        aSetVolume(ptr++, 4, e->cvolR, 0, 0);
        aSetVolume(ptr++, 2, e->ltgt, e->lratm, e->lratl);
        aSetVolume(ptr++, 0, e->rtgt, e->rratm, e->rratl);
        aSetVolume(ptr++, 8, e->dryamt, 0, e->wetamt);
        aEnvMixer(ptr++, 9, osVirtualToPhysical(e->state));
    } else {
        aEnvMixer(ptr++, 8, osVirtualToPhysical(e->state));
    }
    *inp += outCount << 1;
    e->delta += outCount;
    return ptr;
}

