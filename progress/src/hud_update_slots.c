extern int g_camera;
s32 func_8003C968();
s32 layout_slot_buttons();
s32 hudAddLabels();
s32 func_8003D8F4();
s32 func_8003D9C8();
s32 func_8003E1BC();
s32 func_8003E3E0();
s32 add_gray_label_rows();
s32 find_object_by_id();
extern void *gRecords;
static inline static static static static static static static char *inline_fn(s32 arg0)
{
  return (char *) (gRecords + arg0);
}

static inline static static char *inline_fn2(char *arg0, int arg1)
{
  return arg0 + arg1;
}

/* Draws the HUD for every slot of the current record block: slots 1..mode each get their labels, buttons and digits according to the flag bits of their record entry. */ void hud_update_slots(s32 arg0, s32 arg1)
{
  int mask4;
  s32 slot_u16;
  s32 slot_masked;
  s32 slot_idx;
  s32 slot;
  void *entry_b;
  int entry_off;
  u16 n_slots;
  int kind_off;
  u16 state;
  void *rec;
  char *entry_ptr;
  void *rec_b;
  void *entry;
  s32 obj;
  rec = gRecords;
  if ((*((u16 *) inline_fn2((char *) rec, 0x1E))) != 7)
  {
    n_slots = *((u16 *) inline_fn2((char *) rec, 0xE));
    if (n_slots != 0)
    {
      slot = (n_slots | 1) & 1;
      slot_idx = (u16) slot;
      do
      {
        obj = find_object_by_id(((slot_idx - 1) * 2) | 1);
        state = *((u16 *) inline_fn2((char *) rec, 0x1E));
        g_camera = obj;
        if (state == 0)
        {
          if ((*((u8 *) inline_fn2(inline_fn((*((u8 *) inline_fn2(inline_fn(slot_idx), 0x31))) * 0x28), 0x48))) & 4)
          {
            do
            {
            }
            while (0);
            goto block_7;
          }
          goto block_8;
        }
        entry = inline_fn2(gRecords, (4 * (*((u8 *) inline_fn2(inline_fn(slot_idx), 0x31)))) * 10);
        if ((*((u8 *) inline_fn2((char *) entry, 0x48))) & 1)
        {
          block_7:
          hudAddLabels(arg0, arg1, slot_idx);

          block_8:
          slot_u16 = slot & 0xFFFF;

          entry_off = (8 * (*((u8 *) inline_fn2(inline_fn(slot_u16), 0x31)))) * 5;
          if ((*((u8 *) inline_fn2((char *) inline_fn2(gRecords, entry_off), 0x48))) & 1)
          {
            func_8003D8F4(arg0, arg1, slot_u16);
          }
        }
        slot_masked = slot;
        slot_masked = slot_masked & 0xFFFF;
        rec_b = rec;
        entry_ptr = inline_fn(slot_masked);
        entry_b = inline_fn2(gRecords, (*((u8 *) inline_fn2(entry_ptr, 0x31))) * 0x28);
        mask4 = 4;
        if ((*((u8 *) inline_fn2((char *) entry_b, 0x48))) & mask4)
        {
          func_8003D9C8(arg0, arg1, slot_masked);
        }
        if ((*((u8 *) inline_fn2((char *) inline_fn2(gRecords, (*((u8 *) inline_fn2(inline_fn(slot_masked), 0x31))) * 0x28), 0x48))) & 1)
        {
          layout_slot_buttons(arg0, arg1, slot_masked);
        }
        kind_off = 0x31;
        if ((*((u8 *) inline_fn2((char *) (gRecords - (-((*((u8 *) inline_fn2(inline_fn(slot_masked), 0x31))) * 0x28))), 0x48))) & 4)
        {
          add_gray_label_rows(arg0, arg1, slot_masked);
        }
        if ((*((u8 *) inline_fn2(inline_fn(10 * (4 * (*((u8 *) inline_fn2(inline_fn(slot_masked), 0x31))))), 0x48))) & 1)
        {
          func_8003E3E0(arg0, arg1, slot_masked);
        }
        if ((*((u8 *) inline_fn2(inline_fn((*((u8 *) inline_fn2(inline_fn(slot_masked), kind_off))) * 0x28), 0x48))) & 4)
        {
          func_8003E1BC(arg0, arg1, slot_masked);
        }
        state = *((u16 *) inline_fn2((char *) rec_b, 0x1E));
        if ((state != 5) & (state != 0))
        {
          func_8003C968(arg0, arg1, slot_masked);
        }
        slot += 1;
        slot_idx = (s32) ((u16) slot);
      }
      while (n_slots >= ((u32) (slot & 0xFFFF)));
    }
  }
}

