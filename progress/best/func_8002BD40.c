typedef struct { s32 x, y, z; } Vec3S32;
typedef struct { s16 x, y, z; } Vec3S16;
void *func_80028E24(s32, Vec3S32 *);
void func_80028E94(void *, Vec3S16 *, u32);
void func_8002C044(void *);
void func_8002D8A0(s32, s32, s32);
extern s32 D_8009C230;

void func_8002BD40(u8 *arg0)
{
  Vec3S32 sp10;
  Vec3S16 sp20;
  s32 var_s1;
  u32 var_s2;
  s32 var_s3;
  s32 var_s4;
  u8 *t;
  var_s2 = 0;
  var_s4 = 0x100;
  *(s32 *)(*(u8 **)(arg0 + 0x8C) + 0x334) = 0;
  var_s3 = 0x10;
  var_s1 = 0;
  *(s32 *)(*(u8 **)(arg0 + 0x8C) + 0x100) = 0;
  do
  {
    func_8002D8A0(*(s32 *)(arg0 + 0x5C) + 0x40, *(s32 *)(arg0 + 0x80) + var_s3, *(s32 *)(arg0 + 0x80) + var_s4);
    {
      s32 base = *(s32 *)(arg0 + 0x80);
      s32 *q = *(s32 **)(arg0 + 0x58);
      s32 *src = (s32 *)(var_s1 + base);
      s32 *dst;
      src += 0x40;
      dst = (s32 *)(var_s1 + base);
      dst += 0x7C;
      dst[0] = src[0] + q[3];
      dst[1] = src[1] + q[4];
      dst[2] = src[2] + q[5];
    }
    sp10 = *(Vec3S32 *)(var_s1 + *(s32 *)(arg0 + 0x80) + 0x1F0);
    t = func_80028E24(D_8009C230, &sp10);
    var_s4 += 0x14;
    *(u8 **)(*(u8 **)(arg0 + 0x8C) + var_s2 * 4) = t;
    var_s3 += 0x14;
    sp20.x = sp10.x - *(s32 *)(t + 0x24);
    sp20.y = sp10.y - *(s32 *)(t + 0x28);
    sp20.z = sp10.z - *(s32 *)(t + 0x2C);
    var_s1 += 0x14;
    func_80028E94(arg0, &sp20, var_s2++);
  }
  while (var_s2 < 0xC);
  func_8002C044(arg0);
}
