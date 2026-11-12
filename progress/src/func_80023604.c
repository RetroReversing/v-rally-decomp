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

extern char gOrderState[];

/* Walks the list whose head pointer is at gOrderState+0x73F0 (next pointer at +4) to its last node. */
void func_80023604(void) {
    void *node = **(void ***)(gOrderState + 0x73F0);

    if (node != NULL) {
        do {
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
}
