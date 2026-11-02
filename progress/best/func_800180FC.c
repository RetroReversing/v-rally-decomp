#define D_800B56EC (*(s32 *)(D_800AE850 + 0x6E9C))
typedef struct 
{
  u32 pad : 27;
  u32 b4 : 1;
  u32 b3 : 1;
  u32 b2 : 1;
  u32 b1 : 1;
  u32 b0 : 1;
} SegFlags;
typedef struct Seg
{
  char pad0[0x24];
  s32 b24;
  s32 b28;
  s32 b2C;
  char pad30[4];
  s32 x0;
  s32 y0;
  s32 x1;
  s32 y1;
  s32 x2;
  s32 x3;
  char pad4C[4];
  s32 count50;
  s16 *verts;
  struct Seg *s58;
  struct Seg *s5C;
  SegFlags f;
  struct Seg *s64;
  char *cmds;
  s32 off6C;
  s32 off70;
  s32 alloc;
  char pad78[4];
  s32 z7C;
  char pad80[8];
  u16 w;
  u16 h;
  char pad8C[8];
} Seg;
typedef struct 
{
  Seg *segs;
  u16 n;
} Track;
typedef struct 
{
  char pad[0x10];
  u16 cur;
} Info;
void func_80017FA4(Seg *);
void func_80028740(Seg *);
void func_800307C8(Seg *);
void func_80030A0C(Seg *);
void func_80033370(Seg *);
s32 func_8007EAA0(s32, s32);
void memset(s32, s32, s32);
void func_80015460(void *, s32);
extern Seg *D_8009C230;
extern void (*D_8009C234[])(void *);
extern f32 D_8009CEC0[];
extern u8 D_800A73E0[];
extern char D_800AE850[];
extern s32 D_800C3510;
extern Info *D_800C7F80;
Track *func_800180FC(Track *t0)
{
  Seg *segs;
  Track *t;
  Seg *s;
  Seg *q;
  s32 i;
  s32 j;
  s32 n;
  s32 old;
  if (t0->n == 0)
  {
    return t0;
  }
  func_80015460(t0, 1);
  segs = t0->segs;
  D_800A73E0[0x6C01] = 1;
  t = t0;
  for (i = 0; i < t->n; i++)
  {
    s = &segs[i];
    if (((s32) s->s5C) != (-1))
    {
      s->s5C = segs + ((s32) s->s5C);
    }
    else
    {
      s->s5C = 0;
      D_800A73E0[0x6C01] = 0;
    }
    if (((s32) segs[i].s58) != (-1))
    {
      segs[i].s58 = segs + ((s32) segs[i].s58);
    }
    else
    {
      segs[i].s58 = 0;
      D_800A73E0[0x6C01] = 0;
    }
    if (((s32) segs[i].s64) != (-1))
    {
      segs[i].s64 = segs + ((s32) segs[i].s64);
    }
    else
    {
      segs[i].s64 = 0;
    }
    segs[i].verts = (s16 *) (((s32) segs[i].verts) + D_800B56EC);
    segs[i].off70 += D_800B56EC;
    if (segs[i].off6C)
    {
      segs[i].off6C += D_800B56EC;
    }
  }

  if (D_800A73E0[0x6C02] == 0)
  {
    for (i = 0; i < t->n; i++)
    {
      D_8009C230 = &segs[i];
      if (segs[i].f.b0 && ((&segs[i]) != (&segs[D_800C7F80->cur])))
      {
        break;
      }
    }

    D_800C3510 = i;
    D_8009C230 = &segs[D_800C7F80->cur]; }
  else
  {
    for (i = 0; i < t->n; i++)
    {
      D_8009C230 = &segs[i];
      if (segs[i].f.b0 && ((&segs[i]) != (&segs[D_800C7F80->cur])))
      {
        break;
      }
    }

    old = D_800C7F80->cur;
    D_800C7F80->cur = i;
    D_8009C230 = &segs[(u16) i];
    D_800C3510 = old;
    for (i = 0; i < t->n; i++)
    {
      Seg *tmp;
      s = &segs[i];
      tmp = s->s5C;
      s->s5C = s->s58;
      s->s58 = tmp;
    }

  }
  if (D_800A73E0[0x6C01] == 1)
  {
    segs[D_800C3510].f.b1 = 0;
    segs[D_800C3510].f.b0 = 0;
    segs[D_800C3510].f.b4 = 0;
    segs[D_800C7F80->cur].f.b1 = 0;
    segs[D_800C7F80->cur].f.b0 = 1;
    segs[D_800C7F80->cur].f.b4 = 1;
  }
  else
  {
    segs[D_800C3510].f.b1 = 1;
    segs[D_800C3510].f.b0 = 0;
    segs[D_800C3510].f.b2 = 0;
    segs[D_800C3510].f.b4 = 1;
    segs[D_800C7F80->cur].f.b1 = 0;
    segs[D_800C7F80->cur].f.b0 = 1;
    segs[D_800C7F80->cur].f.b2 = 1;
    segs[D_800C7F80->cur].f.b4 = 1;
  }
  if (D_800A73E0[0x6C01] == 0)
  {
    segs[D_800C7F80->cur].f.b2 = 1;
  }
  for (i = 0; i < t->n; i++)
  {
    func_80017FA4(&segs[i]);
  }

  for (i = 0; i < t->n; i++)
  {
    if (segs[i].cmds)
    {
      char *c;
 do { segs[i].cmds += D_800B56EC; func_80015460(segs[i].cmds, segs[i].count50); c = segs[i].cmds; } while (0);
      if (c)
      {
        s32 m;
        m = segs[i].count50;
        j = 0;
        if (j < m)
        {
          loop:
          D_8009C234[*((s16 *) (c + 4))](c);

          c += 8;
          j++;
          if (j < m)
          {
            goto loop;
          }
        }
      }
    }
    segs[i].alloc = func_8007EAA0(1, 0x28);
    memset(segs[i].alloc, 0, 0x28);
    segs[i].z7C = 0;
    segs[i].x0 -= 400;
    segs[i].y0 -= 400;
    segs[i].x2 -= 400;
    segs[i].x1 += 400;
    segs[i].y1 += 400;
    segs[i].x3 += 400;
    segs[i].x0 = segs[i].x0 * D_8009CEC0[0];
    segs[i].y0 = segs[i].y0 * D_8009CEC0[1];
    segs[i].x2 = segs[i].x2 * D_8009CEC0[2];
    segs[i].x1 = segs[i].x1 * D_8009CEC0[0];
    segs[i].y1 = segs[i].y1 * D_8009CEC0[1];
    segs[i].x3 = segs[i].x3 * D_8009CEC0[2];
    segs[i].b24 = segs[i].b24 * D_8009CEC0[0];
    segs[i].b28 = segs[i].b28 * D_8009CEC0[1];
    segs[i].b2C = segs[i].b2C * D_8009CEC0[2];
    n = segs[i].h * segs[i].w;
    {
      s16 *v = segs[i].verts;
      for (j = 0; j < n; j++)
      {
        v[(j * 3) + 0] = v[(j * 3) + 0] * D_8009CEC0[0];
        v[(j * 3) + 1] = v[(j * 3) + 1] * D_8009CEC0[1];
        v[(j * 3) + 2] = v[(j * 3) + 2] * D_8009CEC0[2];
      }

    }
  }

  func_80028740(D_8009C230);
  for (i = 0, q = segs; i < t->n; i++, q++)
  {
    func_800307C8(q);
  }

  func_80030A0C(D_8009C230);
  func_80033370(D_8009C230);
  return t0;
}
