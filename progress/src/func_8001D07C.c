extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_80041F24(void *, u8);
void func_8001CFD0(void *arg0);

void func_8001D07C(void *arg0)
{
    u8 n;
    u32 i;
    s32 flag;
    s32 v;

    n = *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0xF);
    v = *(s32 *)((char *)arg0 + 0x90);
    for (i = 1; i <= n; i++) {
        if (i < 2 || (v != 0 && v != 3)) {
            *(s32 *)(D_800AE850 + 0x252C) = func_80041F24(arg0, i);
            func_8001CFD0(arg0);
        }
    }
}
