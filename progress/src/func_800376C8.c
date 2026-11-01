typedef struct 
{
  u8 pad[0x178];
  struct 
  {
    u8 pad[12];
    s16 w;
    s16 h;
  } *view;
} Obj;
typedef struct Node
{
  u8 pad[12];
  void *p;
} Node;
typedef struct 
{
  u8 pad[6];
  u16 x;
  u16 y;
} Cam;
typedef struct Link
{
  u8 pad[4];
  struct Link *next;
} Link;
extern void *D_8009B5AC;
extern u8 *D_800C811C;
extern Node **D_800C60D4;
extern u8 *D_800C7F84;
extern void guMtxIdentF(void *);
extern void func_80010BFC(s32, void *, void *);
extern f32 func_8001BE68(void *, f32, f32, f32, f32 *, f32 *, f32 *);
extern void *func_80005C48(void *);
extern void func_8000BA38(void *, s16, s16, void *, s32, s32, s32, s32, s32, s32);
extern void func_80036FD8(void *, void *);
extern void func_800370E8(void *, void *, void *);
void func_800376C8(s32 arg0, Obj *p)
{
  f32 m[4][4];
  f32 x;
  f32 y;
  f32 z;
  f32 a = *((f32 *) (D_800C811C + 0x38));
  f32 b = *((f32 *) (D_800C811C + 0x3c));
  f32 c = *((f32 *) (D_800C811C + 0x40));
  u8 *new_var;
  u16 *base;
  Node *s3;
  Node *s2;
  f32 new_var2;
  u8 i;
  Link *q;
  u16 ix;
  u16 iy;
  u16 t;
  u16 k;
  f32 r;
  guMtxIdentF(m);
  func_80010BFC(0, ((u8 *) p) + 0x38, m);
  r = func_8001BE68(((u8 *) p) + 0xb8, a, b, c, &x, &y, &z);
  if (((((x < 1.0f) && (x > (-1.0f))) && (y < 1.0f)) && (y > (-1.0f))) && (((f64) r) <= 0.0))
  {
    s3 = *D_800C60D4;
    base = func_80005C48(D_8009B5AC);
    new_var2 = (f32) p->view->w;
    ix = (u32) (((x + 1.0f) * ((f32) p->view->w)) * 0.5f);
    iy = (u32) ((y + 1.0f) * (((f32) p->view->h) * 0.5f));
    t = 160 - iy;
    k = ix + (((u16) t) * p->view->w);
    if ((base[k] > 0xfffa) & (((u16) t) < 160))
    {
      Node *n = *((Node **) (((u8 *) s3) + 12));
      Cam *cam = *((Cam **) (((u8 *) n) + 0x1c));
      func_8000BA38(*((void **) (D_800C7F84 + 0x178)), (s16) (ix - cam->x), (s16) (t - cam->y), ((u8 *) n) + 16, 8, 100, ((u8 *) s3)[0x16], ((u8 *) s3)[0x17], ((u8 *) s3)[0x18], 255);
      new_var = ((u8 *) s3) + 4;
      s2 = *((Node **) new_var);
      *((s16 *) (((u8 *) s3) + 16)) = ix;
      *((s16 *) (((u8 *) s3) + 18)) = t;
      func_80036FD8(s3, s2);
      q = *((Link **) (((u8 *) s2) + 4));
      i = 4;
      do
      {
        func_800370E8(s3, s2, q);
        q = q->next;
      }
      while ((i--) & 255);
      func_800370E8(s3, s2, q);
    }
  }
}
