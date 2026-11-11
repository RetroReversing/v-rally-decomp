typedef struct { char pad[8]; void (*cb)(s32, void *); s32 a, b; } CameraEntry;
typedef struct {
  u8 pad[0x90];
  s32 slot;
  u8 pad94[4];
  u8 name[0x174 - 0x98];
  s32 extra;
} CameraSlot;
extern char D_800A0130[];
extern u8 *gRecords;
extern u8 *g_camera;
u8 *find_object_by_id(s32);
CameraEntry *find_entry_by_name(void *, void *);
s32 named_entry_find_or_add(void *, s32, s32, CameraEntry *, s32);

/* Works out which object this slot's camera should follow (slot 3 uses the
 * current mode, other non-zero slots are relative to the player), makes it
 * the camera object, then runs the camera entry for the slot's name and
 * calls its callback if it has one. */
s32 camera_set_target_for_slot(CameraSlot *slot_obj, u8 player)
{
  s32 slot;
  u8 idx;
  u8 *node;
  u8 *target_pos;
  CameraEntry *entry;
  s32 result;
  u16 mode;

  slot = slot_obj->slot;
  idx = slot;
  mode = *(u16 *)(gRecords + 0xE);
  if ((u8)idx == 3) {
    idx = (mode * 2) | 1;
  } else if ((u8)idx != 0) {
    idx = player * 2 - slot;
  }
  node = find_object_by_id(idx);
  target_pos = node + 0x28;
  g_camera = node;
  entry = find_entry_by_name(D_800A0130, slot_obj->name);
  result = named_entry_find_or_add(target_pos, entry->a, entry->b, entry, slot_obj->extra);
  if (entry->cb) {
    entry->cb(result, slot_obj);
  }
  return result;
}
