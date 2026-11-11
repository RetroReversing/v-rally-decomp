/* Allocates the effect at `index` in the synth's FX table (records of 0x4C bytes, effect at +0x20),
 * initialises it, and returns it. */
s32 alFxNew(s32, s32, s32);
s32 func_80094580(s32, s32, s32);
s32 func_80094F90(s32, s32, s32);

s32 alSynAllocFX(u8 *synth, s16 index, s32 arg2, s32 arg3) {
    s32 fx_rec;
    s32 rec_off;

    rec_off = index * 0x4C;
    alFxNew(*(s32 *)(synth + 0x34) + rec_off + 0x20, arg2, arg3);
    fx_rec = *(s32 *)(synth + 0x34) + rec_off;
    func_80094F90(fx_rec + 0x20, 1, fx_rec);
    func_80094580(*(s32 *)(synth + 0x30), 2, *(s32 *)(synth + 0x34) + rec_off + 0x20);
    return *(s32 *)(synth + 0x34) + rec_off + 0x20;
}
