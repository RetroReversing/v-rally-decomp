#include "common.h"

extern u8 D_800C02AE[];

void func_80017FA4(u8 *arg0)
{
    u16 *flags;
    s32 temp_lo;
    s32 off;
    u8 *tp;
    s32 limit;
    u16 v;
 s32 eight,two,x,y;
    u16 *p;

    x=*(u16*)(arg0+0x8A);
    x-=1;
    y=*(u16*)(arg0+0x88);
    y-=1;
    temp_lo=x*y;

    if (temp_lo > 0) {
        flags = (u16 *)(D_800C02AE + 0x767E);
        tp = *(u8 **)(D_800C02AE + 0x32F2);
        eight=8;
        two=2;
        off = 0;
        limit=temp_lo*2;
        do {
            if (!(*flags & 0x8000)) {
                temp_lo=off + *(u32 *)(arg0 + 0x70);
                if (*(u16*)temp_lo & 0x8000) {
                    *(u16*)temp_lo = 0;
                }
            }
            if (!(*flags & 0x4000)) {
                temp_lo=off + *(u32 *)(arg0 + 0x70);
                if (*(u16*)temp_lo & 0x4000) {
                    *(u16*)temp_lo = 0;
                }
            }
            if (!(*flags & 0x2000)) {
                temp_lo=off + *(u32 *)(arg0 + 0x70);
                if ((*(u16*)temp_lo & 0x2000) && (*(u32 *)(arg0 + 0x60) & 0x13)) {
                    *(u16*)temp_lo = 0;
                }
            }
            if (!(*flags & 0x1000)) {
                temp_lo=off + *(u32 *)(arg0 + 0x70);
                if ((*(u16*)temp_lo & 0x1000) && (*(u32 *)(arg0 + 0x60) & 4)) {
                    *(u16*)temp_lo = 0;
                }
            }
            if (*(u16 *)(tp + 0x1E) == eight) {
                temp_lo=off + *(u32 *)(arg0 + 0x70);
                if (*(u16*)temp_lo == 0) {
                    *(u16*)temp_lo = two;
                }
            }
            p=(u16*)(off+*(u32*)(arg0+0x70));
            v=*p;
            off+=2;
            *p=v&0xF;
        } while (off < limit);
    }
}
