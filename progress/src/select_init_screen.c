extern s8 *gSelectState;
extern char gStreamState[];

void select_clear_slots(void);
void func_8005BB5C(void);
s32 func_8008A0D8(s32, s32, s8);
void *select_get_entry(u32);
void select_propagate_values(s32, u32, u32);

/* Select-screen setup: clears the slot table, fills the four slot names, and when the
 * stream's mode word at +0xE is below 2, primes the first entry before resetting the
 * screen flags in gSelectState. */
void select_init_screen(void) {
    select_clear_slots();
    func_8005BB5C();
    if (*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0xE) < 2U) {
        func_8008A0D8(*(s32 *)(gStreamState + 0x325A), 1, 0);
        ((s8 *)select_get_entry(1))[0x41] = 0;
        select_propagate_values(1, 1, *(u32 *)(gSelectState + 0x14));
    }
    gSelectState[0x245] = 0;
    gSelectState[0x228] = 0;
    gSelectState[0x22B] = -1;
}
