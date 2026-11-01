extern s32 D_800A19B0;
extern s32 D_800B5B40;
extern s32 *D_800C5BB0[];
extern s32 D_800C72D8[];
extern void (*D_800C8090)(s32), (*D_800C80A8)(s32);
extern void (*D_800C808C)(s32, s32);
s32 func_8007EAA0(s32 arg0, s32 arg1, ...)
{
 volatile s32 sp10;
 s32 temp_s3;
 s32 p;
 s32 q;
 s32 result = 0;
 if (D_800A19B0 == 1) D_800C80A8(D_800B5B40 - 4);
 D_800A19B0 = 1;
 D_800B5B40 = (s32)__builtin_return_address(0);
 temp_s3 = ((s32 *)(((s32)__builtin_next_arg(arg1) + 3) & ~3))[0];
 if (!(arg0 & 0xFFFF0000)) { p = D_800C72D8[arg0]; sp10 = arg0; } else { p = arg0; sp10 = 1; }
 if (p == 0) { D_800C8090(D_800B5B40 - 4); q = 0; } else q = p - 8;
 if (q) {
  result = ((s32 (*)(s32, s32, s32))*(s32 *)D_800C5BB0[sp10])(q + 8, arg1, temp_s3);
  if (result) *(s32 *)(result - 8) = sp10;
  else D_800C808C(arg0, D_800B5B40 - 4);
 }
 D_800A19B0 = 0;
 return result;
}
