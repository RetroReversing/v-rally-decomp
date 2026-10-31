extern char D_800C02AE[];
u64 osGetTime(s16 *);
s32 func_80098090();
s32 func_800980C4(u32);

void func_80035B04(s16 *arg0) {
    s16 *var_s2;
    s32 temp_ret;
    s32 temp_ret_2;
    u32 temp_a1;
    u32 var_s1;

    var_s1 = *(u32 *)(*(char **)(D_800C02AE + 0x7E6E) + 8);
    var_s2 = arg0;
    func_800980C4((u32)osGetTime(arg0));
    temp_a1 = var_s1;
    if (temp_a1 != 0) {
        var_s1 -= 1;
        do {
            if (var_s1 < (*(u32 *)(*(char **)(D_800C02AE + 0x7E6E) + 8) >> 1)) {
                *((s8 *)var_s2 + 6) = 0;
            } else {
                *((s8 *)var_s2 + 6) = 1;
            }
            temp_ret = func_80098090();
            var_s2[0] = temp_ret % 8191;
            temp_ret_2 = func_80098090(temp_ret / 8191);
            var_s2[1] = temp_ret_2 % 2047;
            var_s2[2] = func_80098090(temp_ret_2 / 2047) % 8191;
            var_s2 += 4;
            temp_a1 = var_s1;
            var_s1 -= 1;
        } while (temp_a1 != 0);
    }
}
