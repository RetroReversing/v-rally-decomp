#include "common.h"

s32 func_80031F2C(void *);
void func_80032AE4(void *);
void func_80032FE8(void *);
void func_8003310C(void *);
void func_800324B4(void *);
void func_8003354C(void);
void func_80033238(void *);
void func_80033298(void *);
void func_80033348(void *);
void func_800331D8(void *);

void func_80033370(void *arg0) {
    void *var_s0;
    s16 x;
    s16 y;
    u8 *p;

    var_s0 = arg0;
    do {
        if (func_80031F2C(var_s0) == 0) {
            p = *(u8 **)((u8 *)var_s0 + 0x78);
            x = *(s16 *)(p + 4);
            y = *(s16 *)(p + 6);
            if (x >= 0xFB && y >= 0xFB) {
                func_80033298(var_s0);
            } else if (x >= 0xFB) {
                func_800331D8(var_s0);
            } else if (y >= 0xFB) {
                func_80033238(var_s0);
            } else {
                func_80033348(var_s0);
            }
        }
        var_s0 = *(void **)((u8 *)var_s0 + 0x5C);
    } while (var_s0 != arg0 && var_s0 != NULL);
    func_80032FE8(arg0);
    func_8003310C(arg0);
    func_80032AE4(arg0);
    func_800324B4(arg0);
    func_8003354C();
}
