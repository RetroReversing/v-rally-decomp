#include "common.h"

s32 func_8007EE9C();
extern char D_800C02AE[];

void func_800557AC(void *arg0)
{
    u8 found;
    u16 i;
    void **table;
    void *entry;
    u8 kind;

    found = 0;
    i = 0;
    table = (void **)(D_800C02AE + 0x3902);
    do
    {
        entry = table[i];
        if (entry != NULL)
        {
            if (*(void **)((char *)entry + 4) == arg0)
            {
                found = 1;
            }
        }
        i++;
    } while ((found == 0) && (i < 0x800));
    if (found != 0)
    {
        kind = *(u8 *)((char *)entry + 2);
        if (kind == 1)
        {
            func_8007EE9C(entry);
            *(s32 *)(D_800C02AE + 0x38FE + (i << 2)) = 0;
            func_8007EE9C(arg0);
            return;
        }
        *(u8 *)((char *)entry + 2) = kind - 1;
    }
}
