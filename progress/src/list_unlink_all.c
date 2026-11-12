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

M2C_UNK list_unlink_free(s32, void *);                 /* extern */

/* Frees every node still linked into the list whose head is list (the head node's first link is at offset 4). */ void list_unlink_all(void *list) {
    if (M2C_FIELD(list, s32 *, 4) != 0) {
        do {
            list_unlink_free(M2C_FIELD(list, s32 *, 4), list);
        } while (M2C_FIELD(list, s32 *, 4) != 0);
    }
}
