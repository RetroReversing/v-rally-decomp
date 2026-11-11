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

M2C_UNK stream_obj_free(s32);                         /* extern */
void *named_entry_lookup(void **, u8 *);                /* extern */
M2C_UNK func_800225BC(void **);                     /* extern */
M2C_UNK list_unlink_free(void *, s32);                 /* extern */
extern M2C_UNK D_800A4E20;

/* Looks up the entry named D_800A4E20 in the list at arg0+0x28. If it exists,
 * releases its owner's block (stream_obj_free), calls func_800225BC on the owner
 * and unlinks and frees the entry. */
void func_800447A0(s32 arg0) {
    s32 list;
    void *entry;

    list = arg0 + 0x28;
    entry = named_entry_lookup((void **)(list), (u8 *)(&D_800A4E20));
    if (entry != NULL) {
        stream_obj_free(*(s32 *)((u8 *)**(void ***)((u8 *)entry + 0x10) + 0x10));
        func_800225BC(*(void ***)((u8 *)entry + 0x10));
        list_unlink_free(entry, list);
    }
}
