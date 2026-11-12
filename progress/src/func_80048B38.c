extern u8 stream_state[];
extern u8 gOrderState[];
extern u8 D_800A4E4C[];
extern u8 D_800A4E50[];
s32 func_8000A188(void *, void *, s32, s32, s32);
s32 getTexturePack(void *, s32);
void *find_object_by_id(s32);
void *listAppendDefaultNode(void *, s32, void *);
s32 strCmp(void *, void *);

/* For each entry of the per-object list (count from the table at stream_state), reads the entry's name
 * and stores the object's value into the matching slot (the "A" or "B" list, chosen by name), then
 * sends the update to the object found by id. obj is the object being updated. */
void func_80048B38(u8 *obj)
{
    u8 *name_ptr;
    u8 *slot;
    u8 *entry;
    u8 *name;
    s32 value;
    s32 obj_id;
    u32 idx;
    u32 count;
    u8 count8;

    name_ptr = obj;
    slot = NULL;
    count8 = *(u8 *)(*(u8 **)&stream_state[0x32F2] + 0xF);
    entry = **(u8 ***)&gOrderState[0x6D94];
    idx = 1;
    if (count8 != 0) {
        name = name_ptr + 0x4C;
        count = count8;
        obj_id = 1;
        do {
            value = getTexturePack(name_ptr + 0x98, 0);
            if (strCmp(name, D_800A4E4C) == 0) {
                slot = listAppendDefaultNode(entry + 0xC, 0, name_ptr);
                *(s32 *)(entry + 0x40) = *(s32 *)(name_ptr + 0x128);
            } else if (strCmp(name, D_800A4E50) == 0) {
                slot = listAppendDefaultNode(entry + 0x44, 1, name_ptr);
                *(s32 *)(entry + 0x78) = *(s32 *)(name_ptr + 0x128);
            }
            *(s32 *)(slot + 0xC) = value;
            func_8000A188(*(void **)((u8 *)find_object_by_id(obj_id) + 0x178), slot, *(name_ptr + 0x12B), 0, 0);
            obj_id += 2;
            idx += 1;
            entry = *(u8 **)(entry + 4);
        } while (count >= idx);
    }
}
