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



s32 func_8003B198();

void func_8003B240(void *arg0) {
    void *temp_a0;
    void *temp_v0;

    temp_v0 = M2C_FIELD(*(void * *)((char *)arg0 + 0xA8), void **, 0x24);
    if (temp_v0 != NULL) {
        temp_a0 = *(void * *)((char *)temp_v0 + 0x6C);
        if (*(s32 *)((char *)temp_a0 + 8) == 1) {
            *(s32 *)((char *)arg0 + 0x80) = (s32) (*(s32 *)((char *)arg0 + 0x80) | 4);
            return;
        }
        func_8003B198(arg0, *(s32 *)((char *)temp_a0 + 0xC));
        *(u8 *)((char *)arg0 + 0x90) = 0xFE;
        *(u8 *)((char *)arg0 + 0x91) = 0xD5;
        *(s8 *)((char *)arg0 + 0x92) = 0x1E;
        *(u8 *)((char *)arg0 + 0x93) = 0xFF;
    }
}
