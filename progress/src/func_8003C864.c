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

/* Clears flag bit 0x4 on obj, then sets it again when the linked sub-record has bit 0x100 set in its status word at +0x14. */ void func_8003C864(void *obj) {
    s32 flags;
    void *link;

    flags = M2C_FIELD(obj, s32 *, 0x80) & ~4;
    M2C_FIELD(obj, s32 *, 0x80) = flags;
    link = M2C_FIELD(M2C_FIELD(obj, void **, 0xA8), void **, 0x24);
    if ((link != NULL) && (M2C_FIELD(link, s32 *, 0x14) & 0x100)) {
        M2C_FIELD(obj, s32 *, 0x80) = (s32) (flags | 4);
    }
}
