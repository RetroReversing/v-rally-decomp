typedef struct Pos
{
  u8 pad00[8];
  s16 f8;
  s16 fA;
  s16 fC;
  s16 fE;
} Pos;
typedef struct Obj
{
  u8 pad00[0xC];
  s32 type;
  u8 pad10[0x178 - 0x10];
  Pos *pos;
} Obj;
typedef struct Widget
{
  u8 pad00[0x76];
  s16 id;
  u8 pad78[0x90 - 0x78];
  u8 col[4];
  u8 pad94[0xA4 - 0x94];
  s32 text;
  Obj *obj;
} Widget;
typedef struct Game
{
  u8 pad00[0xE];
  u16 mode;
  u8 pad10[2];
  u16 opts;
  u8 pad14[0x1E - 0x14];
  u16 state;
} Game;
extern Game *D_800C35A0;
extern Obj *D_800C7F84;
extern void func_8003B310();
extern void func_8003B008();
extern void func_8003B240();
extern void func_8003AE84();
extern void func_8003B2C0();
extern void func_8003AF74();
extern void func_8003A9AC(s32, s32, s32, void *, s32, u16, s32);
extern s32 func_80034FF0(s32, s32);
extern Widget *func_80040260(s32, s16, s16, s16, void *, s32);
void func_8003D9C8(s32 arg0, s32 arg1, s32 arg2)
{
  Obj *obj = D_800C7F84;
  Game *g = D_800C35A0;
  Pos *pos = obj->pos;
  u16 i = 0;
  s32 cnt = arg2;
  s32 y = pos->fA;
  s32 x = pos->f8;
  s32 h = pos->fE;
  s32 base = y + 6;
  u16 step;
  s16 n;
  s32 xx;
  s32 tx;
  s32 ty;
  s32 tx2;
  s32 res;
  Widget *w;
  switch (g->mode)
  {
    case 1:
      if (g->state == 0)
    {
      y += h;
      y -= 0x12;
      arg2--;
      func_8003A9AC(arg0, x + 0x4D, y, func_8003B310, arg1, arg2, 0);
      w = func_80040260(arg0, D_800C7F84->pos->f8 + 0x44, y, 2, func_8003B008, 0);
      w->text = func_80034FF0(arg1 + 0x4C, 0);
      w->id = arg2;
      w->obj = D_800C7F84;
    }
    else
    {
      step = 11;
      i = 2;
      do
      {
        func_8003A9AC(arg0, D_800C7F84->pos->f8 + 0x5F, base + step, func_8003B310, arg1, i, 0);
        w = func_80040260(arg0, D_800C7F84->pos->f8 + 0x56, step + base, 2, func_8003B008, 0);
        w->text = func_80034FF0(arg1 + 0x4C, 0);
        step += 11;
        w->id = i;
        i++;
        w->obj = D_800C7F84;
      }
      while (i < 5);
    }
      break;

    case 2:
      xx = x;
      if (!(g->opts & 1))
    {
      xx += 0x16;
      if (obj->type == 3)
      {
        xx -= 0xE;
      }
    }
      if (D_800C35A0->state == 0)
    {
      pos = D_800C7F84->pos;
      y = pos->fA;
      y += pos->fE;
      y -= 0x12;
      arg2 = cnt - 1;
      func_8003A9AC(arg0, xx + 0x39, y, func_8003B310, arg1, arg2, 0);
      w = func_80040260(arg0, xx + 0x2E, y, 2, func_8003B008, 0);
      w->text = func_80034FF0(arg1 + 0x4C, 0);
      w->id = arg2;
      w->obj = D_800C7F84;
    }
    else
    {
      tx = xx + 0x31;
      ty = base + 10;
      func_8003A9AC(arg0, tx, ty, func_8003B240, arg1, i, 0);
      tx2 = (s16) (xx + 0x28);
      w = func_80040260(arg0, tx2, ty, 2, func_8003AE84, 0);
      res = arg1 + 0x4C;
      w->text = func_80034FF0(res, 0);
      w->col[0] = 0xFE;
      w->col[1] = 0xD5;
      w->col[2] = 0x1E;
      w->col[3] = 0xFF;
      func_8003A9AC(arg0, tx, base, func_8003B2C0, arg1, i, 0);
      w = func_80040260(arg0, tx2, base, 2, func_8003AF74, 0);
      w->text = func_80034FF0(res, 0);
      w->obj = D_800C7F84;
      w->obj = D_800C7F84;
    }
      break;

  }

}

