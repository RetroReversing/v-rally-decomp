#include "common.h"

extern int D_800B730C;
extern int D_800B7314;
void *func_80098290();

void *func_800823C8(s32 arg0) {
    s32 temp_v1;
    void *temp_s0;
    void *temp_v0;

    temp_v1 = D_800B730C;
    D_800B730C = (s32) (temp_v1 + 1);
    temp_s0 = (void *) (D_800B7314 + (temp_v1 * 0x468));
    func_80098290(temp_s0, arg0);
    temp_v0 = temp_s0;
    *(s32 *)((char *)temp_v0 + 0x10) = 0;
    *(s32 *)((char *)temp_v0 + 0x7C) = 0;
    return temp_v0;
}
