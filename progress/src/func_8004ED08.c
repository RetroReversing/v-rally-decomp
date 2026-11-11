static inline int __repair_pointer_bits(void *value)
{
  return (int)value;
}

typedef struct Node
{
  s32 x0;
  s32 x4;
  s32 x8;
  s32 xc;
  s32 x10;
  s32 x14;
  u16 x18;
  u16 x1a;
  u16 x1c;
  s32 x20;
  s16 x24[2];
  u8 b28[20];
} Node;

typedef struct Control
{
  Node *node;
  s16 state;
  s16 enabled;
} Control;

typedef struct
{
  u8 pad00[0x24];
  s32 x24;
  s32 x28;
  s32 x2c;
  u8 pad30[0x20];
  s32 inited;
  u8 *table;
  u8 pad58[0x10];
  Control *ctrl;
  u8 pad6c[0x1e];
  u16 first_idx;
} Ctx;

extern void *poolAlloc(s32, s32);

/* Per-frame update of one recorder control. state 3 starts a new segment: it allocates a
 * 60-byte node and fills its start/end coordinates from the table entries at idx and
 * first_idx. state 0 appends one 8-byte record to the node, or ends the segment once the
 * node's record slot is used up (z flags that case, so no record is written). */
void func_8004ED08(Ctx *ctx, s32 b, s32 c, s32 d, s32 e, s32 f, s32 idx)
{
  u8 *rec = 0;
  s32 new_var;
  s32 z = 0;
  s32 q;
  s32 q2;
  s32 r;
  s32 q3;
  s32 q4;
  s32 eb;
  Node *p;
  Control *m;
  if (ctx->inited == 0)
  {
    ctx->ctrl = poolAlloc(1, 8);
    ctx->ctrl->enabled = 1;
    ctx->ctrl->state = 3;
    ctx->inited = 1;
  }
  m = ctx->ctrl;
  if (m->state == 3)
  {
    m->state = 0;
    p = poolAlloc(1, 60);
    p->x0 = (*((s16 *) ((idx * 6) + ctx->table))) + ctx->x24;
    r = idx * 6;
    p->x4 = (*((s16 *) (ctx->table + ((idx * 6) + 2)))) + ctx->x28;
    p->x8 = (*((s16 *) (ctx->table + (r + 4)))) + ctx->x2c;
    new_var = __repair_pointer_bits(ctx->table);
    q = new_var;
    q2 = (idx - ctx->first_idx) * 6;
    p->xc = (*((s16 *) (q2 + q))) - (*((s16 *) ((idx * 6) + q)));
    q = __repair_pointer_bits(ctx->table);
    p->x10 = (*((s16 *) ((((idx - ctx->first_idx) * 6) + q) + 2))) - (*((s16 *) (((idx * 6) + q) + 2)));
    q = __repair_pointer_bits(ctx->table);
    q3 = *((s16 *) ((((idx - ctx->first_idx) * 6) + q) + 4));
    q4 = *((s16 *) ((r + q) + 4));
    rec = ((u8 *) p) + 0x1c;
    p->x18 = 1;
    p->x1a = 0;
    p->x14 = q3 - q4;
    m->node = p;
  }
  else
    if (m->state == 0)
  {
    p = m->node;
    rec = ((u8 *) p) + 0x1c;
    if ((*((u16 *) rec)) == 0)
    {
      rec = ((u8 *) p) + 0x28;
      p->x20 = 4;
      p->x18++;
    }
    else
    {
      z = 1;
    }
  }
  else
  {
    z = 1;
  }
  if (z == 0)
  {
    *((s16 *) rec) = 5;
    *((s32 *) (rec + 4)) = 0;
    *((s16 *) (rec + 2)) = 1;
    rec[8] = c;
    rec[9] = d;
    eb = (rec[0xa] = e);
    rec[0xb] = f;
    *((s32 *) (rec + 0xc)) = b;
  }
}
