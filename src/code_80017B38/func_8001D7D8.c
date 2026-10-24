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

extern int D_800B6170;
extern int D_800C3524;


s32 func_8000C22C();
extern char D_800AE850[];
extern char D_800C02AE[];

void func_8001D7D8(void *arg0) {
    if (D_800B6170 != 0) {
        func_8000C22C(D_800C3524, *(u8 *)((char *)arg0 + 0x93), *(u8 *)((char *)arg0 + 0xDF), *(u8 *)((char *)arg0 + 0x12B), (s32) *(u8 *)((char *)arg0 + 0x177));
    }
}
