extern char gOrderState[];
extern char gStreamState[];
s32 camera_set_target_for_slot(void *, u8);
void func_8001CFD0(void *arg0);

/* For each active slot (1..count, from the stream state), points the camera at it and
   runs func_8001CFD0 on the object. Slot 1 is always handled; the rest only when the
   object's mode (+0x90) is not 0 or 3. */
void camera_update_slots(void *obj)
{
    u8 slot_count;
    u32 slot;
    s32 flag;
    s32 mode;

    slot_count = *(u8 *)(*(char **)(gStreamState + 0x32F2) + 0xF);
    mode = *(s32 *)((char *)obj + 0x90);
    for (slot = 1; slot <= slot_count; slot++) {
        if (slot < 2 || (mode != 0 && mode != 3)) {
            *(s32 *)(gOrderState + 0x252C) = camera_set_target_for_slot(obj, slot);
            func_8001CFD0(obj);
        }
    }
}
