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



extern int D_800C3514;


s32 func_8007EE9C();
extern u8 D_8009B610;
extern char D_800C02AE[];

void func_8000C188(void *arg0) {
    if (arg0 == D_800C3514) {
        if (D_8009B610 == 0) {
            D_800C3514 = 0;
        }
    } else {
        func_8007EE9C(*(void * *)((char *)arg0 + 0x10));
        func_8007EE9C(*(void * *)((char *)arg0 + 0x18));
    }
    func_8007EE9C(arg0);
}
