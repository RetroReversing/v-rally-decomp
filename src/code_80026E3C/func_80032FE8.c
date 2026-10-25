#include "common.h"

void func_80032FE8(void *arg0)
{
    s32 temp_lo;
    s32 var_t1;
    s32 var_a3;
    char *var_a0;
    char *temp_t3;
    s32 temp_t0;
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_t2;
    char *temp_a1;
    char *temp_v0;

    var_a0 = arg0;
    temp_t3 = arg0;
    do
    {
        temp_v0 = *((char **) (var_a0 + 0x58));
        if (temp_v0 != NULL)
        {
            temp_a1 = *((char **) (var_a0 + 0x78));
            temp_v0 = *((char **) (temp_v0 + 0x78));
            temp_t0 = *((u8 *) (temp_a1 + 0xF));
            temp_a2 = *((u8 *) (temp_a1 + 0xE));
            temp_v1 = *((u8 *) (temp_a1 + 0x14));
            temp_t2 = *((u8 *) (temp_v0 + 0x17));
            var_t1 = 1;
            if (temp_t0 < temp_a2)
            {
                var_t1 = *((s16 *) (temp_a1 + 4)) + 1;
            }
            else if (temp_a2 != 0)
            {
                var_t1 = *((s16 *) (temp_a1 + 6)) + 1;
            }
            temp_a1 = *((char **) (*((char **) (var_a0 + 0x58)) + 0x78));
            temp_t0 = *((u8 *) (temp_a1 + 0xF));
            temp_a2 = *((u8 *) (temp_a1 + 0xE));
            var_a3 = 1;
            if (temp_t0 < temp_a2)
            {
                var_a3 = *((s16 *) (temp_a1 + 6)) + 1;
            }
            else if (temp_a2 != 0)
            {
                var_a3 = *((s16 *) (temp_a1 + 4)) + 1;
            }
            temp_v1 = temp_v1 * var_t1;
            temp_t2 = temp_t2 * var_a3;
            temp_lo = (temp_v1 + temp_t2) / (var_t1 + var_a3);
            *((u8 *) (*((char **) (var_a0 + 0x78)) + 0x14)) = (u8) temp_lo;
            *((s8 *) (*((char **) (*((char **) (var_a0 + 0x58)) + 0x78)) + 0x17)) = (s8) temp_lo;
        }
        var_a0 = *((char **) (var_a0 + 0x5C));
    } while ((var_a0 != temp_t3) && (var_a0 != NULL));
}
