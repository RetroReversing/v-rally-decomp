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

extern int D_800C8118;
extern unsigned char D_800AFA49;


extern char D_800AE850[];
extern char D_800C02AE[];

void func_8005D8B0(void) {
    if (D_800C8118 > 0) {
        D_800C8118 = (s32) (D_800C8118 - 1);
        return;
    }
    if (D_800C8118 == 0) {
        D_800C8118 = -1;
        M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s16 *, 4) = 0;
    }
    if (D_800AFA49 == 1) {
        M2C_FIELD(((M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s16 *, 2) * 0x14) + M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s32 *, 0x10)), s32 *, 0x10) = (s32) D_800AFA49;
        return;
    }
    M2C_FIELD(((M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s16 *, 2) * 0x14) + M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s32 *, 0x10)), s32 *, 0x10) = 0x32;
}
