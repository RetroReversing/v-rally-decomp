s32 alFilterNew(void *a0, void *fn2, void *fn3, s32 n4);
s32 alHeapDBAlloc(s32, s32, s32, s32, s32);
extern void *alEnvmixerPull;
extern void *alEnvmixerParam;

/* Sets up an envmixer unit: registers the pull and param handlers, allocates
 * nVoices voice records of 0x50 bytes at +0x14, and resets the unit's state
 * fields to their idle values. */
void alEnvmixerNew(void *envmix, s32 nVoices) {
    alFilterNew(envmix, &alEnvmixerPull, &alEnvmixerParam, 4);
    *(s32 *)((s8 *)envmix + 0x14) = alHeapDBAlloc(0, 0, nVoices, 1, 0x50);
    *(s32 *)((s8 *)envmix + 0x38) = 1;
    *(s32 *)((s8 *)envmix + 0x48) = 0;
    *(s16 *)((s8 *)envmix + 0x1A) = 1;
    *(s16 *)((s8 *)envmix + 0x28) = 1;
    *(s16 *)((s8 *)envmix + 0x2E) = 1;
    *(s16 *)((s8 *)envmix + 0x1C) = 1;
    *(s16 *)((s8 *)envmix + 0x1E) = 1;
    *(s16 *)((s8 *)envmix + 0x20) = 0;
    *(s16 *)((s8 *)envmix + 0x22) = 0;
    *(s16 *)((s8 *)envmix + 0x26) = 1;
    *(s16 *)((s8 *)envmix + 0x24) = 0;
    *(s16 *)((s8 *)envmix + 0x26) = 1;
    *(s16 *)((s8 *)envmix + 0x24) = 0;
    *(s32 *)((s8 *)envmix + 0x30) = 0;
    *(s32 *)((s8 *)envmix + 0x34) = 0;
    *(s16 *)((s8 *)envmix + 0x18) = 0;
    *(s32 *)((s8 *)envmix + 0x3C) = 0;
    *(s32 *)((s8 *)envmix + 0x40) = 0;
    *(s32 *)((s8 *)envmix + 0x44) = 0;
}
