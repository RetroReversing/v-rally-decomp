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

extern signed char D_800C72CD;
extern signed char D_800C72CE;
extern signed char D_800C72CF;


s32 func_8006E208();
s32 func_8006E33C();
s32 func_8006F3C0();
s32 func_8006F424();
s32 func_8006F5B0();
extern s32 D_8009F640;
extern char D_800C02AE[];

void func_8006F628(void) {
    D_800C72CD = 0x44;
    D_800C72CE = 0x45;
    D_800C72CF = 0x1D;
    D_8009F640 |= 0x8000;
    func_8006F5B0();
    func_8006F3C0();
    func_8006F424();
    func_8006E208();
    func_8006E33C();
}
