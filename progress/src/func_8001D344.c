/* identical to record_attach_sprite (matched), with its names changed by decompdecomp */

void *dispatch_name_handler();
s32 str_len();
s32 str_ncat();
extern char sNameSuffix[];
extern char gOrderState[];
extern char D_800C02AA[];
void func_8001D344(s32 *arg0)
{
  s32 *var_a1;
  s32 temp_v0;
  s32 var_a0;
  s32 var_a2;
  s32 var_s0;
  s32 var_v1;
  void *temp_v0_2;
  void *var_v0;
  int new_var;
  temp_v0_2 = arg0;
  var_s0 = temp_v0_2 + 0x4C;
  var_a0 = var_s0;
  temp_v0 = str_len(var_a0);
  var_a1 = &sNameSuffix;
  var_a0 = var_s0;
  var_a1 = &sNameSuffix;
  var_a2 = temp_v0;
  str_ncat(var_a0, &sNameSuffix, var_a2);
  var_v0 = D_800C02AA + 0x5A76;
  var_v0 = *((void **) (D_800C02AA + 0x5A76));
  var_a0 = *((s32 *) (var_v0 + 0x10));
  var_a1 = temp_v0_2;
  temp_v0_2 = dispatch_name_handler(var_a0, var_a1);
  var_v1 = *((s32 *) (((char *) temp_v0_2) + 0x80));
  *((void **) (gOrderState + 0x8A28)) = temp_v0_2;
  var_v1 |= 0x40;
  new_var = 0x80;
  *((s32 *) (((char *) temp_v0_2) + new_var)) = var_v1;
}
