extern char gStreamState[];
extern u8 gTimeModeChars[];
void format_time_text(s32 a0, void *a1);

/* Updates a time display object. When the current record has flag 0x100, sets flag 4 on
 * the display. When the display's digit index is 0, formats the race time into the
 * display. Then stores the digit at that index, as a number, in the display. */
void update_time_display(void *arg0) {
    u8 *disp;
    u8 *rec;
    s32 time;
    s32 off;
    s32 base;

    rec = *(u8 **)(*(u8 **)(gStreamState + 0x7CD6) + 0x24);
    if (rec != 0) {
        disp = arg0;
        base = *(s32 *)(*(u8 **)(rec + 0x6C) + 0x14);
        off = (*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x22) << 6) + 0x2C;
        time = *(s32 *)(base + off);
        if (*(s32 *)(rec + 0x14) & 0x100) {
            *(s32 *)(disp + 0x80) |= 4;
        }
        if (*(u16 *)(disp + 0x78) == 0) {
            format_time_text(time, gTimeModeChars);
        }
        *(s16 *)(disp + 0x7A) = gTimeModeChars[*(u16 *)(disp + 0x78)] - 0x30;
    }
}
