#include "decompdecomp_snapshot_8002c044.h"
#line 1 "func.c"
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(u16*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} Vec;
typedef struct { s32 v[3]; s32 pad[2]; } E20;
typedef struct { s32 x, y, z; } V3;
typedef struct { u8 pad[0x10]; E20 s[12]; E20 d[12]; E20 o[12]; } Blk20;
extern char *D_800B5C40;
void func_8002D8A0(void *, void *, void *);
int func_80028E94(void *, void *, int);
char *func_80028D74(void *, void *);
void func_80029AA8(void *, void *, void *, int);
void func_8002A4C4(void *, void *, int, int);
void func_80029EAC(void *, void *, int);
void func_8002D7E4(int, int *);
void func_8002E778(void *, void *);
void func_8002C6EC(void *, void *);
void func_8002B7D4(void *);
static __inline__ void vadd(E20 *d, E20 *s, int *t)
{
  d->v[0] = s->v[0] + t[0];
  d->v[1] = s->v[1] + t[1];
  d->v[2] = s->v[2] + t[2];
}
void func_8002C044(char *a)
{
int __repair_literal;

  int v[3];
  int q[3];
  Vec pos;
  Vec save;
  int shift[3];
  unsigned i;
  char *g;
  char *old;
  char *b;
  int result;
  int row;
  int col;
  int oldrow;
  int oldcol;
  
  int w;
  int k;
  for (i = 0; i < 12; i++)
  {
    func_8002D8A0(P(a, 0x5c) + 64, &((Blk20 *) P(a, 0x80))->s[i], &((Blk20 *) P(a, 0x80))->d[i]);
    vadd(&((Blk20 *) P(a, 0x80))->o[i], &((Blk20 *) P(a, 0x80))->d[i], (int *) (P(a, 0x58) + 12));
  }
  old = 0;

  for (i = 0; i < 12; i++)
  {
    *(V3 *) v = *(V3 *) &((Blk20 *) P(a, 0x80))->o[i];
    g = ((char **) P(a, 0x8c))[i];
    pos.x = v[0] - W(g, 36);
    pos.y = v[1] - W(g, 40);
    pos.z = v[2] - W(g, 44);
    result = func_80028E94(a, &pos, i);
    if (result > 0)
    {
      int oldrow;
      int oldcol;
      int __repair_literal;
      col = 0;
      row = 0;
      oldcol = ((int *) P(a, 0x60))[i + 12];
      oldrow = ((int *) P(a, 0x60))[i];
      save = pos;
      __repair_literal = result;
      g = func_80028D74(old = g, v);
      if (g != old)
      {
        switch (result)
        {
          case 1:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
            row = -1;
            col = -1;
            break;
          case 2:
            row = 0;
            col = oldcol - (W(old, 76) - W(g, 76));
            break;
          case 3:
            row = U(g, 136) - 2;
            col = oldcol - (W(old, 76) - W(g, 76));
            break;
        }

        w = U(g, 138) - 1; k = row * w;
        if (!((u16 *) P(g, 112))[k + col])
        {
          col = -1;
        }
        if (row >= 0 && col >= 0 && row < U(g, 136) - 1 && col < U(g, 138) - 1)
        {
          W(P(a, 96), (i * 4) + 48) = col;
          W(P(a, 96), i * 4) = row;
          P(P(a, 140), i * 4) = g;
          pos.x = v[0] - W(g, 36);
          pos.y = v[1] - W(g, 40);
          pos.z = v[2] - W(g, 44);
          result = func_80028E94(a, &pos, i);
          if (result)
          {
            result = -result;
          }
        }
        else
        {
          W(P(a, 96), (i * 4) + 48) = oldcol + oldcol - oldcol;
          W(P(a, 96), i * 4) = oldrow;
          g = (char *)((int)old + (int)old - (int)old);
          P(P(a, 140), i * 4) = g;
          pos = save;
          result = -__repair_literal;
        }
      }
      else
      {
        result = -result;
      }
    }
    if (i < 4)
    {
      func_8002D8A0(P(a, 88) + 252, (P(a, 128) + 16) + (i * 20), v);
      v[0] <<= 2;
      v[1] <<= 2;
      v[2] <<= 2;
      v[0] += W(P(a, 88), 232);
      v[1] += W(P(a, 88), 236);
      v[2] += W(P(a, 88), 240);
      q[0] = v[0] - (W(g, 36) << 4);
      q[1] = v[1] - (W(g, 40) << 4);
      q[2] = v[2] - (W(g, 44) << 4);
      if (result < 0)
      {
        if (i == 0)
        {
          shift[0] = 11;
        }
        if (i == 1)
        {
          shift[0] = 10;
        }
        if (i == 2)
        {
          shift[0] = 5;
        }
        if (i == 3)
        {
          shift[0] = 4;
        }
        {
          int k = shift[0] * 4;
          W(P(a, 96), (i * 4) + 48) = W(P(a, 96), k + 48);
          W(P(a, 96), i * 4) = *(int *)(k + (int)P(a, 96));
          P(P(a, 140), i * 4) = *(char **)(k + (int)P(a, 140));
        }
        func_80029AA8(a, q, &pos, i);
      }
      else
        func_80029AA8(a, q, &pos, i);
    }
    else if (result < 0)
    {
      func_8002A4C4(a, &pos, i, result);
    }
    else
    {
      func_80029EAC(a, &pos, i);
    }
  }

  for (b = P(D_800B5C40, 0); b; b = P(b, 4))
  {
    if (((b == a) || (W(b, 20) & 64)) || (W(a, 20) & 64))
    {
      continue;
    }
    v[0] = W(P(a, 92), 84) - W(P(b, 92), 84);
    v[1] = W(P(a, 92), 88) - W(P(b, 92), 88);
    v[2] = W(P(a, 92), 92) - W(P(b, 92), 92);
    func_8002D7E4(v[0], shift);
    func_8002D7E4(v[1], shift + 1);
    func_8002D7E4(v[2], shift + 2);
    if (((shift[0] < 17) || (shift[1] < 17)) || (shift[2] < 17))
    {
      if (shift[0] > shift[1])
      {
        shift[0] = shift[1];
      }
      if (shift[0] > shift[2])
      {
        shift[0] = shift[2];
      }
      shift[0] = 17 - shift[0];
      v[0] >>= shift[0];
      v[1] >>= shift[0];
      v[2] >>= shift[0];
    }
    func_8002E778(v, v);
    v[0] += v[1] + v[2];
    if (v[0] <= 0x4e1ff)
    {
      func_8002C6EC(a, b);
    }
  }

  func_8002B7D4(a + i - i);
}

