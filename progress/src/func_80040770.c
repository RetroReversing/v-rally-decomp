void order_state_init();
void func_8001B68C();
void func_8001B614();
void streamCtlReset();
extern char gOrderState[];
extern char gStreamState[];

/* Re-initialises the order and stream state, then clears the 16-bit fields at
 * gStreamState+0x6C62 and gOrderState+0x7302. */
void func_80040770(void) {
    order_state_init();
    func_8001B68C();
    func_8001B614();
    streamCtlReset();
    *(s16 *)(gStreamState + 0x6C62) = 0;
    *(s16 *)(gOrderState + 0x7302) = 0;
}
