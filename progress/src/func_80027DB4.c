extern char gOrderState[];
extern char gStreamState[];

/* Updates the level stored for channel chan from dir: 0 zeroes it, a positive dir raises it
 * (up to 127) and a negative dir lowers it (down to -128), each step being at least 'step'
 * above or below the stored value. Stores the new level and returns it. */
s8 func_80027DB4(s32 unused, s32 dir, s32 chan) {
    s32 level;
    s32 current;
    s32 step;

    level = *((s32 *)((gStreamState + 0x8062) + ((chan & 255) * 4)));
    if (level >= 151) {
        level = 25;
        step = 20;
    } else if (level >= 101) {
        level = 30;
        step = 20;
    } else {
        level = 35;
        step = 20;
    }
    if (dir == 0) {
        level = 0;
    } else if (dir > 0) {
        current = *((s32 *)((gOrderState + 0x58F8) + ((chan & 255) * 4)));
        if (current >= level) {
            level = current + step;
        }
        if (level >= 128) {
            level = 127;
        }
    } else if (dir < 0) {
        current = *((s32 *)((gOrderState + 0x58F8) + ((chan & 255) * 4)));
        level = -level;
        if (level >= current) {
            level = current - step;
        }
        if (level < (-128)) {
            level = -128;
        }
    } else {
        level = 0;
    }
    *((s32 *)((gOrderState + 0x58F8) + ((chan & 255) * 4))) = level;
    return level;
}
