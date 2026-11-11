void *dispatch_name_handler();
s32 str_len();
s32 str_ncat();
extern char sNameSuffix[];
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_8004CEB4;
static inline char *inline_fn(char *base, int offset)
{
  return base + offset;
}

/* Copies the name string at obj+0x4C into sNameSuffix, links the object from the
   stream state's pointer table into the order state, and sets flag 0xC0 in the
   object's +0x80 word with its +0x88 field pointing at func_8004CEB4. */
void func_8001D2C8(s32 *obj)
{
  s32 *var_a1;
  s32 *var_s1;
  s32 *var_v1;
  s32 temp_v0;
  s32 var_a0;
  s32 var_a2;
  s32 var_s0;
  void *temp_v0_2;
  void *var_v0;
  var_s1 = obj;
  var_s0 = inline_fn((char *)var_s1, 0x4C);
  var_a0 = var_s0;
  temp_v0 = str_len(var_a0);
  var_a0 = var_s0;
  var_a1 = (s32 *)&sNameSuffix;
  var_a1 = (s32 *)&sNameSuffix;
  var_a2 = temp_v0;
  str_ncat(var_a0, &sNameSuffix, var_a2);
  var_v0 = inline_fn(gStreamState, 0x5A82);
  var_v0 = *((void **) inline_fn(gStreamState, 0x5A82));
  var_a0 = *((s32 *) inline_fn((char *) var_v0, 0x10));
  var_a1 = var_s1;
  temp_v0_2 = dispatch_name_handler(var_a0, var_a1);
  var_a0 = *((s32 *) (((char *) temp_v0_2) + 0x80));
  var_a1 = &func_8004CEB4;
  var_v1 = var_a1;
  var_v1 = &func_8004CEB4;
  *((void **) (gOrderState + 0x8A28)) = temp_v0_2;
  *((s32 **) (((char *) temp_v0_2) + 0x88)) = var_a1;
  var_a0 |= 0xC0;
  *((s32 *) (((char *) temp_v0_2) + 0x80)) = var_a0;
}
