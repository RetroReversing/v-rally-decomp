/* Runs the handler of each entry listed at obj+0xA0 (s32 indices, ended by -1).
 * Each index selects a 0x1C-byte record in the handler table at obj+0xD0, and
 * that record's handler is called with obj. */
void func_80022E64(void *obj)
{
    int end_marker;
    s32 slot_index;
    char *obj_bytes;
    void *slot_cursor;

    slot_index = *((s32 *) (((char *) obj) + 0xA0));
    if (slot_index != (-1))
    {
        end_marker = -1;
        slot_cursor = obj;
        do
        {
            obj_bytes = (char *) obj;
            slot_cursor += 4;
#ifdef PORT
            {
                void *tbl = *(void **)(obj_bytes + 0xD0);
                s32 (*fn)(void *) = *(s32 (**)(void *))((char *)tbl + slot_index * 0x1C + 0x18);
                fn(obj);
            }
#else
            (*((s32 (**)(void *)) (((char *) ((slot_index * 0x1C) + (*((s32 *) (obj_bytes + ((unsigned long) 0xD0)))))) + 0x18)))(obj);
#endif
            slot_index = *((s32 *) (((char *) slot_cursor) + 0xA0));
        }
        while (slot_index != end_marker);
    }
}
