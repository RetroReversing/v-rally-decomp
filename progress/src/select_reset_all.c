void selectStateReset(s32);
void selectStateSetOrder(s32, s32);

/* Resets the select state, then sets the order state to 0 with no keep flag. */
s32 select_reset_all(void) {
    selectStateReset(0);
    selectStateSetOrder(0, 0);
    return 0;
}
