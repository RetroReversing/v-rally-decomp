typedef struct 
{
  u16 pad0;
  u16 pad2;
  s16 h;
  u16 x;
  u16 y;
  u16 z;
} PEnt;
typedef struct 
{
  u8 pad[0xE];
  u8 b;
  u8 a;
  u8 pad10[4];
  u8 v0;
  u8 va;
  u8 vb;
  u8 vend;
  u8 pad18[4];
  PEnt *tbl;
} PDef;
typedef struct 
{
  u8 pad[0x78];
  PDef *def;
  u8 pad7C[0xC];
  u16 n;
} PObj;
void func_8002FFA4(PObj *, s32, s32, u16 *);
s16 func_8003035C(PObj *, s32, u16 *);
void func_800317D4(PObj *o)
{
  u16 p0[3];
  u16 p1[3];
  u16 cur[3];
  s32 a;
  s32 b;
  int new_var;
  s32 va;
  s32 vb;
  s32 v0;
  s32 vend;
  s32 t;
  u16 i;
  s32 d;
  PEnt *e;
  a = o->def->a;
  b = o->def->b;
  va = o->def->va;
  vb = o->def->vb;
  v0 = o->def->v0;
  vend = o->def->vend;
  i = 0;
  if (((s32) b) < ((s32) a))
  {
    t = a;
    a = b;
    b = t;
    i = va;
    va = vb;
    vb = i;
  }
  if (a != 0)
  {
    func_8002FFA4(o, 0, v0, p0);
    func_8002FFA4(o, a, va, p1);
    for (i = 0; i < a; i++)
    {
      cur[0] = ((((s16) (p1[0] - p0[0])) * i) / ((s32) a)) + p0[0];
      cur[1] = ((((s16) (p1[1] - p0[1])) * i) / ((s32) a)) + p0[1];
      cur[2] = ((((s16) (p1[2] - p0[2])) * i) / ((s32) a)) + p0[2];
      o->def->tbl[i].x = cur[0];
      o->def->tbl[i].y = cur[1];
      o->def->tbl[i].z = cur[2];
      o->def->tbl[i].h = func_8003035C(o, i, cur);
    }

  }
  else
  {
    va = v0;
  }
  if (b != 0)
  {
    func_8002FFA4(o, a, va, p0);
    func_8002FFA4(o, b, (s16) vb, p1);
    if (a == b)
    {
      o->def->tbl[i].x = p1[0];
      o->def->tbl[i].y = p1[1];
      o->def->tbl[i].z = p1[2];
      o->def->tbl[i].h = func_8003035C(o, b, p1);
    }
    else
    {
      d = b - a;
      for (i = a; i < b; i++)
      {
        cur[0] = p0[0] + ((((s16) (p1[0] - p0[0])) * (i - ((s32) a))) / d);
        cur[1] = p0[1] + ((((s16) (p1[1] - p0[1])) * (i - ((s32) a))) / d);
        cur[2] = p0[2] + ((((s16) (p1[2] - p0[2])) * (i - ((s32) a))) / d);
        o->def->tbl[i].x = cur[0];
        o->def->tbl[i].y = cur[1];
        o->def->tbl[i].z = cur[2];
        o->def->tbl[i].h = func_8003035C(o, i, cur);
      }

    }
  }
  else
  {
    vb = va;
    b = a;
  }
  func_8002FFA4(o, b, (s16) vb, p0);
  func_8002FFA4(o, o->n - 1, vend, p1);
  new_var = 2;
  i = b;
  if (b == (o->n - 1))
  {
    o->def->tbl[i].x = p1[0];
    o->def->tbl[i].y = p1[1];
    o->def->tbl[i].z = p1[2];
    o->def->tbl[i].h = vend * 10;
    return;
  }
  {
    for (; i <= (o->n - 1); i++)
    {
      cur[0] = p0[0] + ((((s16) (p1[0] - p0[0])) * (i - ((s32) b))) / (o->n - ((s32) (b + 1))));
      cur[1] = p0[1] + ((((s16) (p1[1] - p0[1])) * (i - ((s32) b))) / (o->n - ((s32) (b + 1))));
      cur[2] = p0[2] + ((((s16) (p1[2] - p0[2])) * (i - ((s32) b))) / (o->n - ((s32) (b + 1))));
      o->def->tbl[i].x = cur[0];
      o->def->tbl[i].y = cur[1];
      o->def->tbl[i].z = cur[new_var];
      o->def->tbl[i].h = func_8003035C(o, i, cur);
    }

  }
}

