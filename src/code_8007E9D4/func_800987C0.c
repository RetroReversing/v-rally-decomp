#include "common.h"

extern char *D_800ADEF8;
extern char *D_800ADEFC;
extern s32 D_800ADEF4;
extern s32 D_800ADEF0;
s32 func_8009A530();
s32 func_8009A630();

void func_800987C0(s32 arg0)
{
    char *var_s0;
    char *temp_v0;
    u8 var_a0;

    *D_800ADEF8 = 0;
    if (D_800ADEF4 == 2)
    {
        D_800ADEF8 = D_800ADEFC;
        func_8009A530(D_800ADEFC);
    }
    else
    {
        temp_v0 = D_800ADEFC;
        D_800ADEF8 = temp_v0;
        var_s0 = temp_v0;
        var_a0 = *(u8 *) var_s0;
        if (*var_s0 != 0)
        {
            do
            {
                var_s0 += 1;
                func_8009A630((s8) var_a0);
                var_a0 = *(u8 *) var_s0;
            }
            while (*var_s0 != 0);
        }
    }
    D_800ADEF0 = 0x7F;
    D_800ADEF8 = D_800ADEF8 + 1;
    *(D_800ADEF8 - 1) = arg0;
}
