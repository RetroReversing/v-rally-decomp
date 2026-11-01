#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    u32 ramarray[15];
    u32 pifstatus;
} OSPifRam;
typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 addrh;
    u8 addrl;
    u8 data[32];
    u8 datacrc;
} __OSContRamReadFormat;
extern u8 D_800C3520;
extern s32 D_800A3B40;
extern OSPifRam D_800C8130;
s32 __osContAddressCrc(u32);
u8 __osContDataCrc(void *);
s32 func_8008D8B4();
s32 func_8008D920();
s32 func_80090DC0();
s32 func_80091600();
u32 func_80097420();
s32 osRecvMesg(s32, s32, s32);
u32 func_80096830(s32 arg0, s32 arg1, u16 arg2, s32 arg3)
{
    u32 res;
    s32 i;
    u8 *p;
    s32 tries;

    res = 0;
    p = (u8 *)&D_800C8130;
    tries = 2;
    func_8008D8B4();
    if (D_800C3520 != 2 || D_800A3B40 != arg1) {
        D_800C3520 = 2;
        D_800A3B40 = arg1;
        for (i = 0; i < arg1; i++) {
            *p++ = 0;
        }
        D_800C8130.pifstatus = 1;
        ((__OSContRamReadFormat *)p)->dummy = 0xFF;
        ((__OSContRamReadFormat *)p)->txsize = 3;
        ((__OSContRamReadFormat *)p)->rxsize = 0x21;
        ((__OSContRamReadFormat *)p)->cmd = 2;
        ((__OSContRamReadFormat *)p)->datacrc = 0xFF;
        p[sizeof(__OSContRamReadFormat)] = 0xFE;
    } else {
        p += arg1;
    }
    ((__OSContRamReadFormat *)p)->addrh = arg2 >> 3;
    ((__OSContRamReadFormat *)p)->addrl = __osContAddressCrc(arg2) | (arg2 << 5);
    func_80090DC0(1, &D_800C8130);
    osRecvMesg(arg0, 0, 1);
    do {
        func_80090DC0(0, &D_800C8130);
        osRecvMesg(arg0, 0, 1);
        res = (((__OSContRamReadFormat *)p)->rxsize & 0xC0) >> 4;
        if (res == 0) {
            if (__osContDataCrc(((__OSContRamReadFormat *)p)->data) != ((__OSContRamReadFormat *)p)->datacrc) {
                res = func_80097420(arg0, arg1);
                if (res != 0) {
                    break;
                }
                res = 4;
            } else {
                func_80091600(((__OSContRamReadFormat *)p)->data, arg3, 0x20);
            }
        } else {
            res = 1;
        }
    } while (res == 4 && tries-- >= 0);
    func_8008D920();
    return res;
}

