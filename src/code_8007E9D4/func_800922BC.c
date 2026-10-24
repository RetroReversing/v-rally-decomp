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



s32 func_8008BAF0();
s32 func_80093790();
extern s32 func_800925B0;
extern s32 func_80092AFC;

void func_800922BC(void *arg0, s32 arg1) {
    func_80093790(arg0, &func_800925B0, &func_80092AFC, 4);
    *(s32 *)((char *)arg0 + 0x14) = func_8008BAF0(0, 0, arg1, 1, 0x50);
    *(s32 *)((char *)arg0 + 0x38) = 1;
    *(s32 *)((char *)arg0 + 0x48) = 0;
    *(s16 *)((char *)arg0 + 0x1A) = 1;
    *(s16 *)((char *)arg0 + 0x28) = 1;
    *(s16 *)((char *)arg0 + 0x2E) = 1;
    *(s16 *)((char *)arg0 + 0x1C) = 1;
    *(s16 *)((char *)arg0 + 0x1E) = 1;
    *(s16 *)((char *)arg0 + 0x20) = 0;
    *(s16 *)((char *)arg0 + 0x22) = 0;
    *(s16 *)((char *)arg0 + 0x26) = 1;
    *(s16 *)((char *)arg0 + 0x24) = 0;
    *(s16 *)((char *)arg0 + 0x26) = 1;
    *(s16 *)((char *)arg0 + 0x24) = 0;
    *(s32 *)((char *)arg0 + 0x30) = 0;
    *(s32 *)((char *)arg0 + 0x34) = 0;
    *(s16 *)((char *)arg0 + 0x18) = 0;
    *(s32 *)((char *)arg0 + 0x3C) = 0;
    *(s32 *)((char *)arg0 + 0x40) = 0;
    *(s32 *)((char *)arg0 + 0x44) = 0;
}
