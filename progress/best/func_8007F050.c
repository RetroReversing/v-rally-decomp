extern s32 D_800A19B0;
extern char D_800AE850[], D_800C02AE[];
extern s32 func_80080F08(s32);
s32 func_8007F050(s32 arg0) {
 s32 a, b, result = 0;
 if (D_800A19B0 == 1)
  (*(void (**)(s32))(D_800C02AE+0x7DFA))(*(s32 *)(D_800AE850+0x72F0)-4);
 D_800A19B0 = 1;
 *(s32 *)(D_800AE850+0x72F0) = (s32)__builtin_return_address(0);
 a = arg0;
 if (!(arg0 & 0xFFFF0000)) a = *(s32 *)(D_800C02AE+0x702A+arg0*4);
 if (a) b = a-8;
 else {
  (*(void (**)(s32))(D_800C02AE+0x7DE2))(*(s32 *)(D_800AE850+0x72F0)-4);
  b = 0;
 }
 if (b) result = func_80080F08(b+8);
 D_800A19B0 = 0;
 return result;
}
