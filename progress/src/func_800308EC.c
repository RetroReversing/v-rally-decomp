/* Scans a grid of 16-bit cells for pairs of cells equal to `key` and returns a code for the
 * winning side: 1 for a clear majority, 2 or 3 when one side has at least two hits. */
s32 func_800308EC(u8 *grid, s32 key) {
    s32 rows; u32 rowLimit, key16, colCount, rowEnd; u8 *obj2; u32 row; u8 hitsBelow, hitsAbove;
    u32 colStart, colSpan, rowBase; u32 pad[2];
    u32 result;
    result = 0; hitsBelow = 0; hitsAbove = 0; row = 0;
    rows = *(u16*)(grid + 0x88) - 1;
    if (rows != 0) {
        colCount = *(u32*)(grid + 0x4C); key16 = key & 0xFFFF; rowLimit = rows; rowEnd = colCount + 2; rowBase = colCount;
        do {
            colStart = rowBase - 2; obj2 = grid;
            if (colStart < rowEnd) {
                do {
                    if (colStart < rowBase) {
                        if (((u16*)*(u8**)(grid + 0x70))[colStart + row * (*(u16*)(grid + 0x8A) - 1)] == key16) hitsBelow++;
                    }
                    else if (((u16*)*(u8**)(grid + 0x70))[colStart + row * (*(u16*)(grid + 0x8A) - 1)] == key16) {
                        do { hitsAbove++; } while (0);
                    }
                    rows = *(u32*)(grid + 0x4C); rowBase = rows; colStart++;
                } while (colStart < rowBase + 2);
            }
            row++; rowBase = colCount;
        } while (row < rowLimit);
    }
    if (hitsBelow >= 2 || hitsAbove >= 2) {
        result = 1;
        if (!(hitsAbove < hitsBelow)) { hitsBelow = (-(hitsBelow < hitsAbove) & 3) | 2; result = hitsBelow; }
    }
    return result;
}
