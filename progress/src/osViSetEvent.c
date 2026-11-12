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

/* Stores the retrace message and count into the VI state block, with interrupts off. */
s32 osDisableInt();                                /* extern */
M2C_UNK osRestoreInt(s32);                         /* extern */
extern void *viCurrent;

void osViSetEvent(s32 mq, s32 msg, s16 retraceCount) {
    s32 saved;

    saved = osDisableInt();
    M2C_FIELD(viCurrent, s32 *, 0x10) = mq;
    M2C_FIELD(viCurrent, s32 *, 0x14) = msg;
    M2C_FIELD(viCurrent, s16 *, 2) = retraceCount;
    osRestoreInt(saved);
}
