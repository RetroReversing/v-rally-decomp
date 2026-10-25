#include "common.h"

extern u32 D_800C3558;
extern s32 D_800C8328;
extern s32 D_800A14BC[];
s32 func_80057810();
s32 func_800578E0();
s32 func_800592F4();
s32 func_8005F290(s32 arg0)
{
    u32 *temp_a2;
    u32 temp_a1;

    temp_a2 = &D_800C3558;
    if (*temp_a2 < 3) {
        if (*temp_a2 == 0) {
            *temp_a2 = 1;
        }
        temp_a1 = *temp_a2;
        *temp_a2 = temp_a1 + 1;
        func_800592F4(arg0, temp_a1);
        func_800578E0(D_800C8328);
        D_800C8328 = func_80057810(D_800A14BC[D_800C3558]);
    }
    return 0;
}
