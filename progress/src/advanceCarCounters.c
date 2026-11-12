extern void draw_select_overlay();
extern s32 input_get_buttons(s32);
extern void input_clear_flags(u8, s32);
extern u8 gOrderState[];
extern u8 stream_state[];

/* Walks the car list. For each car whose id is below 4, it reads the car's
 * state flags and, when bit 8 is set and the race mode is 0 or 5 or more (or
 * the 0x8030 state is not 2), it advances the car's counter at +0x34. The
 * counter wraps to 0 at 6. */
void advanceCarCounters(s32 *slot)
{
    s32 id;
    s32 flags;
    u16 mode;
    void *car;
    void *carB;
    void *node;

    draw_select_overlay(*slot);
    node = *(*((void ***) (gOrderState + 0x73F0)));
    if (node != NULL) {
        do {
            id = *(s32 *)(*(void **)((char *)node + 0x48));
            if (id < 4) {
                flags = input_get_buttons(id & 0xFF);
                input_clear_flags(*(u8 *)(*(void **)((char *)node + 0x48) + 3), flags);
                if ((flags & 8) && ((mode = *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x1E)), (((mode == 0) | (mode >= 5U)) != 0) || (*(s32 *)(gOrderState + 0x8030) != 2))) {
                    car = *(void **)((char *)node + 0x9C);
                    *(s32 *)((char *)car + 0x34) = (s32) (*(s32 *)((char *)car + 0x34) + 1);
                }
                carB = *(void **)((char *)node + 0x9C);
                if (*(s32 *)((char *)carB + 0x34) >= 6) {
                    *(s32 *)((char *)carB + 0x34) = 0;
                }
            }
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
}
