extern u8 gOrderState[];
extern u8 gStreamState[];
s32 func_8000EC94(void *, void *, void *);
s32 func_80047F3C(void *, s32);

#define CD6_178 (*(u8 **)(*(u8 **)(gStreamState + 0x7CD6) + 0x178))

/* Draws the highlight box around the current view when the active screen is type 5, otherwise runs
 * func_80047F3C over the linked list of entries, numbering them from 1. */
void func_800489D8(void)
{
    u16 box[4];
    u8 col[3];
    u8 *entry;
    s32 i;

    if (*(u16 *)(*(u8 **)(gStreamState + 0x7E6E) + 4) == 5) {
        box[0] = *(u16 *)(CD6_178 + 8);
        box[1] = *(u16 *)(CD6_178 + 0xA);
        box[2] = *(u16 *)(CD6_178 + 0xC);
        box[3] = *(u16 *)(CD6_178 + 0xE);
        if (*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0xE) == 2 && (*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x12) & 1)) {
            box[0] += 0x20;
            box[2] -= 0x20;
        }
        col[0] = 0xCC;
        col[1] = 0xCC;
        col[2] = 0xCC;
        func_8000EC94(CD6_178, box, col);
        return;
    }
    entry = *(u8 **)(*(u8 **)(gOrderState + 0x6D94));
    if (entry != NULL) {
        i = 1;
        do {
            func_80047F3C(entry, i & 0xFF);
            entry = *(u8 **)(entry + 4);
            i++;
        } while (entry != NULL);
    }
}
