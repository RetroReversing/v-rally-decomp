extern s32 g_pos_bias;
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
void car_update_list(Seg *);
s32 poolAlloc(s32, s32);
void memset(s32, s32, s32);
void add_pos_bias_words(void *, s32);
extern Seg *volatile gMirrorListHead;
extern void (*D_8009C234[])(void *);
extern f32 vtx_scale[];
extern u8 gGameState[];
extern char gOrderState[];
extern s32 D_800C3510;
extern Info *g_rec_val;
/* Fixes up the track's segment table after load: resolves segment links to pointers, applies the position bias to vertex and command pointers, scales the vertex data, and picks the start segment. */ Track *track_segments_setup(Track *track)
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
  if (track->n == 0)
  {
    return track;
  }
  add_pos_bias_words(track, 1);
  segs = track->segs;
  gGameState[0x6C01] = 1;
  t = track;
  for (i = 0; i < t->n; i++)
  {
    s = &segs[i];
    #ifdef PORT
if ((*(s32 *)&s->s5C) != (-1))
#else
if (((s32) s->s5C) != (-1))
#endif
    {
      #ifdef PORT
s->s5C = segs + (*(s32 *)&s->s5C);
#else
s->s5C = segs + ((s32) s->s5C);
#endif
    }
    else
    {
      s->s5C = 0;
      gGameState[0x6C01] = 0;
    }
    #ifdef PORT
if ((*(s32 *)&segs[i].s58) != (-1))
#else
if (((s32) segs[i].s58) != (-1))
#endif
    {
      #ifdef PORT
segs[i].s58 = segs + (*(s32 *)&segs[i].s58);
#else
segs[i].s58 = segs + ((s32) segs[i].s58);
#endif
    }
    else
    {
      segs[i].s58 = 0;
      gGameState[0x6C01] = 0;
    }
    #ifdef PORT
if ((*(s32 *)&segs[i].s64) != (-1))
#else
if (((s32) segs[i].s64) != (-1))
#endif
    {
      #ifdef PORT
segs[i].s64 = segs + (*(s32 *)&segs[i].s64);
#else
segs[i].s64 = segs + ((s32) segs[i].s64);
#endif
    }
    else
    {
      segs[i].s64 = 0;
    }
    {
      #ifdef PORT
      s32 vv = *(s32 *)&segs[i].verts;
#else
      s32 vv = (s32) segs[i].verts;
#endif
      s32 base = g_pos_bias;
#ifdef PORT
      segs[i].verts = (s16 *)(uintptr_t)(vv + base);
#else
      segs[i].verts = (s16 *) (vv + base);
#endif
      segs[i].off70 += base;
      if (segs[i].off6C)
      {
        segs[i].off6C += base;
      }
    }
  }

  if (gGameState[0x6C02] == 0)
  {
    for (i = 0; i < t->n; i++)
    {
      gMirrorListHead = &segs[i];
      if (segs[i].f.b0 && ((&segs[i]) != (&segs[g_rec_val->cur])))
      {
        break;
      }
    }

    D_800C3510 = i;
    gMirrorListHead = &segs[g_rec_val->cur];
  }
  else
  {
    for (i = 0; i < t->n; i++)
    {
      gMirrorListHead = &segs[i];
      if (segs[i].f.b0 && ((&segs[i]) != (&segs[g_rec_val->cur])))
      {
        break;
      }
    }

    old = g_rec_val->cur;
    g_rec_val->cur = i;
    *(Seg **) &gMirrorListHead = &segs[g_rec_val->cur];
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
  if (gGameState[0x6C01] == 1)
  {
    segs[D_800C3510].f.b1 = 0;
    segs[D_800C3510].f.b0 = 0;
    segs[D_800C3510].f.b4 = 0;
    segs[g_rec_val->cur].f.b1 = 0;
    segs[g_rec_val->cur].f.b0 = 1;
    segs[g_rec_val->cur].f.b4 = 1;
  }
  else
  {
    segs[D_800C3510].f.b1 = 1;
    segs[D_800C3510].f.b0 = 0;
    segs[D_800C3510].f.b2 = 0;
    segs[D_800C3510].f.b4 = 1;
    segs[g_rec_val->cur].f.b1 = 0;
    segs[g_rec_val->cur].f.b0 = 1;
    segs[g_rec_val->cur].f.b2 = 1;
    segs[g_rec_val->cur].f.b4 = 1;
  }
  if (gGameState[0x6C01] == 0)
  {
    segs[g_rec_val->cur].f.b2 = 1;
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
      c = q->cmds += g_pos_bias;
      add_pos_bias_words(c, q->count50);
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
    q->alloc = poolAlloc(1, 0x28);
    memset(q->alloc, 0, 0x28);
    q->z7C = 0;
    q->x0 -= 400;
    q->y0 -= 400;
    q->x2 -= 400;
    q->x1 += 400;
    q->y1 += 400;
    q->x3 += 400;
    q->x0 = q->x0 * vtx_scale[0];
    q->y0 = q->y0 * vtx_scale[1];
    q->x2 = q->x2 * vtx_scale[2];
    q->x1 = q->x1 * vtx_scale[0];
    q->y1 = q->y1 * vtx_scale[1];
    q->x3 = q->x3 * vtx_scale[2];
    q->b24 = q->b24 * vtx_scale[0];
    q->b28 = q->b28 * vtx_scale[1];
    q->b2C = q->b2C * vtx_scale[2];
    n = q->h * q->w;
    {
      s16 *v = q->verts;
      for (j = 0; j < n; j++)
      {
        v[(j * 3) + 0] = v[(j * 3) + 0] * vtx_scale[0];
        v[(j * 3) + 1] = v[(j * 3) + 1] * vtx_scale[1];
        v[(j * 3) + 2] = v[(j * 3) + 2] * vtx_scale[2];
      }

    }
  }

  func_80028740(gMirrorListHead);
  for (i = 0; i < t->n; i++)
  {
    func_800307C8(&segs[i]);
  }

  func_80030A0C(gMirrorListHead);
  car_update_list(gMirrorListHead);
  return track;
}
