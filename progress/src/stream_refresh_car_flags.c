extern u8 stream_state[];

#define CAR_STRIDE       0x2C4
#define CAR_FLAG_OFF     0x2140
#define SLOT_FLAG_OFF    0x1E7C
#define CAR_ALT_FLAG_OFF 0x2C50
#define FLAG_BIT_8       8

/* Sets or clears bit 8 in the 16-bit flags of the four car records and of two
   related records, from the control flags (bit i of the car mask, 0x20 for the
   slot record, 0x10 for the alternate records). */
void stream_refresh_car_flags(void) {
    u8 *cars;
    u32 flags;
    s32 bit;
    u8 i;

    cars = *(u8 **)(stream_state + 0x103AA);
    flags = *(*(u8 **)(stream_state + 0x32F2) + 0x2F);

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if ((flags & bit) == bit) {
            *(u16 *)(cars + i * CAR_STRIDE + CAR_FLAG_OFF) &= ~FLAG_BIT_8;
        } else {
            *(u16 *)(cars + i * CAR_STRIDE + CAR_FLAG_OFF) |= FLAG_BIT_8;
        }
    }

    if (flags & 0x20) {
        *(u16 *)(cars + SLOT_FLAG_OFF) &= ~FLAG_BIT_8;
    } else {
        *(u16 *)(cars + SLOT_FLAG_OFF) |= FLAG_BIT_8;
    }

    if (flags & 0x10) {
        for (i = 0; i < 4; i++) {
            *(u16 *)(cars + i * CAR_STRIDE + CAR_ALT_FLAG_OFF) |= FLAG_BIT_8;
        }
        return;
    }

    for (i = 0; i < 4; i++) {
        *(u16 *)(cars + i * CAR_STRIDE + CAR_ALT_FLAG_OFF) |= FLAG_BIT_8;
    }
}
