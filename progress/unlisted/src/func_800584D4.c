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

s32 list_remove_at(s32 index, void **listHead);
extern void *gSelectState;
extern M2C_UNK gStreamState;

/* Drops the pending entries queued in the select state (count at +0x232) from the front of the stream list, then clears the count and sets the flag at +0x235. */
void func_800584D4(void) {
    s32 i;

    i = 0;
    if (M2C_FIELD(gSelectState, u8 *, 0x232) != 0) {
        do {
            list_remove_at(0, M2C_FIELD(&gStreamState, s32 *, 0x7672));
            i += 1;
        } while ((u32) (i & 0xFF) < (u8) M2C_FIELD(gSelectState, u8 *, 0x232));
    }
    M2C_FIELD(gSelectState, u8 *, 0x232) = 0U;
    M2C_FIELD(gSelectState, s8 *, 0x235) = 1;
}
