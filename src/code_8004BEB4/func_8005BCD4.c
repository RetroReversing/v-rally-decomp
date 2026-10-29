#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  u8 pad[0x184];
  void *assets[4];
  u8 p[0x8e];
  s16 slide;
  u8 q[4];
  s8 selected;
  u8 r;
  s8 type;
  u8 t[0x21];
  u8 alpha;
  u8 hidden;
  u8 active;
} Obj;
typedef struct 
{
  u8 p[4];
  void **node;
} Asset;
extern Obj *D_800A1468;
extern u8 *D_800C35A0;
extern void *D_800D05D8;
struct N { int p0; struct N *next; int p8; int key; };
extern struct N *func_8004240C(int);
extern void func_8004C370(s32, void *);
extern void func_800599D0(void *, s32);
extern void func_800596F4(void *, s16, s16, void *);
extern void func_8004CEB4(void *, void *, void *, s32, s32, s32, s32, s32, s32);
void func_8005BCD4(void)
{
  struct 
  {
    s32 rec[16];
    u8 aa[4];
    u8 bb[4];
    u8 cc[4];
    u8 q[4];
    u8 pad[8];
    u8 text[10];
    u8 col[5];
    u8 p;
    f32 f;
    f32 g;
    s16 z;
    u8 pad2[14];
    s16 xy[4];
  } x;
  Obj *o;
  struct N *h;
  u8 i;
  u8 save;
  s8 k;
  s8 j;
  o = D_800A1468;
  if (o->hidden)
  {
    return;
  }
  x.col[0] = o->alpha;
  x.col[2] = (x.col[1] = 0xdc);
  x.col[3] = 0x80;
  x.z = 0;
  x.col[4] = 0xff;
  x.g = (x.f = 1.0f);
  if (o->slide < 0xc0)
  {
    o->slide += 16;
  }
  for (j = 0; j < 4; j++)
  {
    x.rec[12 + j] = 1;
    x.aa[j] = 30;
    x.bb[j] = 50;
    x.cc[j] = 142;
  }

  x.q[0] = (x.q[1] = 210);
  x.q[2] = (x.q[3] = 50);
  h = func_8004240C(1);
  for (i = 0; i < (*((u16 *) (D_800C35A0 + 14))); i++)
  {
    register Obj *a0;
    a0 = D_800A1468;
    if (!a0->assets[i])
    {
      continue;
    }
    if (i < 2)
    {
      register u16 a1;
      a1 = (u16) a0->slide;
      x.xy[1] = (22 * (i & 1)) + 0x1a8;
      x.rec[5] = (x.rec[4] = (i & 2) * 400);
      x.rec[7] = (x.rec[6] = x.rec[4] + 256);
      x.rec[8] = ((i & 1) * 22) + 0x1aa;
      x.rec[10] = (x.rec[9] = ((i & 1) * 22) + 0x1be);
      x.rec[11] = ((i & 1) * 22) + 0x1aa;
      x.xy[0] = a1;
    }
    else
    {
      x.xy[0] = 400;
      x.xy[1] = ((i & 1) * 22) + 0x1a8;
    }
    func_8004C370(*((s32 *) (((u8 *) h) + 0x178)), x.rec);
    x.xy[2] = (*((u16 *) (((u8 *) (*((Asset *) D_800A1468->assets[i])->node)) + 6))) * x.f;
    x.xy[3] = (*((u16 *) (8 + ((u8 *) (*((Asset *) D_800A1468->assets[i])->node))))) * x.g;
    *((s16 *) (x.text + 4)) = (i) ? (0x128) : (0x126);
    *((s16 *) (x.text + 6)) = ((i & 2) * 256) + 42;
    *((s16 *) (x.text + 8)) = ((i & 1) * 22) + 0x1ae;
    func_800599D0(x.text, 0);
    o = D_800A1468;
    save = 255;
    if (o->active && (i == o->selected))
    {
      save = i;
      for (j = 3; j >= 0; j--)
      {
        register u8 *a2;
        register s8 v0;
        a2 = D_800C35A0;
        v0 = j;
        if (*((u8 *)((s32) a2 + (s32) v0 + 0x32)) == o->type)
        {
          break;
        }
      }

      i = j;
    }
    if (D_800A1468->assets[i])
    {
      func_8004CEB4(D_800D05D8, *((Asset *) D_800A1468->assets[i])->node, x.xy, 0, x.col[4], x.col[4], x.col[4], x.col[4], 0);
    }
    if ((x.xy[0] - 64) >= 0)
    {
      register u8 *v1;
      register u8 idx;
      v1 = D_800C35A0;
      idx = *((u8 *)((s32) v1 + (s32) i + 0x32));
      func_800596F4(x.text, x.xy[0] - 48, *((s16 *) (x.text + 8)), v1 + ((idx * 40) + 68));
    }
    if (D_800A1468->active && (save == D_800A1468->selected))
    {
      i = save;
    }
  }

}
