#include "common.h"

extern void *D_800A1468;
extern u8 D_800AE850[];
extern u8 D_800A13C0[];
void func_8007F050(s32);
void func_80098290(void *, s32);
void func_8002B618(void *, void *);

void func_80059540(s32 arg0)
{
    s32 sp10[6];
    u8 temp_v1;
    char *obj;
    void (*temp_v0)();

    func_8007F050(1);
    func_8007F050(2);
    func_80098290(sp10, arg0);
    obj = D_800A1468;
    obj[0x235] = 0;
    temp_v1 = D_800AE850[0x120C];
    *((s32 *)(obj + 0x1F0)) = 0;
    func_8002B618(D_800A13C0 + temp_v1 * 0x24, sp10);
    temp_v0 = *((void (**)())((char *)D_800A1468 + 0x288));
    if (temp_v0 != NULL)
    {
        temp_v0();
    }
    *((char *)D_800A1468 + 0x249) = 3;
    *((s32 *)((char *)D_800A1468 + 0x1E4)) = 0;
}
