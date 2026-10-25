#include "common.h"

s32 func_800803C0(void *a, void *b);
s32 func_80098180(void *a, void *b);

void func_800224C8(void **arg0, void *arg1)
{
    s32 ok;
    void **node;

    ok = 1;
    if (arg0 != NULL) {
        node = (void **) *arg0;
        if (node != NULL) {
            do {
                if (func_80098180(node[3], arg1) == 0) {
                    ((void (*)(void *)) node[6])(node[4]);
                    ok = 0;
                    func_800803C0(*arg0, arg0);
                }
                node = (void **) node[1];
            } while (ok && node != NULL);
        }
    }
}
