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

M2C_UNK slotSetSelected(s32, s32);                    /* extern */
s32 select_stream_char(u8, u8, u8);                      /* extern */
extern void *gSelectState;
extern M2C_UNK stream_state;

/* Steps the selected stream slot back by one: if its count byte is nonzero, decrements it and marks slot_id as selected. */ s32 stream_slot_select_prev(s32 slot_id) {
    u8 count;
    u8 count_prev;
    void *slot_base;
    void *slot;

    slot_base = M2C_FIELD(&stream_state, void **, 0x32F2) + ((M2C_FIELD((M2C_FIELD(&stream_state, void **, 0x32F2) + M2C_FIELD(gSelectState, s8 *, 0x228)), u8 *, 0x32) * 0x28) + 0x44);
    slot = slot_base + (select_stream_char(M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u8 *, 0x1F), M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u8 *, 0x21), M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u8 *, 0x23)) & 0xFF);
    count = M2C_FIELD(slot, u8 *, 0x10);
    if (count != 0) {
        count_prev = count - 1;
        M2C_FIELD(slot, u8 *, 0x10) = count_prev;
        slotSetSelected(slot_id, count_prev & 0xFF);
    }
    return 1;
}
