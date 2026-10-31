extern s32 D_800A19B0;
extern volatile unsigned long D_800B5B40;
extern s32 *D_800C5BB0[];
extern s32 D_800C72D8[];
extern s32 D_800C808C, D_800C8090, D_800C80A8;
void *func_8007EAA0(s32 arg0, s32 arg1, s32 arg2, ...)
{
 volatile s32 sp10;
 s32 temp_s3;
 s32 var_a0;
 s32 size;
 void *result = NULL;
 if (D_800A19B0 == 1)
  ((void (*)(s32))D_800C80A8)(D_800B5B40-4);
 D_800A19B0=1;
 D_800B5B40=(u32)__builtin_return_address(0);
 temp_s3=*(s32 *)__builtin_next_arg(arg2);
 var_a0=arg0;
 if (!(arg0&0xFFFF0000)) {
  var_a0=D_800C72D8[arg0];
  sp10=arg0; } else sp10=1;
 if (!var_a0) {
  ((void (*)(s32))D_800C8090)(D_800B5B40-4);
  size=0;
 } else size=var_a0-8;
 if (size) {
  result=((void *(*)(s32,s32,s32))*D_800C5BB0[sp10])(size+8,arg1,temp_s3);
  if (result) *(s32 *)((u8 *)result-8)=sp10;
  else ((void (*)(s32,s32))D_800C808C)(arg0,D_800B5B40-4);
 }
 D_800A19B0=0;
 return result;
}
