#include "common.h"

s32 func_80084DD4();
s32 func_800857C0();
s32 func_800907D0();
s32 func_80090914();
extern s32 D_800A1B70;
extern s32 (*D_800A1B80)();
extern char D_800AE850[];

void func_80085FB8(void)
{
    s32 var_s0;
    s32 var_s1;
    void *temp_s2;

    var_s1 = 0;
    temp_s2 = D_800AE850 + 0x5A38;
    (*D_800A1B80)();
    var_s0 = 0x18C;
    do
    {
        if ((func_80084DD4(var_s1) != 0) && (func_800857C0(var_s1, 2) != 0))
        {
            func_80090914(temp_s2, D_800A1B70 + var_s0, var_s1);
            func_800907D0(D_800A1B70 + var_s0, 0);
            func_80090914(temp_s2, D_800A1B70 + var_s0, var_s1);
            func_800907D0(D_800A1B70 + var_s0, 0);
            func_80090914(temp_s2, D_800A1B70 + var_s0, var_s1);
            func_800907D0(D_800A1B70 + var_s0, 0);
        }
        var_s1 += 1;
        var_s0 += 0x68;
    }
    while (var_s1 < 4);
}
