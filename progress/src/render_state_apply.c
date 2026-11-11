typedef struct {
  u32 w0;
  u32 w1;
} DLGfx;
typedef struct {
  u32 a:1;
  u32 b:4;
  u32 c:1;
  u32 e:2;
  u32 d:2;
  u32 ca:1;
  u32 cb:4;
  u32 cc:1;
  u32 ce:2;
  u32 cd:2;
  u32 pad:12;
} RFlags;
typedef struct {
  u8 pad0[0x14];
  DLGfx *dl;
  u8 pad18[0x7C - 0x18];
  s32 x7C;
  s32 x80;
  RFlags f;
} RState;
#define CMD(st, a, b) { DLGfx *_g = (st)->dl; (st)->dl = _g + 1; _g->w0 = (a); _g->w1 = (b); }

/* Emits the RDP state commands for the fields in rs->f whose value differs from
 * the cached copy (the ca..ce bits); force_all re-emits every state and resets
 * the x7C/x80 counters. Returns 1. */
s32 render_state_apply(RState *rs, u8 force_all)
{
  if (force_all == 1)
  {
    rs->x7C = 0;
    rs->x80 = 0;
  }
  if ((rs->f.ca != rs->f.a) | (force_all == 1))
  {
    rs->f.ca = rs->f.a;
    if (rs->f.a)
      CMD(rs, 0xD7000002, 0x80008000)
    else
      CMD(rs, 0xD7000000, 0x80008000)
  }
  if ((rs->f.cb != rs->f.b) | (force_all == 1))
  {
    rs->f.cb = rs->f.b;
    if ((u8)rs->f.b == 0)
      CMD(rs, 0xE3001201, 0)
    else
      CMD(rs, 0xE3001201, 0x2000)
  }
  if ((rs->f.cc != rs->f.c) | (force_all == 1))
  {
    rs->f.cc = rs->f.c;
    if (rs->f.c)
      CMD(rs, 0xE3000C00, 0x80000)
    else
      CMD(rs, 0xE3000C00, 0)
  }
  if ((rs->f.cd != rs->f.d) | (force_all == 1))
  {
    rs->f.cd = rs->f.d;
    switch (rs->f.d)
    {
      case 0:
        CMD(rs, 0xE3001001, 0)
        break;
      case 1:
        CMD(rs, 0xE3001001, 0x8000)
        break;
      case 2:
        CMD(rs, 0xE3001001, 0xC000)
        break;
    }
  }
  if ((rs->f.ce != rs->f.e) | (force_all == 1))
  {
    rs->f.ce = rs->f.e;
    if ((u8)rs->f.e == 0)
      CMD(rs, 0xD9DFFFFF, 0)
    else
      CMD(rs, 0xD9FFFFFF, 0x200000)
  }
  return 1;
}
