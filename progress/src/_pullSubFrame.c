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

/* Audio update step for one envelope mixer: emits the F3DEX-audio commands that
 * copy the frame's samples to the output buffers. On the first frame it also
 * ramps both channel volumes towards their targets. Advances *inp and the
 * sample counter by outCount samples, and returns the next command slot. */
Acmd *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *cmdList)
{
    Acmd *cmd = cmdList;
    ALEnvMixer *env = (ALEnvMixer *)filter;
    ALFilter *source = env->filter.source;

    if (env->motion != 1 || !outCount) {
        return cmd;
    }
    if (!source) {
        func_800914E0(D_800A7070, D_800A7074, 0x16F);
    }
    cmd = (*source->handler)(source, inp, outCount, sampleOffset, cmdList);

    aSetBuffer(cmd++, 0, *inp, *outp + 0x440, outCount << 1);
    aSetBuffer(cmd++, 8, *outp + 0x580, *outp + 0x6C0, *outp + 0x800);

    if (env->first) {
        env->first = 0;
        env->ltgt = (env->volume * D_800A38A0[env->pan]) >> 15; env->lratm = _getRate((f64)env->cvolL, (f64)env->ltgt, env->segEnd, &env->lratl);
        env->rtgt = (env->volume * D_800A38A0[128 - env->pan - 1]) >> 15; env->rratm = _getRate((f64)env->cvolR, (f64)env->rtgt, env->segEnd, &env->rratl);
        aSetVolume(cmd++, 6, env->cvolL, 0, 0);
        aSetVolume(cmd++, 4, env->cvolR, 0, 0);
        aSetVolume(cmd++, 2, env->ltgt, env->lratm, env->lratl);
        aSetVolume(cmd++, 0, env->rtgt, env->rratm, env->rratl);
        aSetVolume(cmd++, 8, env->dryamt, 0, env->wetamt);
        aEnvMixer(cmd++, 9, osVirtualToPhysical(env->state));
    } else {
        aEnvMixer(cmd++, 8, osVirtualToPhysical(env->state));
    }
    *inp += outCount << 1;
    env->delta += outCount;
    return cmd;
}
