#define OBJ (*(O **)(D_800C02AE+0x7cd6))
#define STATE (*(u8 **)(D_800C02AE+0x32f2))
typedef struct R
{
  u8 pad[8];
  u16 x;
  u16 y;
  u16 w;
  u16 h;
} R;
typedef struct O
{
  u8 pad[0x178];
  R *r;
} O;
extern u8 D_800C02AE[];
O *func_8004240C();
void func_8000EF0C();
void func_8003FD0C(s32 arg0)
{
  s16 rect[4];
  s8 color[4];
  s32 id;
  int new_var;
  R *r;
  color[0] = 0;
  color[1] = 0;
  new_var = arg0 & 255;
  color[2] = 0;
  color[3] = 255;
  if ((*((u16 *) (STATE + 14))) == 2)
  {
    id = 6;
    if (!new_var)
    {
      id = 5;
    }
    do
    {
      OBJ = func_8004240C(id);
    }
    while (0);
    if ((*((u16 *) (STATE + 18))) & 1)
    {
      func_8000EF0C(OBJ->r, rect, color);
      rect[0] = OBJ->r->x + 32;
      r = OBJ->r;
      rect[1] = (r->y + (((s16) r->h) / 2)) - 1;
      rect[2] = OBJ->r->w - 32;
      r = OBJ->r;
      rect[3] = (r->y + (((s16) r->h) / 2)) + 1;
      OBJ = func_8004240C(5);
      func_8000EF0C(OBJ->r, rect);
      r = OBJ->r;
      rect[0] = (r->x + r->w) - 32;
      rect[1] = OBJ->r->y;
      r = OBJ->r;
      rect[2] = (r->x + r->w) - 16;
      rect[3] = OBJ->r->h; }
    else
    {
      r = OBJ->r;
      rect[0] = (r->x + (((s16) r->w) / 2)) - 1;
      rect[1] = OBJ->r->y;
      r = OBJ->r;
      rect[2] = (r->x + (((s16) r->w) / 2)) + 1;
      rect[3] = OBJ->r->h;
    }
  }
}

