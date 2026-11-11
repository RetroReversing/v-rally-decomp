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

s16 lerp_q7();

/* Steps 12 fade entries: an entry whose countdown (+0xC) is still running
   just counts down; once it reaches zero its level (+0x24) moves toward
   target by a 40/128 fraction of the remaining distance. */
void func_800735D0(void *base, s32 target) {
    u16 countdown;
    u32 i;
    void *entry;

    i = 0;
    entry = base;
loop_1:
    countdown = *(u16 *)((char *)entry + 0xC);
    if (countdown == 0) {
        goto block_3;
    }
    *(u16 *)((char *)entry + 0xC) = (u16) (countdown - 1);
    goto block_4;
block_3:
    *(s16 *)((char *)entry + 0x24) = lerp_q7(*(s16 *)((char *)entry + 0x24), target, 0x28);
block_4:
    i += 1;
    entry += 2;
    if (i < 0xCU) {
        goto loop_1;
    }
    return;
}
