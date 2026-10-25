#include "common.h"

void func_8001A2E0(void *);
void func_8007EE9C(s32);
extern u8 D_8009BBBC;

void func_80018F64(u8 *arg0) {
    s32 i;
    u8 *obj;
    s32 val;

    if (D_8009BBBC == 1) {
        if (*(void **)(arg0 + 0x14) != NULL) {
            i = *(s32 *)(*(u8 **)(arg0 + 0x14) + 0x28) - 1;
            if (i >= 0) {
                do {
                    obj = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x14) + 0x2C) + 0 + i * 8);
                    func_8001A2E0(obj);
                    val = *(s32 *)(obj + 0x38);
                    i--;
                    if (val != 0) {
                        func_8007EE9C(val);
                        *(s32 *)(obj + 0x38) = 0;
                    }
                } while (i >= 0);
            }
        }
    }
}
