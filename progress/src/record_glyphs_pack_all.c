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

M2C_UNK func_8006ECB4();                            /* extern */
M2C_UNK glyph_record_pack(s32);                         /* extern */

/* Packs the record glyph for each of the four slots, then calls func_8006ECB4 to finish. */ void record_glyphs_pack_all(void) {
    s32 slot;

    slot = 0;
    do {
        glyph_record_pack(slot & 0xFF);
        slot += 1;
    } while ((u32) (slot & 0xFF) < 4U);
    func_8006ECB4();
}
