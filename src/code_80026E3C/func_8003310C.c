#include "common.h"

s32 func_800316C4(void *);
s32 func_800317D4(void *);
extern s32 D_8009EB80;
extern char D_8009F32C[];

void func_8003310C(void *arg0)
{
    void *obj;
    void *start;
    s16 i;
    s32 off;

    obj = arg0;
    start = arg0;
    do
    {
        i = 0;
        do
        {
            off = (((s32)(i << 16)) >> 13) + (D_8009EB80 << 5);
            if (*(u16 *)(D_8009F32C + off) == *(u16 *)((char *)obj + 0x8C))
            {
                func_800316C4(obj);
                break;
            }
            i++;
        } while (i < 12);
        if (i == 12)
        {
            func_800317D4(obj);
        }
        obj = *(void **)((char *)obj + 0x5C);
    } while (obj != start && obj != NULL);
}
