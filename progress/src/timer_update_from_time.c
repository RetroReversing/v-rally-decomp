s32 formatRecordTime(s32, u8 *);
extern u8 gTimeText[];

/* Updates a timer object from a record time: when the time is set, formats it into gTimeText and stores the digit at the current position, otherwise flags the timer as stopped. */
void timer_update_from_time(u8 *timer, s32 time) {
    s32 digit;

    if (time != 0) {
        if (*(u16 *)(timer + 0x78) == 0) {
            formatRecordTime(time, gTimeText);
            digit = gTimeText[*(u16 *)(timer + 0x78)] - 0x30;
            *(s32 *)(timer + 0x80) &= ~4;
            *(s8 *)(timer + 0x94) = 0;
            *(s16 *)(timer + 0x7A) = digit;
        } else {
            *(s32 *)(timer + 0x80) &= ~4;
            *(s8 *)(timer + 0x94) = 0;
            *(s16 *)(timer + 0x7A) = gTimeText[*(u16 *)(timer + 0x78)] - 0x30;
        }
    } else {
        *(s32 *)(timer + 0x80) |= 4;
    }
}
