extern s32 D_8009D6B0;

/* Runs the per-entry update callbacks of obj until the entry list ends or obj's stop flag is set,
 * then clears the global D_8009D6B0 if obj's reset flag (bit 1) is set. */
void func_80022F98(s32 *obj) {
    s32 *list;
    s32 entry;
    s32 end;
    s32 *cursor;

    list = (s32 *)obj[0];
    obj[2] &= ~1;
    entry = *(s32 *)((u8 *)list + 0xA0);
    if (entry != -1) {
        end = -1;
        cursor = list;
        do {
            void (*fn)(void *) = *(void (**)(void *))(*(u8 **)(*(u8 **)obj + 0xD0) + entry * 0x1C + 0x14);
            fn(obj);
            cursor += 1;
            entry = *(s32 *)((u8 *)cursor + 0xA0);
            if (entry == end) {
                break;
            }
        } while (!(obj[2] & 1));
    }
    if (obj[2] & 2) {
        D_8009D6B0 = 0;
        obj[2] &= ~2;
    }
}
