typedef char *va_list7F;
typedef struct 
{
  s32 a;
  s32 b;
} Hdr7F12C;
typedef struct 
{
  s32 pad[3];
  s32 (*fn)(void *, s32, s32, s32);
} Cls7F12C;
extern s32 D_800A19B0;
extern void *D_800B5B40;
extern Cls7F12C *D_800C5BB0[];
extern void *D_800C72D8[];
extern void (*D_800C8090)(void *);
extern void (*D_800C80A8)(void *);
s32 func_8007F12C(u32 id, s32 *ret, s32 arg2, ...)
{
  va_list7F ap;
  s32 x;
  int new_var4;
  s32 y;
  s32 idx;
  s32 *pidx = &idx;
  Cls7F12C **new_var2;
  int new_var3;
  Hdr7F12C *p;
  Cls7F12C *c;
  s32 *new_var;
  if (D_800A19B0 == 1)
  {
    D_800C80A8(((char *) D_800B5B40) - 4);
  }
  D_800A19B0 = 1;
  {
    void *u;
    do
    {
      D_800B5B40 = u;
    }
    while (0);
  }
 do { ap = (va_list7F) __builtin_next_arg(arg2); ap = (char *) ((((int) ap) + 3) & (-4)); new_var4 = 1; x = *((s32 *) ap); ap += 4; ap = (char *) ((((int) ap) + 3) & (-4)); new_var = (s32 *) ap; y = *new_var; if (!(id & 0xFFFF0000)) { p = D_800C72D8[id]; idx = id; } else { p = (Hdr7F12C *) id; idx = new_var4; } if (new_var3 = p == 0) { D_800C8090(((char *) D_800B5B40) - 4); p = 0; } else { p--; } } while (0);
  if (p != 0)
  {
    new_var2 = D_800C5BB0;
    c = new_var2[idx];
    if (c != 0)
    {
      *ret = c->fn(p + 1, arg2, x, y);
    }
  }
  D_800A19B0 = 0;
  return 0;
}
