#define W(p,o) (*(u8**)((u8*)(p)+(o)))
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
#define S(p,o) (*(s16*)((u8*)(p)+(o)))
typedef struct 
{
  u8 b[8];
} Pair;
typedef struct 
{
  u8 b[0x178];
  Pair *p;
} Obj;
extern Obj *D_800C7F84;
extern u32 D_800AFA6C;
extern void func_8000A2C4(void *, s32, s32, s32);
void func_80048394(s32 a, u8 *b, Obj *c, s32 d)
{
  Pair **new_var3;
  Pair saved;
  u8 *root = (u8 *) D_800C7F84->p;
  u8 *list;
  s32 x;
  s32 q;
  s32 prod;
  Obj *new_var2;
  Pair **new_var;
  int new_var4;
  s32 off;
  u8 *item;
  s32 h;
  list = (D_800AFA6C & 1) ? (W(b, 0x24)) : (W(b, 0x28));
  saved = *D_800C7F84->p;
  *D_800C7F84->p = *c->p;
  h = H(W(W(W(list, 12), 4), 0), 6);
  x = (s16) (H(b, 4) + H(c->p, 8));
  q = x / h;
  new_var4 = (!D_800C7F84) && (!D_800C7F84);
  prod = q * h;
  d *= 4;
  off = q * 80;
  if (new_var4)
  {
  }
  item = list + off;
  S(item, 28) = d;
  S(item, 20) = (prod - x) * 4;
  W(root, 44) = item;
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  h = H(W(W(W(item, 12), 4), 0), 6);
  x = x - prod;
  S(item, 108) = d;
  S(item, 100) = (h - x) * 4;
  W(root, 44) = list + (off + 80);
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  h = H(W(W(W(item, 92), 4), 0), 6);
  S(item, 180) = ((h * 2) - x) * 4;
  new_var2 = D_800C7F84;
  S(item, 188) = d;
  W(root, 44) = list + (off + 160);
  new_var = &new_var2->p;
  new_var3 = new_var;
  func_8000A2C4(D_800C7F84->p, 0, 0, 1);
  *(*new_var3) = *c->p;
}
