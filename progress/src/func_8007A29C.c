#define B(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define P(p,o) (*(void **)((u8 *)(p)+(o)))
#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define SH(p,o) (*(s16 *)((u8 *)(p)+(o)))
void func_8004C7F0(void *);
void stream_free_all_blocks(void);
void *select_get_entry(u32);
void *textObjGet(u32);
void func_8005937C(s32, s32);
void func_8005BB5C(void);
void select_clear_slots(void);
void func_80069974(void);
s32 heapFreeBlock(void *);
s32 resolve_path(u8 *);
void record_set_byte9(void *, s32, s8);
extern u8 *gSelectState;
extern u8 D_800A5F7C[];
extern u8 D_800A5F8C[];
extern u8 *gLeague;
typedef struct 
{
  u8 pad0[0x32];
  u8 idx[0x16];
  struct 
  {
    u8 pad[6];
    u8 b6;
    u8 b7;
    u8 pad2[0x20];
  } e[4];
} RS;
extern u8 *gRecords;
extern u8 *D_800D0658;
static inline s16 normalize_field(s32 x) { x=(u32)x<<16; x=(s32)x>>16; return x; }

/* Rebuilds the per-slot entry lists for the four slots of the current car: drops entries
   whose flag bit 8 is set (unlinking them and releasing the node), renumbers the rest,
   refreshes the slot counters, and updates the HUD object's state. */
void func_8007A29C(void)
{
  u8 *car_tbl;
  u8 *entry;
  u8 *counts;
  u8 *slots;
  u8 *ctx;
  u8 *state;
  u8 *node;
  u8 *prev;
  u8 *list;
  u8 *idx_ptr;
  u8 *cnt_ptr;
  u16 y_off;
  s8 i;
  s8 j;
  s32 n;
  u8 t;
  stream_free_all_blocks();
  select_clear_slots();
  func_8005BB5C();
  i = 0;
  B(gSelectState, 0x22B) = B(gSelectState, 0x228);
  t = ((RS *) gRecords)->e[((RS *) gRecords)->idx[(s8) B(gSelectState, 0x228)]].b7;
  B(gSelectState, 0x237) = t;
  ctx = gLeague;
  entry = P(ctx, 0x10) + (SH(ctx, 2) * 0x14);
  B(gSelectState, 0x238) = H(D_800D0658 + (t * 0x2C4), 0x14);
  state = gSelectState;
  counts = state + 0x23D;
  car_tbl = D_800D0658;
  slots = state + 0x241;
  B(state, 0x23D) = 4;
  B(state, 0x23E) = 8;
  B(state, 0x23F) = 4;
  B(state, 0x240) = 4;
  B(state, 0x241) = 0;
  B(state, 0x242) = 4;
  B(state, 0x243) = 0xC;
  B(state, 0x244) = 0x10;
  do
  {
    list = select_get_entry(i);
    node = P(list, 0x28);
    j = 0;
    n = counts[i];
    y_off = H(node, 8);
    prev = 0;
    if (n > 0)
    {
      idx_ptr = slots + i;
      cnt_ptr = counts + i;
      do
      {
        B(node, 0x22) = (*idx_ptr) + j;
        if (H(car_tbl + ((((s8) (*idx_ptr)) + j) * 0x2C4), 0x10) & 8)
        {
          if (prev == 0)
          {
            prev = node;
            node = P(node, 0);
            P(list, 0x28) = node;
            heapFreeBlock(prev);
            prev = 0;
          }
          else
          {
            P(prev, 0) = P(node, 0);
            heapFreeBlock(node);
            node = P(prev, 0);
          }
          do
          {
            *cnt_ptr -= 1;
            B(list, 0x4C) -= 1;
          }
          while (0);
        }
        else
        {
          H(node, 8) = normalize_field(y_off);
          y_off += 0x14;
          prev = node;
          node = P(node, 0);
        }
        j++;
      }
      while (j < n);
    }
    if (counts[i] == 0)
    {
      B(select_get_entry(i), 0x41) = 0;
      record_set_byte9(gLeague, (B(P(gLeague, 0x10) + (SH(gLeague, 2) * 0x14), 0xD) + i) & 0xFFFF, 0);
      if (B(gSelectState, 0x238) == i)
      {
        {
          u8 *rs = gRecords;
          rs += (rs + ((s8) B(gSelectState, 0x228)))[0x32] * 40;
          H(rs, 0x4E) = 4;
        }
        B(gSelectState, 0x238) = H(D_800D0658, 0xB24);
      }
    }
    func_8005937C(B(entry, 0xD) + i, counts[i]);
    i++;
  }
  while (i < 4);
  {
    u8 *a2 = P(gLeague, 0x10);
    s32 m2 = B(gSelectState, 0x238);
    B(a2 + (SH(gLeague, 2) * 0x14), 0xE) = B(a2 + (SH(gLeague, 2) * 0x14), 0xD) + m2;
    func_80069974();
  }
  B(gSelectState, 0x2BD) = 1;
  resolve_path(D_800A5F7C);
  func_8004C7F0(D_800A5F8C);
  node = textObjGet(0x38);
  H(node, 4) = ((*((s8 *) (gSelectState + 0x228))) == 0) ? (3) : (0x98);
}