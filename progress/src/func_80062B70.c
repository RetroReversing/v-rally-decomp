void *select_get_entry(u32);
void slot_set_selected(s32, s32);
extern s32 gSelectStep;
extern void *gRecords;

/* Updates the menu selections from the records. In mode 2 it first nudges the first three
 * entries of list 3 down by 0x10, then sets list 2 from record byte 0x30 and list 3 from the
 * record's state words at 0xE, 0x18 and 0x1A. */
void func_80062B70(void) {
    s32 i;
    void *item;
    void *rec;

    if (gSelectStep == 2) {
        item = *((void **)(((char *)select_get_entry(3)) + 0x28));
        i = 0;
        do {
            i += 1;
            *((u16 *)(((char *)item) + 6)) += 0x10;
            item = *((void **)item);
        } while ((u8)i < 3);
    }
    slot_set_selected(2, ((u8 *)gRecords)[0x30]);
    rec = gRecords;
    if (*((u16 *)(((char *)rec) + 0xE)) == 1) {
        if (*((s32 *)(((char *)rec) + 0x18)) == 0x10001) {
            slot_set_selected(3, 1);
        } else {
            *((u16 *)(((char *)rec) + 0x18)) = 0;
            *((u16 *)(((char *)rec) + 0x1A)) = 1;
            slot_set_selected(3, 0);
        }
    } else {
        if (*((u16 *)(((char *)rec) + 0x18)) != 0) {
            slot_set_selected(3, 1);
        } else {
            slot_set_selected(3, (*((u16 *)(((char *)rec) + 0x1A)) == 0) * 2);
        }
    }
}
