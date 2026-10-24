#include "common.h"

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



s32 func_800699E4();
s32 func_8006F75C();
s32 func_8007A794();
extern void *D_8009B5A4;
extern s16 D_800A0370;
extern s16 D_800A0372;
extern u16 D_800A0374;
extern u16 D_800A0376;
extern void *D_800A1468;

void func_8007AA94(void) {
    D_800A0370 = 0;
    D_800A0372 = 0;
    D_800A0374 = *(u16 *)((char *)D_8009B5A4 + 4);
    D_800A0376 = *(u16 *)((char *)D_8009B5A4 + 6);
    func_800699E4();
    *(s8 *)((char *)D_800A1468 + 0x2BD) = -1;
    func_8006F75C();
    func_8007A794();
}
