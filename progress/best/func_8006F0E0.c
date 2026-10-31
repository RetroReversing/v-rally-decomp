#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
typedef struct 
{
  u16 flag : 1;
  u16 n1 : 5;
  u16 n2 : 5;
  u16 n3 : 5;
  u16 track : 4;
  u16 values : 12;
  u16 flag2 : 1;
  u16 code : 7;
  u16 zero : 8;
  u8 b6;
  u8 b7;
  u16 time;
  u16 x;
  u16 y;
} Save6;
extern s32 D_800C35A0;
extern Save6 D_800C70D4[];
extern u8 D_800A16F4[];
void func_8006F0E0(s32 arg0)
{
  s32 index;
  s32 offset;
  s32 j;
  s32 shift;
  s32 value;
  u8 i;
  u16 time;
  u8 v;
  u8 *p;
  u8 *q;
  Save6 *out;
  index = arg0 & 255;
  offset = index * 40;
  q = D_800C35A0 + offset;
  time = *((u16 *) (((u8 *) q) + 0x52));
  out = &D_800C70D4[index];
  if (time > 65530U)
  {
    time = 65530;
  }
  out->time = time;
  out->x = *((s32 *) (((u8 *) q) + 0x68));
  out->y = *((u16 *) (((u8 *) q) + 0x68));
  if (D_800A16F4[index] >= 4U)
  {
    D_800A16F4[index] = 3;
  }
  p = D_800C35A0 + offset;
  index = D_800A16F4[index] << 5;
  out->code = ((u8) index) + (*((u8 *) (((u8 *) p) + 0x48)));
  out->flag2 = *((u8 *) (((u8 *) p) + 0x4d));
  out->n1 = (*((u8 *) (((u8 *) p) + 0x44))) - 0x41;
  out->n2 = (*((u8 *) (((u8 *) p) + 0x45))) - 0x41;
  out->n3 = (*((u8 *) (((u8 *) p) + 0x46))) - 0x41;
  index = *((u8 *) (((u8 *) p) + 0x4f));
  out->zero = 0;
  out->b6 = 0;
  out->b7 = 0;
  out->track = index & 15;
  out->flag = (index & 16) >> 4;
  out->values = 0;
  i = 0;
  do
  {
    j = i & 255;
    index = *((u8 *) (((u8 *) ((D_800C35A0 + offset) + j)) + 0x54));
    if (((u32) index) < 3U)
    {
      out->zero += (index & 3) << (j * 2);
    }
    shift = j * 2;
    value = ((*((s16 *) (((u8 *) (shift + (D_800C35A0 + offset))) + 0x60))) + 20) / 10;
    if (((u16) value) < 6U)
    {
      index = (value & 7) << (3 * j);
      out->values += (u16) index;
    }
    index = *((u8 *) (((u8 *) ((D_800C35A0 + offset) + j)) + 0x58));
    if (((u32) index) < 3U)
    {
      out->b6 += (index & 3) << shift;
    }
    index = *((u8 *) (((u8 *) ((D_800C35A0 + offset) + j)) + 0x5c));
    offset = ((u32) index) < 3U;
    if (offset)
    {
      out->b7 += (index & 3) << shift;
    }
    i++;
  }
  while (((u32) (i & 255)) < 4U);
}

