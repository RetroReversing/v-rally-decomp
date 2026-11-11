s32 func_800595EC();
extern void *gSelectState;
extern char D_800A56F4[];
extern char gStreamState[];
extern s32 select_init_screen;
extern s32 func_80066EBC;

/* Select screen step: while the counter at gSelectState+0x282 is nonzero, decrements it and
 * writes the next byte from the 0x280 table (offset by 3, minus 0x41) to +0x281. When the counter
 * runs out, resets the stream field and installs the select init and update handlers at +0x288 and +0x28C. */
s32 func_800677E8(void)
{
    char *table;
    char *flag;
    int bias;
    u8 remaining;
    u8 next;
    char *handlers;
    table = gSelectState + 0x280;
    remaining = *((u8 *) (((char *) gSelectState) + 0x282));
    if (remaining != 0)
    {
        flag = ((char *) gSelectState) + 0x281;
        next = remaining - 1;
        bias = 0x41;
        *((u8 *) (((char *) gSelectState) + 0x282)) = next;
        *((s8 *) flag) = (s8) ((*((u8 *) (((char *) (table + (next & 0xFF))) + 3))) - bias);
    }
    else
    {
        *((s16 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 2)) = 0;
        func_800595EC(&D_800A56F4);
        *((s32 **) (((char *) gSelectState) + 0x288)) = &select_init_screen;
        handlers = ((char *) gSelectState) + 0x28C;
        *((s32 **) handlers) = &func_80066EBC;
    }
    return 0;
}
