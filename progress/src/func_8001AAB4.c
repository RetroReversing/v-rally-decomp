typedef struct Rec
{
  s16 v[17];
} Rec;
typedef struct Out
{
  void *dl[12];
  void *verts[12];
  s32 time[12];
  s16 dur[12];
  u16 nverts[12];
} Out;
typedef struct Parent
{
  u8 pad[16];
  s32 flags;
  u8 pad14[20];
  u8 a[8];
  u8 b[8];
  Out *out;
} Parent;
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
extern void func_800062B8(s32);
extern void func_80009C90(s32, s32);
extern s32 func_80006060(s32);
extern void func_80019608(void *, s32 *, s32 *, s32 *, s32);
extern void func_800197A4(void *, Rec **, void *, s32 *, s32, void **);
extern void func_80056FE4(Packet *);
extern void func_80057270(void *, u16);
extern void func_80056AB8(s32, Packet *, void *);
extern void func_8007EE9C(void *);

void func_8001AAB4(Parent *arg0)
{
  s32 count[12];
  s32 extra[12];
  Rec *start[12];
  Rec *end[12];
  void *sub[12];
  Packet packet;
  s32 total;
  s32 used;
  void *buf;
  s32 i;
  s32 h;
  u32 *dl;

  used = 0;
  arg0->out = func_8007EAA0(1, sizeof(Out));
  total = 0;
  for (i = 0; i < 12; i++)
  {
    count[i] = 0;
    extra[i] = 0;
  }
  func_80019608(arg0->a, count, extra, &total, arg0->flags);
  func_80019608(arg0->b, count, extra, &total, arg0->flags);
  buf = func_8007EAA0(1, total * 6);
  for (i = 0; i < 12; i++)
  {
    if (count[i])
    {
      start[i] = func_8007EAA0(1, count[i] * sizeof(Rec));
      end[i] = start[i];
    }
    else
    {
      start[i] = 0;
      end[i] = 0;
    }
    if (extra[i])
    {
      arg0->out->verts[i] = func_8007EAA0(1, extra[i] * 24);
      sub[i] = arg0->out->verts[i];
      arg0->out->nverts[i] = extra[i];
    }
    else
    {
      arg0->out->verts[i] = 0;
      arg0->out->nverts[i] = 0;
      sub[i] = 0;
    }
  }
  func_800197A4(arg0->a, end, buf, &used, arg0->flags, sub);
  func_800197A4(arg0->b, end, buf, &used, arg0->flags, sub);
  h = D_800B5B44;
  for (i = 0; i < 12; i++)
  {
    if (end[i] - start[i])
    {
      arg0->out->dl[i] = func_80006008(h);
      arg0->out->time[i] = func_80006060(h);
      packet.ptr = start[i];
      packet.count = end[i] - start[i];
      packet.zero = 0;
      func_80056FE4(&packet);
      func_80057270(arg0->out->verts[i], arg0->out->nverts[i]);
      func_80009C90(h, 1);
      func_80056AB8(h, &packet, buf);
      arg0->out->dur[i] = (func_80006060(h) - arg0->out->time[i]) >> 4;
      func_800062B8(h);
      dl = func_80006008(h);
      dl[0] = 0xDF000000;
      dl[1] = 0;
      func_80006014(h, dl + 2);
    }
    else
    {
      arg0->out->dl[i] = 0;
      arg0->out->time[i] = 0;
      arg0->out->dur[i] = 0;
    }
    if (start[i])
    {
      func_8007EE9C(start[i]);
    }
  }
  func_8007EE9C(buf);
}
