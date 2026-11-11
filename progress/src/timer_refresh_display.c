s32 timer_update_from_time(u8 *timer, s32 time);

/* Refreshes a timer's display from the record it is bound to. If the record's state is 1 the timer is flagged as stopped; otherwise its time is updated and a 4-byte marker is written at +0x90. */
void timer_refresh_display(u8 *timer) {
    u8 *owner;
    u8 *record;
    u8 *state;

    owner = *(u8 **)(timer + 0xA8);
    record = *(u8 **)(owner + 0x24);
    if (record != NULL) {
        state = *(u8 **)(record + 0x6C);
        if (*(s32 *)(state + 8) == 1) {
            *(s32 *)(timer + 0x80) = (s32)(*(s32 *)(timer + 0x80) | 4);
            return;
        }
        timer_update_from_time(timer, *(s32 *)(state + 0xC));
        *(u8 *)(timer + 0x90) = 0xFE;
        *(u8 *)(timer + 0x91) = 0xD5;
        *(s8 *)(timer + 0x92) = 0x1E;
        *(u8 *)(timer + 0x93) = 0xFF;
    }
}
