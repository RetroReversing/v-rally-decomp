extern s32 D_800B5B48;
extern char gOrderState[];
extern char D_800A4E20[];
void select_step_menu();
void func_800447A0();
s32 make_rect_set();
s32 rect_set_set_item_pos();
void rect_set_set_scale(s32, f32, f32, f32);
void *list_find_node(void **, u8 *);
void *named_entry_find_or_add();
void *poolAllocNode();

/* Finds or creates this object's rect-set record (at obj+0x28, from the shared table), then
 * resets its state, stores the rect set id from D_800B5B48, and sets the rect colour. */
void func_800446D0(char *obj) {
    char *rec;
    char *found;
    s32 setId;

    rec = obj + 0x28;
    found = list_find_node((void **)(rec), (u8 *)(D_800A4E20));
    if (found != NULL) {
        goto block_5;
    }
    rec = poolAllocNode(named_entry_find_or_add(rec, select_step_menu, func_800447A0, D_800A4E20, 0), 0x18);
    goto block_6;
block_5:
    rec = *(char **)(*(char **)(found + 0x10));
block_6:
    rec[0xE] = 1;
    rec[0xF] = 0;
    setId = D_800B5B48;
    *(s16 *)(rec + 0xC) = 0;
    *(s32 *)(rec + 0x14) = setId;
    *(s32 *)(rec + 0x10) = make_rect_set(setId);
    rect_set_set_scale(*(s32 *)(rec + 0x10), 1.0f, 1.0f, 1.0f);
    rect_set_set_item_pos(*(s32 *)(rec + 0x10), 0x80, 0x33);
}
