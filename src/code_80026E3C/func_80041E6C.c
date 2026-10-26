#include "common.h"

s32 func_80022184(void *);
s32 func_80022200(void *);
s32 func_80022484(void *);
s32 func_800803C0(s32, void *);
s32 func_80080478(void *);
s32 func_800804C4(void *, void *);
extern void *D_800B5B4C;
extern char D_800B5B88[];
extern s32 func_8004247C;

s32 func_80041E6C(void)
{
    char *s0;

    if (func_80022184(D_800B5B88) != 0) {
        s0 = *(char **)D_800B5B4C;
        if (s0 != NULL) {
            do {
                func_80022484(s0 + 0x28);
                if (*(s32 *)(s0 + 0x28) != 0) {
                    do {
                        func_800803C0(*(s32 *)(s0 + 0x28), s0 + 0x28);
                    } while (*(s32 *)(s0 + 0x28) != 0);
                }
                s0 = *(char **)(s0 + 4);
            } while (s0 != NULL);
        }
        func_800804C4(D_800B5B4C, &func_8004247C);
        func_80080478(D_800B5B4C);
        D_800B5B4C = NULL;
        func_80022200(D_800B5B88);
        return 1;
    }
    return 0;
}
