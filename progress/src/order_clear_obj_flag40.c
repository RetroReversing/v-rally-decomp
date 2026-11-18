extern char gOrderState[];

/* Clears flag bit 0x40 in the flags word of the object held by the order slot, if any. */
void order_clear_obj_flag40(void) {
    char *obj = *(char **)(gOrderState + 0x8A28);
    if (obj != NULL) {
        *(s32 *)(obj + 0x80) &= ~0x40;
    }
}
