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

extern unsigned char D_800ADFE0;


extern char D_800A73E0[];

void func_8003CC98(void *arg0) {
    u32 temp_a1;

    temp_a1 = *M2C_FIELD(M2C_FIELD(*(void * *)((char *)arg0 + 0xA8), void **, 0x24), s32 **, 0x70) + 1;
    if (temp_a1 == D_800ADFE0) {
        *(u8 *)((char *)arg0 + 0x90) = 0xFE;
        *(u8 *)((char *)arg0 + 0x91) = 0xD5;
        *(s8 *)((char *)arg0 + 0x92) = 0x1E;
        *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) & ~4);
    } else {
        *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) | 4);
    }
    if ((u8) D_800ADFE0 < temp_a1) {
        *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) | 4);
    }
}
