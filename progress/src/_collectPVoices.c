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

s32 al_link_push();
s32 alUnlink();

/* Moves every voice on the list at +0x14 of the audio block onto the list at +0x4 (alUnlink then al_link_push). */
void _collectPVoices(void *block) {
    s32 voice;
    void *blk;

    blk = block;
    voice = *(s32 *)((char *)blk + 0x14);
    if (voice != 0) {
        do {
            alUnlink(voice);
            al_link_push(voice, blk + 4);
            voice = *(s32 *)((char *)blk + 0x14);
        } while (voice != 0);
    }
}
