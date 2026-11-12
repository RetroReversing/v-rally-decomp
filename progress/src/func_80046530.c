u32 getCounterValue();
void voice_queue_add_slot(s32);
s32 func_80046414();
s32 func_800464B0();
extern s32 gPadFlags;
extern char stream_state[];
typedef struct 
{
  s32 pad0[4];
  s32 a10;
  s32 a14;
  u32 a18;
  void *a1C;
} Sub70;

/* Handles an event record `evt` for object `obj`. Skipped when the global flags
 * or the object's own flags say so. Otherwise, if `obj` is eligible and the event
 * has a higher priority than the current owner of its sub-slot (the owner is
 * `slot->a1C`), the event claims the slot and its sounds are queued. Clears the
 * claim when the object has no event flag set. */
void func_80046530(u8 *evt, s32 arg1, u8 *obj)
{
  u32 evt_type_w;
  s32 evt_type2;
  char *cfg_slot;
  unsigned int max_prio;
  u32 obj_score;
  u32 evt_type;
  int slot_off;
  u32 prio_mask;
  u32 is_special;
  Sub70 *slot;
  void *owner;
  if (gPadFlags & 0x800)
  {
    return;
  }
  if ((*((s32 *) (obj + 0x14))) & 0x80)
  {
    return;
  }
  obj_score = getCounterValue(obj);
  max_prio = 100U;
  if ((*(*((s32 **) (obj + 0x48)))) >= 2)
  {
 return; }
  if (func_800464B0(obj) == 0)
  {
    return;
  }
  slot_off = 0x14;
  if (!((*((s32 *) (obj + slot_off))) & 0x20))
  {
    slot = *((Sub70 **) (obj + 0x70));
    owner = slot->a1C;
    cfg_slot = stream_state + 0x32F2;
    if (((owner != evt) && ((prio_mask = (0U - ((u32) (owner != 0))) & max_prio, prio_mask >= slot->a18))) && ((((*((s32 *) evt)) & 0xFFFF0000) != 0x06060000) | (obj_score >= 0x50U)))
    {
      evt_type = *((s32 *) (evt + 4));
      is_special = (evt_type != 1) & (evt_type != 5);
      if (is_special)
      {
        if (evt_type == 2)
        {
          slot->a14 = evt[2];
          (*((Sub70 **) (obj + 0x70)))->a10 = evt[3];
        }
        else
        {
          slot->a14 = evt[0];
          (*((Sub70 **) (obj + 0x70)))->a10 = evt[1];
        }
        is_special = 0x7D;
        (*((Sub70 **) (obj + 0x70)))->a18 = is_special;
      }
      else
      {
        slot->a10 = 4;
        (*((Sub70 **) (obj + 0x70)))->a14 = evt[0];
        (*((Sub70 **) (obj + 0x70)))->a18 = 0x7D;
      }
      (*((Sub70 **) (obj + 0x70)))->a1C = evt;
      if ((*((u16 *) ((*((u8 **) cfg_slot)) + 0xE))) < 2U)
      {
        func_80046414(evt[1], evt[0]);
        if ((*((s32 *) (evt + 4))) == 1)
        {
          voice_queue_add_slot(0x13);
          func_80046414(evt[3], evt[2]);
        }
        evt_type2 = *((s32 *) (evt + 4));
        if ((evt_type2 == 2) | (evt_type2 == 5))
        {
          func_80046414(evt[3], evt[2]);
        }
      }
    }
  }
  else
  {
    (*((Sub70 **) (obj + 0x70)))->a1C = 0;
  }
}
