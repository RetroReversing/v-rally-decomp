typedef struct Slot6C
{
  s32 val;
  u8 c4;
  u8 c5;
  u8 c6;
  u8 c7;
  u8 c8;
  u8 c9[3];
  u8 cC;
  u8 cD[3];
} Slot6C;
typedef struct Code6C
{
  u16 a;
  u16 b;
  u8 pad[10];
} Code6C;
typedef struct Tbl6C
{
  u8 pad[0xE2];
  u16 v[1];
} Tbl6C;
extern Slot6C D_800C3650[][4];
extern Code6C D_800C70D4[];
extern Tbl6C D_800C7124;
extern s32 D_800ADF30[];
extern void func_8006BF30(s32,s32,s32,s32);

void func_8006CF7C(u8 i)
{
  Tbl6C *t = &D_800C7124;
  u8 j = 0;
  u32 v;
  s32 x;
  Code6C *p;

  do
  {
    v = t->v[i * 3 + j];
    if (v != 0xFFFF)
    {
      p = &D_800C70D4[v >> 14];
      func_8006BF30((u8)(j),(u8)(0x17),(u8)(i),(u8)(i));
      D_800C3650[i][j].c6 = ((p->a >> 10) & 0x1F) + 0x41;
      D_800C3650[i][j].c7 = ((p->a >> 5) & 0x1F) + 0x41;
      x = (((u8 *) p)[1] & 0x1F) + 0x41;
      v &= 0x3FFF;
      D_800C3650[i][j].cC = 1;
      D_800C3650[i][j].c8 = x;
      if (v & 1)
        v = -v;
      v = D_800ADF30[i] - v;
      D_800C3650[i][j].val = v;
      D_800C3650[i][j].c4 = (p->b >> 12) + (p->a >> 15) * 16;
    }
    j++;
  }
  while (j < 3);
}
