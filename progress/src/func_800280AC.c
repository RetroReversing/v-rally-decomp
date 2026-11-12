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

M2C_UNK seq_record_store_u32(s32, M2C_UNK);                /* extern */
M2C_UNK func_80027CFC(M2C_UNK);                     /* extern */
s32 seq_next_entry(s32);                             /* extern */
extern s32 gCarEntryTable;

/* Stores value into the next car entry slot, then passes value on to func_80027CFC. */ void func_800280AC(s32 arg0, M2C_UNK value) {
    seq_record_store_u32(seq_next_entry(gCarEntryTable), value);
    func_80027CFC(value);
}
