extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_80041F24();
void func_8001CFD0(void *arg0, void *);

void func_8001D07C(void *arg0)
{
    u32 n;
    u32 i;
    u32 max;
    s32 flag;
    s32 v;

    n = *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0xF);
    v = *(s32 *)((char *)arg0 + 0x90);
    i = 1;
    if (n != 0) {
        flag = (v != 0) & (v != 3);
        max = n;
        do {
            if (i < 2) {
                goto call;
            }
            if (flag == 0) {
                i++;
                continue;
            }
        call:
            *(s32 *)(D_800AE850 + 0x252C) = func_80041F24(arg0, i & 0xFF);
            func_8001CFD0(arg0, arg0);
            i++;
        } while (i <= max);
    }
}
