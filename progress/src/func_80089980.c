extern u8 gGameState[];
extern u8 gOrderState[];

/* Resets the print/state block: clears four words at +0x4598 and two at +0x4590, then sets the word at gOrderState+0x1204 to 0x80. */
void func_80089980(void) {
    register u8 i;
    u32 *p;
    i = 0;
    p = (u32 *)((u8 *)gGameState + 0x4598);
    do {
        p[i] = 0;
        i++;
    } while (i < 4);
    *(u32 *)((u8 *)gGameState + 0x4590) = 0;
    *(u32 *)((u8 *)gGameState + 0x4594) = 0;
    *(u32 *)((u8 *)gOrderState + 0x1204) = 0x80;
}
