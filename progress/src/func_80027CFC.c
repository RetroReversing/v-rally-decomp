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

/* Updates the 4-byte flag record at bytes: bytes[2] becomes (bytes[2] | ~bytes[1] | 0x90),
   and bytes[3] becomes bytes[1] & that new value. */
void func_80027CFC(unsigned char *bytes) {
    unsigned int x = bytes[1];
    unsigned int y = bytes[2];
    unsigned int v = (y | (~x)) | 0x90;
    unsigned int w = bytes[1] & v;

    bytes[2] = v;
    bytes[3] = bytes[1] & v;
}
