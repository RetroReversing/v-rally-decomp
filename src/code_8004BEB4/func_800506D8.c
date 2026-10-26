#include "common.h"

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

M2C_UNK func_8005060C(M2C_UNK *);                   /* extern */
extern M2C_UNK *D_800A1234;
extern M2C_UNK *D_800A1238;
extern M2C_UNK D_800B0C58;
extern void *D_800C35A0;
extern M2C_UNK D_800C5BD8;

void func_800506D8(void) {
    func_8005060C(D_800A1234);
    if (M2C_FIELD(D_800C35A0, u16 *, 0x1E) == 0) {
        func_8005060C(D_800A1238);
    }
    D_800A1234 = &D_800B0C58;
    D_800A1238 = &D_800C5BD8;
}
