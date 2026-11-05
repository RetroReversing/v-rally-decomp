extern s32 D_800A19B0;
extern volatile s32 D_800B5B40;
extern s32 D_800C5BB0[];
extern s32 D_800C8090;
extern s32 D_800C80A8;
s32 func_8007EE9C(void *arg0) {
    s32 result = 0;
    if (D_800A19B0 == 1) {
        ((void (*)(s32))D_800C80A8)(D_800B5B40 - 4);
    }
    D_800A19B0 = 1;
    { void *return_address = __builtin_mips_live_return_address(); D_800B5B40 = (s32)return_address; }
    if (arg0 != 0) {
        s32 index = *(s32 *)((u8 *)arg0 - 8);
        s32 **table = (s32 **)((u8 *)D_800C5BB0 + index * 4);
        result = ((s32 (*)(void *))(*table)[1])(arg0);
    } else {
        ((void (*)(s32))D_800C8090)(D_800B5B40 - 4);
    }
    D_800A19B0 = 0;
    return result;
}
