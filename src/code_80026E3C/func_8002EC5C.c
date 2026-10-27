#include "common.h"

void func_8002EC5C(void *arg0, void *arg1, void *arg2)
{
    s32 count;
    s32 n;
    char *rec;
    char *temp;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 qx,qy,qz;
    u16 tmp;
    u16 tmp2;

    count = *(u16 *)((char *)arg1 + 0x16);
    rec = *(char **)((char *)arg1 + 0x10);
    n = count;
    count--;
    temp = *(char **)((char *)arg0 + 0x5C);
    dx = *(s32 *)((char *)arg2 + 0x14) - *(s32 *)(temp + 0x54);
    dy = *(s32 *)((char *)arg2 + 0x18) - *(s32 *)(temp + 0x58);
    dz = *(s32 *)((char *)arg2 + 0x1C) - *(s32 *)(temp + 0x5C);
    if (n == 0)
    {
        return;
    }
    qx = dx / 3; qy = dy / 3; qz = dz / 3;
    do
    {
        if (*(u16 *)rec != 0)
        {
            *(u16 *)(rec + 0x4) = *(u16 *)(rec + 0x4) + (*(u16 *)(rec + 0xA) + qx);
            *(u16 *)(rec + 0x6) = *(u16 *)(rec + 0x6) + (*(u16 *)(rec + 0xC) + qy);
            *(u16 *)(rec + 0x8) = *(u16 *)(rec + 0x8) + (*(u16 *)(rec + 0xE) + qz);
            tmp = *(u16 *)(rec + 0x2);
            *(u16 *)(rec + 0x2) = tmp + 0xFFFF;
            if (tmp == 0)
            {
                if (*(u16 *)(rec + 0x12) != 7)
                {
                    *(u16 *)(rec + 0x12) = *(u16 *)(rec + 0x12) + 1;
                }
                *(u16 *)(rec + 0x2) = *(u16 *)(rec + 0x16);
            }
            if (*(u8 *)(rec + 0x14) != 0)
            {
                *(u8 *)(rec + 0x14) = *(u8 *)(rec + 0x14) + *(u8 *)(rec + 0x15);
            }
            *(u16 *)(rec + 0x18) = *(u16 *)(rec + 0x18) + *(u16 *)(rec + 0x1A);
            if (*(u16 *)(rec + 0x1C) < *(u16 *)(rec + 0x18))
            {
                *(u16 *)(rec + 0x18) = *(u16 *)(rec + 0x1C);
            }
            tmp2 = *(u16 *)(rec + 0x10);
            *(u16 *)(rec + 0x10) = tmp2 + 0xFFFF;
            if (tmp2 == 0)
            {
                *(u16 *)rec = 0;
            }
        }
        rec += 0x24;
    } while (count-- != 0);
}
