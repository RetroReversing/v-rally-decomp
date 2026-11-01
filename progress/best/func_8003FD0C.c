#define OBJ D_800C7F84
#define STATE D_800C35A0
extern u8 *D_800C35A0;
extern struct O *D_800C7F84;
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
  u8 color[4];
  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  color[3] = 255;
  if (*(u16 *)(STATE + 14) == 2)
  {
    s32 id = 6;
    if (!(arg0 & 0xFF)) id = 5;
    OBJ = func_8004240C(id);
    if (*(u16 *)(STATE + 18) & 1)
    {
      rect[0] = OBJ->r->x + 32;
      rect[1] = OBJ->r->y + (s16)OBJ->r->h / 2 - 1;
      rect[2] = OBJ->r->w - 32;
      rect[3] = OBJ->r->y + (s16)OBJ->r->h / 2 + 1;
      OBJ = func_8004240C(5);
      func_8000EF0C(OBJ->r, rect, color);
      rect[0] = OBJ->r->x + OBJ->r->w - 32;
      rect[1] = OBJ->r->y;
      rect[2] = OBJ->r->x + OBJ->r->w - 16;
      rect[3] = OBJ->r->h;
      func_8000EF0C(OBJ->r, rect, color);
    }
    else
    {
      rect[0] = OBJ->r->x + (s16)OBJ->r->w / 2 - 1;
      rect[1] = OBJ->r->y;
      rect[2] = OBJ->r->x + (s16)OBJ->r->w / 2 + 1;
      rect[3] = OBJ->r->h;
      func_8000EF0C(OBJ->r, rect, color);
    }
  }
}
