void *func_80028E24(s32, s32 *, s32, s32);
void func_80028E94(void *, s16 *, u32, s32);
void func_8002C044(void *);
void func_8002D8A0(s32, s32, s32);
extern s32 D_8009C230;
typedef struct 
{
  s32 x;
  s32 y;
  s32 z;
} Vec3S32;
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} Vec3S16;
void func_8002BD40(u8 *arg0)
{
  Vec3S32 sp10;
  int new_var2;
  Vec3S16 sp20;
  s32 new_var;
  s32 var_s1;
  u32 var_s2;
  s32 var_s3;
  s32 var_s4;
  u8 *temp_a0;
  u8 *temp_a2;
  u8 *temp_v0;
  u8 *temp_v0_2;
  var_s2 = 0;
  var_s4 = 0x100;
  *((s32 *) ((*((u8 **) (arg0 + 0x8C))) + 0x334)) = 0;
  var_s3 = 0x10;
  var_s1 = 0;
  *((s32 *) ((*((u8 **) (arg0 + 0x8C))) + 0x100)) = 0;
  do
  {
    new_var2 = 0x1F4;
    func_8002D8A0((*((s32 *) (arg0 + 0x5C))) + 0x40, (*((s32 *) (arg0 + 0x80))) + var_s3, (*((s32 *) (arg0 + 0x80))) + var_s4);
    temp_a0 = (u8 *) (var_s1 + (*((s32 *) (arg0 + 0x80))));
    temp_a0 = temp_a0 + 0x100;
    temp_a2 = *((u8 **) (arg0 + 0x58));
    var_s1 = *((s32 *) (*((s32 *) (temp_a2 + 0xC))));
    *((s32 *) ((temp_a0 + 0x100) + 0x1F0)) = var_s1 + (temp_a0 + 0x100);
    *((s32 *) ((temp_a0 + 0x100) + new_var2)) = (*((s32 *) ((temp_a0 + 0x100) + 4))) + (*((s32 *) (temp_a2 + 0x10)));
    *((s32 *) (temp_a0 + 0x1F8)) = (*((s32 *) (temp_a0 + 8))) + (*((s32 *) (temp_a2 + 0x14)));
    temp_v0 = (u8 *) (var_s1 + (*((s32 *) (arg0 + 0x80))));
    sp10 = *((Vec3S32 *) (temp_v0 + 0x1F0));
    temp_v0_2 = func_80028E24(D_8009C230, (s32 *) (&sp10), sp10.y, sp10.z);
    var_s4 += 0x14;
    *((u8 **) ((*((u8 **) (arg0 + 0x8C))) + (var_s2 * 4))) = temp_v0_2;
    var_s3 += 0x14;
    sp20.x = sp10.x - (*((s32 *) (temp_v0_2 + 0x24)));
    new_var = *((s32 *) (temp_v0_2 + 0x28));
    sp20.y = sp10.y - new_var;
    sp20.z = sp10.z - (*((s32 *) (temp_v0_2 + 0x2C)));
    var_s1 += 0x14;
    func_80028E94(arg0, (s16 *) (&sp20), var_s2, new_var);
    var_s2 += 1;
  }
  while (var_s2 < 0xC);
  func_8002C044(arg0);
}
