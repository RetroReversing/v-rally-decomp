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





void func_80024584(void **arg0) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_t1;
    s32 var_t3;
    s32 var_t4;
    s32 var_t5;
    s32 var_t6;
    s32 var_t7;
    s32 var_v0;
    void *var_a3;
    void *var_t0;
    void *var_t2;
    void *var_v1;

    var_t0 = *arg0;
    if (var_t0 != NULL) {
        var_t7 = 0x19;
        var_t3 = 1;
        var_t6 = 2;
        var_t5 = 0x400;
        var_t4 = 0x100;
        do {
            var_a3 = *(void * *)((char *)var_t0 + 0x4C);
            var_t2 = *(void * *)((char *)var_t0 + 0x78);
            var_v0 = *(s32 *)((char *)var_a3 + 0);
            var_t1 = *(s32 *)((char *)var_a3 + 4);
            var_a1 = var_t2 + 0x10;
            if (var_v0 == 0) {
                var_v1 = *(void * *)((char *)var_t0 + 0x48);
                var_v0 = *(s32 *)((char *)var_v1 + 0xC);
                if ((var_v0 > 0) || ((var_v0 = *(s32 *)((char *)var_t0 + 0x50), var_v0 = *(s32 *)((char *)var_v0 + 4), var_v0 &= 2, (var_v0 != 0)) && (var_v0 = *(s32 *)((char *)var_v1 + 0x10), (var_v0 > 0)))) {
                    *(s32 *)((char *)var_a3 + 0x18) = 0x19;
                    *(s32 *)((char *)var_a3 + 0) = 1;
                }
                var_v0 = *(s32 *)((char *)var_a3 + 0);
            }
            if (var_v0 == 1) {
                var_v0 = *(s32 *)((char *)var_a3 + 0x18);
                var_v0 -= 1;
                *(s32 *)((char *)var_a3 + 0x18) = var_v0;
                if (var_v0 == 0) {
                    *(s32 *)((char *)var_a3 + 0) = 2;
                    var_v0 = *(s32 *)((char *)var_t2 + 0);
                    *(s32 *)((char *)var_a3 + 4) = var_v0;
                }
            }
            var_a2 = var_t1 * var_t1; var_v0 = *(s32 *)((char *)var_t2 + 0xC); var_a2 = var_a2 >> 0xA; var_a2 *= var_v0;
            var_v0 = var_t1 >> 0xA;
            var_a0 = var_v0 << 0xA;
            var_v0 *= 4;
            var_v0 += var_a1;
            var_a1 = *(s32 *)((char *)var_v0 + 0);
            var_a0 = var_t1 - var_a0;
            var_v1 = 0x400 - var_a0; var_v1 = (void *) ((s32) var_v1 * var_a1); var_v0 = *(s32 *)((char *)var_v0 + 4); var_a0 *= var_v0;
            var_v0 = *(s32 *)((char *)var_t2 + 8);
            var_a1 = *(s32 *)((char *)var_t0 + 0x50);
            var_a2 += var_v0;
            var_v0 = *(s32 *)((char *)var_a1 + 4);
            var_v1 += var_a0;
            var_v0 &= 2;
            var_t1 = (s32) (var_v1 + var_a2);
            if (var_v0 != 0) {
                var_v0 = (s32) *(void * *)((char *)var_t0 + 0x48);
                var_v1 = *(void * *)((char *)var_v0 + 0x10); } else {
                var_v0 = *(s32 *)((char *)var_a1 + 8);
                var_v0 = var_v0 < 6;
                var_v1 = NULL;
                if (var_v0 == 0) {
                    var_v0 = (s32) *(void * *)((char *)var_t0 + 0x4C);
                    *(s32 *)((char *)var_v0 + 8) = 0;
                } else {
                    var_v0 = (s32) *(void * *)((char *)var_t0 + 0x48);
                    var_v1 = *(void * *)((char *)var_v0 + 0xC);
                }
            }
            var_v0 = (s32) *(void * *)((char *)var_t0 + 0x48);
            var_v1 = (void *) ((s32) var_v1 * var_t1);
            var_a0 = *(s32 *)((char *)var_v0 + 0x18);
            var_v0 = var_a0 * 2;
            var_v0 = var_a0 * 3;
            var_v0 = var_a0 * 0x18;
            var_v0 = var_a0 * 0x19;
            var_v0 = var_v0 >> 7;
            var_v0 = 0x100 - var_v0;
            var_v1 = (void *) ((s32) var_v1 >> 8);
            var_v1 -= var_a2;
            var_v1 = (void *) ((s32) var_v1 >> 0xA); var_v0 *= (s32) var_v1; var_v1 = *(void * *)((char *)var_a3 + 0x14);
            var_v0 *= (s32) var_v1;
            *(s32 *)((char *)var_a3 + 0xC) = var_t1;
            *(s32 *)((char *)var_a3 + 0x10) = var_a2;
            var_v0 = var_v0 >> 0xC;
            *(s32 *)((char *)var_a3 + 8) = var_v0;
            var_t0 = *(void * *)((char *)var_t0 + 4);
        } while (var_t0 != NULL);
    }
}
