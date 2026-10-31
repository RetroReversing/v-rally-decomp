void func_8002D2C8(s32, s32);
void func_8001FFC4(s32 *arg0, char *arg1, s16 arg2, s16 arg3) {
s32 idx;
s32 off;
s32 off2;
char *tbl;
idx = arg3 * *(u16 *)(arg1 + 0x8A);
idx += *(s32 *)(arg1 + 0x4C);
idx += arg2;
tbl = *(char **)(arg1 + 0x54);
off = idx * 6;
arg0[0] = *(s16 *)(off + (s32)tbl) + *(s32 *)(arg1 + 0x24);
arg0[1] = *(s16 *)(off + (s32)*(char **)(arg1 + 0x54) + 2) + *(s32 *)(arg1 + 0x28);
arg0[2] = *(s16 *)(off + (s32)*(char **)(arg1 + 0x54) + 4) + *(s32 *)(arg1 + 0x2C);
idx += *(u16 *)(arg1 + 0x8A);
off2 = idx * 6;
func_8002D2C8(*(s16 *)(off2 + (s32)*(char **)(arg1 + 0x54)) - *(s16 *)(off + (s32)*(char **)(arg1 + 0x54)),
*(s16 *)(off2 + (s32)*(char **)(arg1 + 0x54) + 4) - *(s16 *)(off + (s32)*(char **)(arg1 + 0x54) + 4));
}
