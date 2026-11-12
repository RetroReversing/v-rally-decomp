/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 osDisableInt();                                /* extern */
M2C_UNK osRestoreInt(s32);                         /* extern */
extern void *viCurrent;

/* Points the current VI context at a new framebuffer and sets flag 0x10 in its control word, with interrupts masked meanwhile. */ void viSetSwapBuffer(s32 framebuffer) {
    s32 int_state;

    int_state = osDisableInt();
    M2C_FIELD(viCurrent, s32 *, 4) = framebuffer;
    M2C_FIELD(viCurrent, u16 *, 0) = (u16) (M2C_FIELD(viCurrent, u16 *, 0) | 0x10);
    osRestoreInt(int_state);
}
