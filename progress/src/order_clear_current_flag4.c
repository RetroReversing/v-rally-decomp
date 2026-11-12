extern u8 gOrderState[];

/* Clears flag bit 0x4 in the flags word (+0xC) of the current order's object, when there is one. */
void order_clear_current_flag4(void) {
    u8 *obj = *(u8 **)(gOrderState + 0x18);
    if (obj != NULL) {
        *(s32 *)(obj + 0xC) &= ~4;
    }
}
