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

/* Packs three 5-bit values into the first word of the command block at ctx+0x14 (opcode 0x05 in the top byte) and zeroes the second word. */ s32 cmd_pack_triple(void *ctx, s32 field_a, s32 field_b, s32 field_c) {
    void *cmd;

    cmd = M2C_FIELD(ctx, void **, 0x14);
    M2C_FIELD(cmd, s32 *, 0) = (s32) (((field_a & 0x1F) << 0x11) | ((field_b & 0x1F) << 9) | ((field_c & 0x1F) * 2) | 0x05000000);
    M2C_FIELD(cmd, s32 *, 4) = 0;
    return 1;
}
