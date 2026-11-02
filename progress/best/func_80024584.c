typedef struct { s32 state; s32 pos; s32 out; s32 c; s32 d; s32 vol; s32 timer; } Snd;
typedef struct { s32 start; s32 p4; s32 base; s32 k; s32 tbl[1]; } Curve;
typedef struct { u8 pad[0xC]; s32 thr; s32 thr2; u8 p14[4]; s32 damp; } Cfg;
typedef struct { u8 pad[4]; s32 flags; s32 cnt; } Inp;
typedef struct Node {
  u8 pad0[4];
  struct Node *next;
  u8 pad8[0x40];
  Cfg *cfg;
  Snd *snd;
  Inp *inp;
  u8 pad54[0x24];
  Curve *curve;
} Node;

void func_80024584(Node **list)
{
  Node *n;
  Snd *s;
  Curve *c;
  s32 pos;
  s32 sq;
  s32 i;
  s32 frac;
  s32 v;
  s32 m;
  s32 w;
  s32 *tb;

  n = *list;
  if (n != NULL) {
    do {
      s = n->snd;
      c = n->curve;
      pos = s->pos;
      tb = c->tbl;
      if (s->state == 0) {
        if (n->cfg->thr > 0 || ((n->inp->flags & 2) && n->cfg->thr2 > 0)) {
          s->timer = 25;
          s->state = 1;
        }
      }
      if (s->state == 1) {
        if (--s->timer == 0) {
          s->state = 2;
          s->pos = c->start;
        }
      }
      sq = pos * pos; sq >>= 10; sq *= c->k;
      frac = pos - ((pos >> 10) << 10);
      v = (0x400 - frac) * tb[pos >> 10] + frac * tb[(pos >> 10) + 1];
      sq = c->base + sq;
      pos = v + sq;
      if (n->inp->flags & 2) {
        i = n->cfg->thr2; } else if (n->inp->cnt >= 6) {
        i = 0;
        n->snd->out = 0;
      } else {
        i = n->cfg->thr;
      }
      w = (((i * pos) >> 8) - sq) >> 10;
      m = ((0x100 - ((n->cfg->damp * 25) >> 7)) * w) * s->vol;
      s->c = pos;
      s->d = sq;
      s->out = m >> 12;
      n = n->next;
    } while (n != NULL);
  }
}
