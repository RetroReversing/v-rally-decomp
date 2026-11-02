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
typedef struct {
  u8 c[3];
  u8 pad47;
  u8 car;
  u8 pad49[4];
  u8 f4d;
  u8 pad4e;
  u8 f4f;
  u8 pad50[2];
  u16 time;
  u8 a[4];
  u8 b[4];
  u8 d[4];
  s16 v[4];
  s32 x68;
} Rec;
typedef struct { u8 pad[0x44]; Rec e[4]; } RS;
extern RS *D_800C35A0;
extern Save6 D_800C70D4[];
extern u8 D_800A16F4[];
void func_8006F0E0(u8 arg0)
{
  s32 index = arg0;
  Save6 *out;
  Rec *r;
  u16 time;
  u8 i;
  u32 j;
  s32 k;
  s32 value;

  time = D_800C35A0->e[index].time;
  out = &D_800C70D4[index];
  if (time > 65530U)
  {
    time = 65530;
  }
  out->time = time;
  out->x = D_800C35A0->e[index].x68;
  out->y = *(u16 *)&D_800C35A0->e[index].x68;
  if (D_800A16F4[index] >= 4U)
  {
    D_800A16F4[index] = 3;
  }
  r = &((RS *)((u8 *)D_800C35A0 + index * 40))->e[0];
  k = D_800A16F4[index] << 5;
  out->code = (u8)k + r->car;
  out->flag2 = r->f4d;
  out->n1 = r->c[0] - 0x41;
  out->n2 = r->c[1] - 0x41;
  out->n3 = r->c[2] - 0x41;
  k = r->f4f;
  out->zero = 0;
  out->b6 = 0;
  out->b7 = 0;
  out->track = k & 15;
  out->flag = (k & 16) >> 4;
  out->values = 0;
  i = 0;
  do
  {
    j = i;
    k = D_800C35A0->e[index].a[j];
    if (k < 3U)
    {
      out->zero += (k & 3) << (j * 2);
    }
    value = (D_800C35A0->e[index].v[j] + 20) / 10;
    if ((u16)value < 6U)
    {
      k = (value & 7) << (3 * j);
      out->values += (u16)k;
    }
    k = D_800C35A0->e[index].b[j];
    if (k < 3U)
    {
      out->b6 += (k & 3) << (j * 2);
    }
    k = D_800C35A0->e[index].d[j];
    if (k < 3U)
    {
      out->b7 += (k & 3) << (j * 2);
    }
    i++;
  }
  while (i < 4U);
}
