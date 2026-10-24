#include "common.h"

s32 func_80022184();
s32 func_80022200();
s32 func_80047D18();
s32 func_8007EE9C();
s32 func_80080478();
extern char D_800AE850[];

void func_80047F94(void) {
    void *var_s0;

    if (func_80022184(D_800AE850 + 0x7348) != 0) {
        if (*(void ** *)(D_800AE850 + 0x6D94) != NULL) {
            var_s0 = **(void ** *)(D_800AE850 + 0x6D94);
            if (var_s0 != NULL) {
                do {
                    func_80047D18(*(s32 *)((char *)var_s0 + 0xC));
                    func_80047D18(*(s32 *)((char *)var_s0 + 0x44));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x30));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x68));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x34));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x6C));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x38));
                    func_8007EE9C(*(s32 *)((char *)var_s0 + 0x70));
                    var_s0 = *(void * *)((char *)var_s0 + 4);
                } while (var_s0 != NULL);
            }
        }
        func_80022200(D_800AE850 + 0x7348);
        func_80080478(*(void ** *)(D_800AE850 + 0x6D94));
        *(void ** *)(D_800AE850 + 0x6D94) = NULL;
    }
}
