/* Sets the +0x41 flag byte of the select list's head node (the node at select_get_entry(index)) to 1. */
extern void *select_get_entry(u32 index);

void select_set_head_flag(u32 index) {
    ((s8 *)select_get_entry(index))[0x41] = 1;
}
