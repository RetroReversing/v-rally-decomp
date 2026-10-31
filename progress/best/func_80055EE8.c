extern s32 D_8009FF30;
extern u8 D_800C7926;
typedef struct 
{
  u8 color[16];
  u16 pos[4];
  s8 uv[8];
  u16 last;
} Out;
typedef struct 
{
  u16 *records;
  u16 count;
} Info;
void func_80055EE8(Out **dst, Info *in, s32 arg2, u8 *tbl)
{
  u16 *p = in->records;
  int new_var2;
  s32 n = in->count;
  s32 i;
  u8 c = 0x8c;
  s8 *new_var;
  u8 color;
  if (D_800C7926 == 0)
  {
    c = 0x32;
  }
  {
    for (i = 0; i < n; p += 9, i++)
    {
      s8 *bytes = (s8 *) p;
      u16 *q = p + 8;
      (*dst)->pos[0] = p[0] + arg2;
      (*dst)->pos[1] = p[1] + arg2;
      new_var2 = 2;
      (*dst)->pos[new_var2] = p[2] + arg2;
      n = 10;
      (*dst)->pos[3] = p[3] + arg2;
      if (D_8009FF30 != 2)
      {
        color = tbl[p[0]];
      }
      else
      {
        color = c;
      }
      (*dst)->color[0] = color;
      (*dst)->color[1] = color;
      (*dst)->color[2] = color;
      (*dst)->color[3] = n;
      if (D_8009FF30 != 2)
      {
        i = p[1];
        color = tbl[i];
      }
      else
      {
        color = c;
      }
      (*dst)->color[4] = color;
      (*dst)->color[5] = color;
      (*dst)->color[6] = color;
      (*dst)->color[7] = 0;
      if (D_8009FF30 != 2)
      {
        color = tbl[p[2]];
      }
      else
      {
        color = c;
      }
      (*dst)->color[8] = color;
      (*dst)->color[9] = color;
      (*dst)->color[10] = color;
      (*dst)->color[11] = 0;
      if (D_8009FF30 != 2)
      {
        color = tbl[p[3]];
      }
      else
      {
        color = c;
      }
      (*dst)->color[12] = color;
      (*dst)->color[13] = color;
      (*dst)->color[14] = color;
      new_var = (*dst)->uv;
      (*dst)->color[15] = 0;
      {
        s8 *d;
        s32 a;
        s32 b;
        d = new_var;
        a = bytes[8];
        b = bytes[9];
        d[0] = a;
        d[1] = b;
        d = new_var;
        a = bytes[10];
        b = bytes[11];
        d[2] = a;
        d[3] = b;
        d = new_var;
        a = bytes[12];
        b = bytes[13];
        d[4] = a;
        d[5] = b;
        d = new_var;
        a = bytes[14];
        b = bytes[15];
        d[6] = a;
        d[7] = b;
      }
      (*dst)->last = q[0];
      *dst = (Out *) (((u8 *) (*dst)) + 0x22);
    }

  }
}
