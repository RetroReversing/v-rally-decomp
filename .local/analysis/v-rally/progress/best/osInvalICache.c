/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O1 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

void osInvalICache(u32 arg0, s32 arg1) {
    u32 temp_t1;
    u32 var_t0;
    u32 var_t0_2;

    if (arg1 > 0) {
        if ((u32) arg1 < 0x4000U) {
            temp_t1 = arg0 + arg1;
            if (arg0 < temp_t1) {
                var_t0 = arg0 - (arg0 & 0x1F);
                do {
                    M2C_ERROR(/* unknown instruction: cache 0x10, ($t0) */);
                    var_t0 += 0x20;
                } while (var_t0 < (u32) (temp_t1 - 0x20));
            }
        } else {
            var_t0_2 = 0x80000000;
            do {
                M2C_ERROR(/* unknown instruction: cache 0x0, ($t0) */);
                var_t0_2 += 0x20;
            } while (var_t0_2 < 0x80003FE0U);
        }
    }
}
