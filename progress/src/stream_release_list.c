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

M2C_UNK streamReleaseEntry(s32);                         /* extern */

/* Walks the linked list of stream entries from list_head and releases each one. */ void stream_release_list(void **list_head) {
    void *entry;

    if (list_head != NULL) {
        entry = *list_head;
        if (entry != NULL) {
            do {
                streamReleaseEntry(M2C_FIELD(entry, s32 *, 0xC));
                entry = M2C_FIELD(entry, void **, 4);
            } while (entry != NULL);
        }
    }
}
