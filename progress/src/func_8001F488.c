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

extern char gOrderState[];

/* Copies two fields from src (+0x90 and +0xDC) into gOrderState+0x18B4..0x18B6 and marks the second byte as 0xFF. */
void func_8001F488(char *src) {
    *(u8 *)(gOrderState + 0x18B4) = *(s32 *)(src + 0x90);
    {
        s32 v = *(s32 *)(src + 0xDC);

        *(u8 *)(gOrderState + 0x18B6) = 0xFF;
        *(u8 *)(gOrderState + 0x18B5) = v;
    }
}
