#define W(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define H(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define U(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define A(p,o) (*(void **)((u8 *)(p)+(o)))
typedef struct Rec
{
  s16 v[17];
} Rec;
typedef struct Parent
{
  u8 pad[16];
  s32 flags;
  u8 pad14[36];
  u8 *out;
} Parent;
typedef struct Work
{
  s32 count[12];
  s32 extra[12];
  Rec *start[12];
  Rec *end[12];
  void *sub[12];
} Work;
typedef struct Cursor
{
  s32 count;
  u8 pad4[44];
  s32 extra;
  u8 pad34[44];
  Rec *start;
  u8 pad64[44];
  Rec *end;
  u8 pad94[44];
  void *sub;
} Cursor;
typedef struct Packet
{
  Rec *ptr;
  s16 count;
  s16 zero;
} Packet;
extern s32 D_800B5B44;
extern void *func_8007EAA0(s32, s32);
extern void *func_80006008(s32);
extern void func_80006014(s32, void *);
extern void func_800062B8(s32, void *);
extern void func_80009C90(s32, s32);
extern s32 func_80006060(s32);
extern void func_80019608(void *, void *, void *, s32 *, s32);
extern void func_800197A4(void *, void *, void *, s32 *, s32, void *);
extern void func_80056FE4(Packet *);
extern void func_80057270(void *, u16);
extern void func_80056AB8(s32, Packet *, void *);
extern void func_8007EE9C(void *);
static inline static static static static static u8 *inline_fn(Parent *arg0)
{
  return arg0->out;
}

void func_8001AAB4(Parent *arg0)
{
  Work work;
  Packet packet;
  s32 total;
  s32 used;
  int new_var2;
  Cursor *p;
  void *fp;
  s32 i;
  void *new_var;
  s32 off;
  s32 __repair_off_1;
  s32 handle;
  s32 result;
  used = 0;
  arg0->out = func_8007EAA0(1, 192);
  total = 0;
  for (i = 0; i < 12; i++)
  {
    work.count[i] = 0;
    work.extra[i] = 0;
  }

  func_80019608(((u8 *) arg0) + 0x28, work.count, work.extra, &total, arg0->flags);
  func_80019608(((u8 *) arg0) + 0x30, work.count, work.extra, &total, arg0->flags);
  off = (off = 0);
  p = (Cursor *) (&work);
  fp = func_8007EAA0(1, total * 6);
  do
  {
    if (p->count)
    {
      p->start = func_8007EAA0(1, p->count * 34);
      p->end = p->start;
    }
    else
    {
      p->start = 0;
      p->end = 0;
    }
    if (p->extra)
    {
      A(off + arg0->out, 0x30) = func_8007EAA0(1, p->extra * 24);
      p->sub = A(off + arg0->out, 0x30);
      H(off + arg0->out, 0xa8) = p->extra;
    }
    else
    {
      A(off + arg0->out, 0x30) = 0;
      H(off + arg0->out, 0xa8) = 0;
    }
    off += 2;
    p->sub = 0;
    p = (Cursor *) (((u8 *) p) + 4);
    off += 4;
  }
  while (((s32) p) < ((s32) work.extra));
  p = (Cursor *) (&work);
  __repair_off_1 = 0;
  off = 0;
  func_800197A4(((u8 *) arg0) + 0x28, work.end, fp, &used, arg0->flags, work.sub);
  func_800197A4(((u8 *) arg0) + 0x30, work.end, fp, &used, arg0->flags, work.sub);
  handle = D_800B5B44;
  do
  {
    if (p->end - p->start)
    {
      A(__repair_off_1 + arg0->out, 0) = func_80006008(handle);
      W(__repair_off_1 + arg0->out, 0x60) = func_80006060(handle);
      packet.ptr = p->start;
      new_var2 = p->end - p->start;
      packet.zero = 0;
      packet.count = new_var2;
      func_80056FE4(&packet);
      func_80057270(A(__repair_off_1 + arg0->out, 0x30), U(off + arg0->out, 0xa8));
      func_80009C90(handle, 1);
      func_80056AB8(handle, &packet, fp);
      result = func_80006060(handle);
      new_var = off + arg0->out;
      H(new_var, 0x90) = (result - W(__repair_off_1 + arg0->out, 0x60)) >> 4;
      new_var = (fp = func_80006008(handle));
      func_800062B8(handle, new_var);
      new_var = new_var;
      W(new_var, 0) = 0xdf000000;
      W(new_var, 4) = 0;
      func_80006014(handle, new_var + 8);
    }
    else
    {
      W(__repair_off_1 + arg0->out, 0) = 0;
      W(__repair_off_1 + arg0->out, 0x60) = 0;
      H(off + inline_fn(arg0), 0x90) = 0;
    }
    if (p->start)
    {
      func_8007EE9C(p->start);
    }
    p = (Cursor *) (((u8 *) p) + 4);
    __repair_off_1 += 4;
    off += 2;
  }
  while (__repair_off_1 < 48);
  func_8007EE9C(fp);
}
