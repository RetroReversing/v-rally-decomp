#include "snapshot31_verified.h"

extern s8 D_800ADFA8;
void *func_80022318();
s32 *func_8004D784();
extern s32 D_8009D538;
extern char D_800A4DEC[];
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80042D20(void)
{
    s32 *temp_v0;
    s32 *temp_inner;
    void *temp_v1;
    void *var_s0;
    temp_v0 = func_8004D784(*(void **)(*(char **)(D_800C02AE + 0x326A) + 0x24));
    temp_v0[4] = (temp_v0[4] & ~2) | 1;
    var_s0 = **(void ***)(D_800AE850 + 0x72FC);
    D_800ADFA8 = 0;
    while (var_s0 != NULL) {
        *(u16 *)((char *)var_s0 + 0x20) &= 0xFFBF;
        temp_v1 = func_80022318((char *)var_s0 + 0x28, D_800A4DEC);
        if (temp_v1 != NULL) {
            temp_v1 = *(void **)((char *)temp_v1 + 0x10);
            temp_inner = *(s32 **)temp_v1;
            temp_inner = *(s32 **)((char *)temp_inner+4);
            *(u16 *)((char *)temp_inner + 0x68) &= 0xFFFD;
        }
        var_s0 = *(void **)((char *)var_s0 + 4);
    }
    D_8009D538 = (D_8009D538 & ~0x80) | 1;
}