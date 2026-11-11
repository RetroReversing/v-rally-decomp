s32 select_set_active_sub();
extern char gStreamState[];

/* Steps the active select-screen counter at +0x22 down by one. When it is zero, the start value
 * comes from the group count at +0x1E and the entry index at +0x20 (0x2C4-byte entries). Then
 * selects the new counter value and returns 0. */
s32 func_800718F4(s32 arg0)
{
    char *p;
    s32 v;

    p = *((char **)(gStreamState + 0x32F2));
    if (*((u16 *)(p + 0x22)) == 0) {
        v = *((u16 *)(*((char **)(gStreamState + 0x10386 + *((u16 *)(p + 0x1E)) * 4)) + *((u16 *)(p + 0x20)) * 0x2C4 + 0x14));
    } else {
        v = *((u16 *)(p + 0x22));
    }
    *((u16 *)(p + 0x22)) = v - 1;
    select_set_active_sub(arg0, *((u16 *)(*((char **)(gStreamState + 0x32F2)) + 0x22)));
    return 0;
}
