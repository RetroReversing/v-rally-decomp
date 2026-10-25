#include "common.h"

void *func_80028E24(void *arg0, void *arg1)
{
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    void *var_a2;

    var_a2 = arg0;
    temp_a3 = *((s32 *) arg1);
    do {
        if (temp_a3 >= *((s32 *) (((char *) var_a2) + 0x34)) && *((s32 *) (((char *) var_a2) + 0x3C)) >= temp_a3)
        {
            temp_v0 = *((s32 *) (((char *) var_a2) + 0x44));
            temp_v1 = *((s32 *) (((char *) arg1) + 8));
            if (temp_v1 >= temp_v0 && *((s32 *) (((char *) var_a2) + 0x48)) >= temp_v1)
            {
                return var_a2;
            }
        }
        var_a2 = *((void **) (((char *) var_a2) + 0x5C));
    } while (var_a2 != arg0 && var_a2 != NULL);
    return NULL;
}
