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

void osWritebackDCache(u32 arg0, s32 arg1) {
    u32 temp_t1;
    u32 var_t0;
    u32 var_t0_2;

    if (arg1 > 0) {
        if ((u32) arg1 < 0x2000U) {
            temp_t1 = arg0 + arg1;
            if (arg0 < temp_t1) {
                var_t0 = arg0 - (arg0 & 0xF);
                do {
                    M2C_ERROR(/* unknown instruction: cache 0x19, ($t0) */);
                    var_t0 += 0x10;
                } while (var_t0 < (u32) (temp_t1 - 0x10));
            }
        } else {
            var_t0_2 = 0x80000000;
            do {
                M2C_ERROR(/* unknown instruction: cache 0x1, ($t0) */);
                var_t0_2 += 0x10;
            } while (var_t0_2 < 0x80001FF0U);
        }
    }
}
