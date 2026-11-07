extern s32 D_800B56EC;
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
extern Seg *volatile D_8009C230;
extern void (*D_8009C234[])(void *);
extern f32 D_8009CEC0[];
extern u8 D_800A73E0[];
extern char D_800AE850[];
extern s32 D_800C3510;
extern Info *D_800C7F80;
Track *func_800180FC(Track *t0)
{
  char *c;
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
    {
      s32 vv = (s32) segs[i].verts;
      s32 base = D_800B56EC;
      segs[i].verts = (s16 *) (vv + base);
      segs[i].off70 += base;
      if (segs[i].off6C)
      {
        segs[i].off6C += base;
      }
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
    D_8009C230 = &segs[D_800C7F80->cur];
  }
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
    *(Seg **) &D_8009C230 = &segs[D_800C7F80->cur];
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
    q = &segs[i];
    if (q->cmds)
    {
      c = q->cmds += D_800B56EC;
      func_80015460(c, q->count50);
      c = q->cmds;
      if (c)
      {
        s32 m;
        m = q->count50;
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
    q->alloc = func_8007EAA0(1, 0x28);
    memset(q->alloc, 0, 0x28);
    q->z7C = 0;
    q->x0 -= 400;
    q->y0 -= 400;
    q->x2 -= 400;
    q->x1 += 400;
    q->y1 += 400;
    q->x3 += 400;
    q->x0 = q->x0 * D_8009CEC0[0];
    q->y0 = q->y0 * D_8009CEC0[1];
    q->x2 = q->x2 * D_8009CEC0[2];
    q->x1 = q->x1 * D_8009CEC0[0];
    q->y1 = q->y1 * D_8009CEC0[1];
    q->x3 = q->x3 * D_8009CEC0[2];
    q->b24 = q->b24 * D_8009CEC0[0];
    q->b28 = q->b28 * D_8009CEC0[1];
    q->b2C = q->b2C * D_8009CEC0[2];
    n = q->h * q->w;
    {
      s16 *v = q->verts;
      for (j = 0; j < n; j++)
      {
        v[(j * 3) + 0] = v[(j * 3) + 0] * D_8009CEC0[0];
        v[(j * 3) + 1] = v[(j * 3) + 1] * D_8009CEC0[1];
        v[(j * 3) + 2] = v[(j * 3) + 2] * D_8009CEC0[2];
      }

    }
  }

  func_80028740(D_8009C230);
  for (i = 0; i < t->n; i++)
  {
    func_800307C8(&segs[i]);
  }

  func_80030A0C(D_8009C230);
  func_80033370(D_8009C230);
  return t0;
}
