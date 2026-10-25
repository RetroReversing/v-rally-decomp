#include "common.h"

void func_80088514(void *arg0)
{
    u32 temp_a1;
    u32 temp_v0;
    u32 temp_v1;
    do
    {
        temp_a1 = (*((u8 *) (((char *) arg0) + 0xD1))) + (*((u8 *) (((char *) arg0) + 0xCC)));
        *((u32 *) (((char *) arg0) + 0x8C)) += 0x100;
        if (temp_a1 < 0x40U)
        {
            *((u8 *) (((char *) arg0) + 0xD1)) = temp_a1;
        }
        else
        {
            *((u8 *) (((char *) arg0) + 0xD1)) = temp_a1 & 0x3F;
            temp_a1 = temp_a1 >> 6;
            if ((*((u8 *) (((char *) arg0) + 0xD2))) == 0)
            {
                temp_v0 = (*((u8 *) (((char *) arg0) + 0xB5))) + temp_a1;
                *((u8 *) (((char *) arg0) + 0xB5)) = temp_v0;
                if (((temp_v0 & 0xFF)) >= 0x80U)
                {
                    *((u8 *) (((char *) arg0) + 0xB5)) = 0x7FU;
                    *((u8 *) (((char *) arg0) + 0xD2)) = 1U;
                }
            }
            else
            {
                temp_v1 = (*((u8 *) (((char *) arg0) + 0xB5))) - temp_a1;
                *((u8 *) (((char *) arg0) + 0xB5)) = temp_v1;
                temp_v1 &= 0xFF;
                if ((temp_v1 >= 0x80U) | (temp_v1 == 0))
                {
                    *((u8 *) (((char *) arg0) + 0xB5)) = 0U;
                    *((u8 *) (((char *) arg0) + 0xD2)) = 0U;
                }
            }
        }
    }
    while (((*((u32 *) (((char *) arg0) + 0x8C)))) < ((u32) (*((u32 *) (((char *) arg0) + 8)))));
}
