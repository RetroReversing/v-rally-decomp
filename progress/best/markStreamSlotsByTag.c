/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

extern s32 stream_state;

void markStreamSlotsByTag(s32 arg0) {
    s32 temp_a1;
    s32 temp_a3;
    s32 var_a2;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    char *var_t0;

    var_t1 = 1;
    var_t3 = M2C_FIELD(&stream_state, s32 *, 0x10386);
    var_t2 = 0;
    if (M2C_FIELD(&stream_state, u16 *, 0x10370) != 0) {
        var_t0 = var_t3 + 0x14;
        do {
            var_a2 = 0;
            if (var_t1 & ((u16) *(u16 *)var_t0 > 0U)) {
                temp_a3 = var_t2 & 0xFF;
                do {
                    temp_a1 = var_a2 & 0xFF;
                    if (M2C_FIELD((var_t3 + (temp_a1 << 6)), u8 *, 0x37) == (arg0 & 0xFFFF)) {
                        var_t1 = 0;
                        *(&stream_state + 0x327E + temp_a3) = *(&stream_state + 0x327E + temp_a3) | (1 << temp_a1);
                    }
                    var_a2 += 1;
                } while (var_t1 & ((u32) (var_a2 & 0xFF) < (u16) *(u16 *)var_t0));
            }
            var_t0 += 0x2C4;
            var_t2 += 1;
            var_t3 += 0x2C4;
        } while (var_t1 & ((u32) (var_t2 & 0xFF) < (u16) M2C_FIELD(&stream_state, u16 *, 0x10370)));
    }
}
