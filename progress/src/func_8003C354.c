typedef void (*SpriteHook)(void);
typedef struct {
  char pad0[0x78];
  s16 unk78;
  s16 unk7A;
  char pad7C[0x10];
  void *unk8C;
  char pad90[8];
  s16 unk98;
  s16 unk9A;
  char pad9C[8];
  s32 unkA4;
  void *unkA8;
} Sprite;
typedef struct { char pad[8]; s16 x; s16 y; s16 w; s16 h; } Rect;
typedef struct { char pad[0xC]; s32 unkC; char pad10[0x168]; Rect *rect; } Owner;
typedef struct { char pad[0xE]; u16 mode; char pad10[2]; u16 flags; } Cfg;

s32 func_80034FF0(s32, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
Owner *func_8004240C(s32);
void func_8003C254(void);
extern Cfg *D_800C35A0;
extern Owner *D_800C7F84;

void func_8003C354(s32 arg0, s32 arg1, u16 arg2)
{
  Owner *o;
  Rect *r;
  Sprite *a;
  Sprite *b;
  s32 x, y, w, h, w2, h2;
  s32 sx;
  s16 sy;
  s32 off;

  o = func_8004240C(((arg2 - 1) * 2) | 1);
  r = o->rect;
  D_800C7F84 = o;
  x = r->x + 20;
  y = r->y + 6;
  w = r->w;
  h = r->h;
  w2 = w - 16;
  h2 = h - 8;
  switch (D_800C35A0->mode) {
  case 1:
    sy = h - 20;
    a = ((Sprite *)func_80040260((void *)(arg0), w - 82, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    a->unk7A = 0;
    a->unk78 = 1;
    a->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    a->unkA8 = D_800C7F84;
    b = ((Sprite *)func_80040260((void *)(arg0), w - 73, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    b->unk7A = 0;
    b->unk78 = 1;
    b->unk8C = a;
    b->unkA8 = D_800C7F84;
    b->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    a = ((Sprite *)func_80040260((void *)(arg0), w - 64, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    a->unk7A = 0;
    a->unk78 = 0;
    a->unk8C = b;
    a->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    a->unkA8 = D_800C7F84;
    break;
  case 2:
    off = 0;
    if (!(D_800C35A0->flags & 1)) {
      x = r->x + 4;
      off = -(o->unkC == 1) & 20;
    }
    sx = x + w2;
    sy = y + h2 - 14;
    a = ((Sprite *)func_80040260((void *)(arg0), (s32)(sx + 0xFFCCU) + off, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    a->unk7A = 0;
    a->unk78 = 1;
    a->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    a->unk98 = 0x600;
    a->unk9A = 0x600;
    a->unkA8 = D_800C7F84;
    b = ((Sprite *)func_80040260((void *)(arg0), (s32)(sx + 0xFFD5U) + off, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    b->unk7A = 0;
    b->unk78 = 1;
    b->unk8C = a;
    b->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    b->unk98 = 0x600;
    b->unk9A = 0x600;
    b->unkA8 = D_800C7F84;
    a = ((Sprite *)func_80040260((void *)(arg0), (s32)(sx + 0xFFDEU) + off, sy, (s16)(3), (SpriteHook)(func_8003C254), 0));
    a->unk7A = 0;
    a->unk78 = 0;
    a->unk8C = b;
    a->unkA4 = func_80034FF0(arg1 + 0x4C, 0);
    a->unk98 = 0x600;
    a->unk9A = 0x600;
    a->unkA8 = D_800C7F84;
    break;
  }
}
