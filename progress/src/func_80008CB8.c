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

/* Sets the three parameter bytes of entry `index` in the table at obj+0x70 and clears
 * the entry's pending flag (bit 0 of its flags word at +6), if that flag was set. */
void func_80008CB8(void *obj, s32 index, s8 param0, s8 param1, u8 param2) {
    s32 offset;
    u16 flags;
    void *entry;

    offset = (index & 0xFFFF) * 0x10;
    entry = offset + M2C_FIELD(obj, s32 *, 0x70);
    flags = M2C_FIELD(entry, u16 *, 6);
    if (flags & 1) {
        M2C_FIELD(entry, u16 *, 6) = (u16) (flags & 0xFFFE);
        M2C_FIELD((offset + M2C_FIELD(obj, s32 *, 0x70)), s8 *, 0xC) = param0;
        M2C_FIELD((offset + M2C_FIELD(obj, s32 *, 0x70)), s8 *, 0xD) = param1;
        M2C_FIELD((offset + M2C_FIELD(obj, s32 *, 0x70)), u8 *, 0xE) = param2;
    }
}
