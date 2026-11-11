/* Adds a fixed per-index offset (0, 7, 13, 19, 25, 31, 38, 45 for index 0..7) to `value`
 * and returns the result. Indexes outside 0..7 return `value` unchanged. */
u8 func_8006B9E0(u8 index, u8 value) {
    switch (index) {
    case 0:
        break;
    case 1:
        value += 7;
        break;
    case 2:
        value += 13;
        break;
    case 3:
        value += 19;
        break;
    case 4:
        value += 25;
        break;
    case 5:
        value += 31;
        break;
    case 6:
        value += 38;
        break;
    case 7:
        value += 45;
        break;
    }
    return value;
}
