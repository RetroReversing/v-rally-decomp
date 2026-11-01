typedef struct Info { char pad0[4]; s16 s4; s16 s6; char pad8[8]; s16 x; s16 y; char pad14[4]; u16 v18; u8 b1A; u8 b1B; } Info;
typedef struct Car { char pad0[8]; s32 flags; char padC[0x4C]; struct Car *prev; struct Car *next; char pad60[0x18]; Info *info; char pad7C[0xC]; u16 n88; char pad8A[2]; u16 id; char pad8E[4]; u8 k92; u8 k93; } Car;
typedef struct Hdr { char pad[0x12]; u16 v; } Hdr;
typedef struct Pre { u8 k0; u8 k1; u16 id; u8 c; u8 d; u16 val; } Pre;
extern f32 D_8009CEC8;
extern s32 D_8009EB80;
typedef struct { s32 v; s32 pad[5]; } T6;
extern T6 D_8009EB84[], D_8009EB88[], D_8009EB8C[];
extern Hdr *D_800C7F80;
extern Pre D_8009F42C[][3];
#define FLAG(c) (*(u16 *)((char *)(c) + 0xA))
void func_800324B4(Car *arg0)
{
  Car *p;
  s32 t, d, e, x, y, side, dist, sp, m, lim, fl, i;
#define a y
#define b x
#define flag a
  t = D_8009CEC8 * (f32)D_800C7F80->v;
  side = 0;
  d = t * 400 / 4096;
  e = t * 900 / 4096;
  p = arg0;
  do {
    p = p;
    dist = 0;
    if (p->prev != NULL && p->next != NULL) {
      x = p->info->x;
      y = p->info->y;
      if (x > d && y < -d) { dist = x - y; side = (p->n88 - 1) / 2; }
      if (x < -d) if (y > d) { dist = y - x; side = (p->n88 - 1) / 2; }
      if (x >= 0 && y < -e) { dist = x - y; side = (p->n88 - 1) / 2; }
      if (x > e && y < 1) { dist = x - y; side = (p->n88 - 1) / 2; }
      if (x < 1 && y > e) { dist = y - x; side = (p->n88 - 1) / 2; }
      if (x < -e && y >= 0) { dist = y - x; side = (p->n88 - 1) / 2; }
      y = x;
      x = p->prev->info->y;
      if (x > d && y < -d) { dist = x - y; side = 0; }
      if (x < -d) if (y > d) { dist = y - x; side = 0; }
      if (x >= 0 && y < -e) { dist = x - y; side = 0; }
      if (x > e && y < 1) { dist = x - y; side = 0; }
      if (x < 1 && y > e) { dist = y - x; side = 0; }
      if (x < -e && y >= 0) { dist = y - x; side = 0; }
      if (side == 0) {
        if ((FLAG(p) & 0x800) && (FLAG(p->prev) & 0x800) && (FLAG(p->next) & 0x800)) dist = 0;
      } else if (FLAG(p) & 0x800) {
        dist = 0;
      }
    }
    a = ((p->flags & 0x402) == 0x402) * 2;
    b = 0;
    if ((p->flags & 0x201) == 0x201) a = 1;
    if (p->next != NULL) {
      fl = p->next->flags;
      if ((fl & 0x402) == 2) b = 2;
      if ((fl & 0x201) == 1) b = 1;
    }
    if (b == 1 && a == 1) {
      sp = p->info->s4 + ((u32)(p->next->info->s4 * D_8009EB8C[D_8009EB80].v) >> 12);
    } else if (b == 2 && a == 2) {
      sp = p->info->s6 + ((u32)(p->next->info->s6 * D_8009EB8C[D_8009EB80].v) >> 12);
    } else {
      sp = 0;
    }
    m = p->info->s4;
    a = p->info->s6;
    if (m < a) m = a;
    flag = 0;
    if (sp > 300) {
      lim = 12000 - ((u32)(sp * D_8009EB88[D_8009EB80].v) >> 12);
      flag = 1;
      if (lim < 0) lim = 0;
    } else if (m > 300) {
      lim = 12000 - ((u32)(m * D_8009EB88[D_8009EB80].v) >> 12);
      if (lim < 0) lim = 0;
    } else {
      lim = 12000;
    }
    if (dist != 0) {
      lim -= (u32)(dist * D_8009EB84[D_8009EB80].v) >> 12;
      p->info->b1A = side;
      p->info->b1B = 2;
      if (lim < 0) lim = 0;
      p->info->v18 = lim;
      p->prev->info->v18 = lim;
      p->prev->info->b1A = *((u8 *)p->prev + 0x89) - 2;
      p->prev->info->b1B = 0;
    }
    if (flag) {
      p->next->info->v18 = lim;
      p->next->info->b1A = 0;
      p->info->b1A = *((u8 *)p + 0x89) - 2;
    }
    if (p->info->v18 == 0) p->info->v18 = lim;
    for (i = 0; i < 3; i++) {
      if (D_8009F42C[D_8009EB80][i].id == 0) break;
      if (D_8009F42C[D_8009EB80][i].id == p->id && D_8009F42C[D_8009EB80][i].k0 == p->k92 && D_8009F42C[D_8009EB80][i].k1 == p->k93) {
        p->info->v18 = D_8009F42C[D_8009EB80][i].val;
        p->info->b1A = D_8009F42C[D_8009EB80][i].c;
        p->info->b1B = D_8009F42C[D_8009EB80][i].d;
      }
    }
    p = p->next;
  } while (p != arg0 && p != NULL);
}
