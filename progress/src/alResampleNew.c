s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
s32 alHeapDBAlloc(s32, s32, s32, s32, s32);
extern void *alResamplePull;
extern void *alResampleParam;

/* Initialises a resample object: sets up the base filter fields (pull function,
 * parameter block, count), allocates the sample buffer from the heap, and clears
 * the state fields. The gain at +0x18 starts at 1.0. */
void alResampleNew(void *resample, s32 count) {
    func_80093790(resample, &alResamplePull, &alResampleParam, 1);
    *(s32 *)((s8 *)resample + 0x14) = alHeapDBAlloc(0, 0, count, 1, 0x20);
    *(s32 *)((s8 *)resample + 0x20) = 0;
    *(s32 *)((s8 *)resample + 0x24) = 1;
    *(s32 *)((s8 *)resample + 0x30) = 0;
    *(s32 *)((s8 *)resample + 0x1C) = 0;
    *(s32 *)((s8 *)resample + 0x28) = 0;
    *(s32 *)((s8 *)resample + 0x2C) = 0;
    *(f32 *)((s8 *)resample + 0x18) = 1.0f;
}
