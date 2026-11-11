typedef struct { s16 pad0; s16 idx; s32 pad4[3]; u8 *tbl; } Hdr;
typedef struct { void *next; s16 x; u16 y; u8 a; u8 b; u8 c; u8 pad; } Node;
typedef struct { s32 pad0; u16 id; s16 pad6; s16 pad8; s8 k; s8 padb; s32 padc; f32 v; } RecA;
typedef struct { s32 pad0; s32 pad4; u16 id; s16 pada; s16 padc; s8 k; s8 padf; s32 pad10; f32 v; } RecB;
s32 func_8000C9B0(void *, void *, u8, f32, u8);
s32 pool_get_item(s32, u16);void *select_get_entry(u32);void *textObjGet(u32);
Node *poolAlloc(s32, s32);
extern u8 *gSelectState;
extern char gStreamState[];

/* Creates a list entry at (x_pos, rows) for the text block with id text_id, and appends it to
 * the list at gSelectState+0x24/+0x28, bumping the count at +0x2C. Each of the n_text text
 * records and the `rows` records at the base x is measured with func_8000C9B0 into a running
 * max, which is computed here but not stored. */
void func_80057B40(s32 x_pos, u16 rows, u8 text_id, u8 n_text)
{
  Node *entry;
  Hdr *hdr;
  RecA *a;
  RecB *b;
  u16 base;
  s16 max;
  s8 i;
  s16 r;
  u8 *e;

  entry = poolAlloc(1, 0xC);
  hdr = *(Hdr **)(gStreamState + 0x325A);
  base = x_pos - hdr->tbl[hdr->idx * 20 + 0xD];
  max = 0;
  entry->b = n_text;
  entry->y = rows;
  entry->a = text_id;
  entry->x = base;
  if (n_text != 0) {
    a = textObjGet((u8)(text_id));
    for (i = 0; i < n_text; i++) {
      s32 t = pool_get_item(*(s32 *)(gStreamState + 0x807A), a->id);
      e = gSelectState + a->k * 2;
      r = func_8000C9B0((void *)(gSelectState + (e[0xD0] * 4 + 0xE4)), (void *)(t), (u8)(e[0xD1]), (f32)(a->v), (u8)(0));
      if (r > max) max = r;
    }
  }
  b = select_get_entry((u16)(base));
  for (i = 0; i < rows; i++) {
    s32 t = pool_get_item(*(s32 *)(gStreamState + 0x807A), b->id);
    e = gSelectState + b->k * 2;
    r = func_8000C9B0((void *)(gSelectState + (e[0xD0] * 4 + 0xE4)), (void *)(t), (u8)(e[0xD1]), (f32)(b->v), (u8)(0));
    if (r > max) max = r;
  }
  entry->c = 0;
  if (*(void **)(gSelectState + 0x28) != 0) {
    *(void **)*(void **)(gSelectState + 0x28) = entry;
  } else {
    *(void **)(gSelectState + 0x24) = entry;
  }
  *(void **)(gSelectState + 0x28) = entry;
  *(s32 *)(gSelectState + 0x2C) += 1;
}
