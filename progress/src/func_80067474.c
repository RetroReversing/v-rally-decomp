typedef struct { u8 pad0[2]; u16 index; u8 pad4[12]; u8 *items; } Table;
typedef struct { u8 pad0[0x228]; s8 name_cursor; u8 pad229[0x1C]; u8 mode; u8 pad246[0x42]; void (*on_update)(void); void (*on_draw)(void); } Obj;
typedef struct { u8 pad0[0x2C]; s32 status; } Entry;
extern Obj *gSelectState;
extern u8 *gSlotState;
extern Table *gLeague;
extern void select_copy_entry_label(s32, s32);
extern void select_init_entry_handlers(s32, s32);
extern void func_800679D8(void);
extern void draw_name_entry_wheel(void);

/* Checks the four name letters of the current record; if any is out of range,
   puts the name cursor on the first bad letter and sets the entry to state 2,
   otherwise sets the entry to state 3 and resets the select handlers. */
s32 func_80067474(s32 menu, s32 slot)
{
  s8 bad_count = 0;
  s8 first_bad = -1;
  s8 i = 0;
  u8 *name;
  u16 row;
  u8 *entries;
  Entry *entry;

  gSelectState->mode = 0;
  name = gSlotState + 0x44;
  row = gLeague->index;
  do {
    if (name[i * 0x28] >= 0x5B) {
      bad_count++;
      if (first_bad < 0) first_bad = i;
    }
    i++;
  } while (i < 4);
  if (bad_count != 0) {
    gSelectState->name_cursor = first_bad;
    select_copy_entry_label(menu, slot);
    gSelectState->on_update = func_800679D8;
    gSelectState->on_draw = draw_name_entry_wheel;
    entries = gLeague->items;
    entries = *(u8 **)(entries + row * 20 + 8);
    entry = *(Entry **)(entries + slot * 12 + 4);
    entry->status = 2;
  } else {
    entries = gLeague->items;
    entries = *(u8 **)(entries + row * 20 + 8);
    entry = *(Entry **)(entries + slot * 12 + 4);
    entry->status = 3;
    select_init_entry_handlers(3, 3);
  }
  return 0;
}
