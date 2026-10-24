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



void func_8003AE84(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(*(void * *)((char *)arg0 + 0xA8), void **, 0x24);
    if (temp_v1 != NULL) {
        *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) | 4);
        if (M2C_FIELD(*(void * *)((char *)temp_v1 + 0x6C), s32 *, 0xC) != 0) {
            *(s16 *)((char *)arg0 + 0x7A) = 0xB;
            if (M2C_FIELD(*(void * *)((char *)temp_v1 + 0x6C), s32 *, 0x20) == 0) {
                *(u8 *)((char *)arg0 + 0x90) = 0xFE;
                *(u8 *)((char *)arg0 + 0x91) = 0xD5;
                *(s8 *)((char *)arg0 + 0x92) = 0x1E;
                *(u8 *)((char *)arg0 + 0x93) = 0xFF;
            }
            *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) & ~4);
        }
    }
}
