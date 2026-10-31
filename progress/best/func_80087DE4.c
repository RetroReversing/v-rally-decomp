u8 *func_80087DE4(u8 *arg0, u8 *arg1)
{
  u8 *new_var;
  u8 *next;
  s32 idx;
  u8 *obj = arg0;
  f32 f;
  idx = obj[0xd3];
  next = arg1 + 1;
  arg0 += idx;
  arg0[0x124] = *arg1;
  new_var = obj + (idx * 4);
  *((u8 **) (new_var + 0xd4)) = next;
  *((s32 *) (new_var + 0xe8)) = *((s32 *) (arg0 + 0x34));
  *((s32 *) (new_var + 0xfc)) = *((s32 *) (arg0 + 0x30));
  arg0[0x129] = arg0[0xb4];
  f = *((f32 *) (obj = obj + 0x6c));
  arg0 += 0x12e;
  *arg0 = (u32) f;
  *((u16 *) ((arg0 + (idx * 2)) + 0x110)) = *((u16 *) (arg0 + 0x9a));
  *((u16 *) ((arg0 + (idx * 2)) + 0x11a)) = *((u16 *) (arg0 + 0x9c));
  arg0[0xd3]++;
  return next;
}
