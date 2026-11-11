#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

void *__allocParam();

/* Stops a voice by queuing a stop event: if the voice has a handler, allocates a parameter block, fills it with event type 0xF and the synth time plus the handler's offset, then sends it to the handler's owner as message 3. */
void alSynStopVoice(void *synth, void *voice) {
    s32 (*fn)(void *, s32, void *);
    s32 time;
    void *evt;
    void *owner;

    fn = M2C_FIELD(voice, s32 (**)(void *, s32, void *), 8);
    if (fn != NULL) {
        evt = __allocParam();
        if (evt != NULL) {
            fn = M2C_FIELD(voice, s32 (**)(void *, s32, void *), 8);
            time = *(s32 *)((char *)synth + 0x1C);
            owner = *(void * *)((char *)fn + 0xD8);
            fn = (s32 (*)(void *, s32, void *))0xF;
            *(s16 *)((char *)evt + 8) = 0xF;
            *(s32 *)((char *)evt + 0) = 0;
            time += owner;
            *(s32 *)((char *)evt + 4) = time;
            fn = M2C_FIELD(voice, s32 (**)(void *, s32, void *), 8);
            owner = *(void * *)((char *)fn + 0xC);
            fn = M2C_FIELD(owner, s32 (**)(void *, s32, void *), 8);
            fn(owner, 3, evt);
        }
    }
}
