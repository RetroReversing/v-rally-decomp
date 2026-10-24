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



extern int D_800C35A0;
extern int D_800C3558;
extern int D_800C8328;


s32 func_8001B5AC();
s32 func_8001B6DC();
s32 func_8002B618();
s32 func_8004D31C();
s32 func_80054838();
s32 func_80057810();
s32 func_800578E0();
s32 func_8005803C();
s32 func_8005BB5C();
s32 func_8005BC60();
s32 func_8005EB48();
s32 func_8006B8C4();
s32 func_8006E33C();
s32 func_8006F75C();
s32 func_8006F7F8();
extern void *D_800A1468;
extern s32 D_800A14C0;
extern s8 D_800A16F0;
extern char D_800A54F0[];
extern char D_800C02AE[];

s32 func_8005F460(void) {
    func_8005803C(0, 0);
    *(s8 *)((char *)D_800A1468 + 0x24D) = 0;
    D_800A16F0 = 0;
    func_8001B5AC(D_800C35A0);
    func_8001B6DC();
    func_8006F7F8();
    D_800A16F0 = 0;
    func_8002B618(&D_800A54F0, 0);
    func_8006B8C4();
    func_8006E33C();
    func_8006F75C();
    func_80054838();
    D_800C3558 = 0;
    func_800578E0(D_800C8328);
    D_800C8328 = func_80057810(D_800A14C0);
    func_8005BC60();
    func_8005BB5C();
    func_8004D31C();
    func_8005EB48();
    return 0;
}
