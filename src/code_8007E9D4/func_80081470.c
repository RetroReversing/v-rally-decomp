#include "common.h"

s32 func_80082350();
void *func_80081470(void *arg0, void *arg1)
{
    u32 off;
    s32 var_s1;
    void **var_s0;

    if (func_80082350(arg1, arg0) != 0)
    {
        return arg0;
    }
    var_s1 = *((s32 *) (((char *) arg0) + 0x10));
    if (var_s1 > 0)
    {
        off = var_s1 << 2;
        var_s0 = (void **) (off + (u32) arg0);
        do
        {
            if (func_80082350(arg1, var_s0[5]) != 0)
            {
                return var_s0[5];
            }
            var_s1 -= 1;
            var_s0 -= 1;
        }
        while (var_s1 > 0);
    }
    return NULL;
}
