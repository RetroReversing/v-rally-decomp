extern u8 stream_state[];

/* Clears per-cell bits for one map/grid object: a cell is zeroed when its bit is set in
   the cell array (0x70) and the matching flags are not masked out. Cells with the
   tile kind 8 are set to 2. Then the low nibble of each cell is kept. */
void func_80017FA4(u8 *obj)
{
#ifdef PORT
    u16 *skip_mask;
    s32 cell_count;
    s32 off;
    u8 *tile_info;
    s32 limit;
    u16 v;
    s32 kind_match;
    s32 kind_fix;
    s32 width_minus_1;
    s32 height_minus_1;
    u8 *cell;
    u16 *p;

    width_minus_1 = *(u16 *)(obj + 0x8A);
    width_minus_1 -= 1;
    height_minus_1 = *(u16 *)(obj + 0x88);
    height_minus_1 -= 1;
    cell_count = width_minus_1 * height_minus_1;

    if (cell_count > 0) {
        skip_mask = (u16 *)(stream_state + 0x767E);
        tile_info = *(u8 **)(stream_state + 0x32F2);
        kind_match = 8;
        kind_fix = 2;
        off = 0;
        limit = cell_count * 2;
        do {
            if (!(*skip_mask & 0x8000)) {
                cell = *(u8 **)(obj + 0x70) + off;
                if (*(u16*)cell & 0x8000) {
                    *(u16*)cell = 0;
                }
            }
            if (!(*skip_mask & 0x4000)) {
                cell = *(u8 **)(obj + 0x70) + off;
                if (*(u16*)cell & 0x4000) {
                    *(u16*)cell = 0;
                }
            }
            if (!(*skip_mask & 0x2000)) {
                cell = *(u8 **)(obj + 0x70) + off;
                if ((*(u16*)cell & 0x2000) && (*(u32 *)(obj + 0x60) & 0x13)) {
                    *(u16*)cell = 0;
                }
            }
            if (!(*skip_mask & 0x1000)) {
                cell = *(u8 **)(obj + 0x70) + off;
                if ((*(u16*)cell & 0x1000) && (*(u32 *)(obj + 0x60) & 4)) {
                    *(u16*)cell = 0;
                }
            }
            if (*(u16 *)(tile_info + 0x1E) == kind_match) {
                cell = *(u8 **)(obj + 0x70) + off;
                if (*(u16*)cell == 0) {
                    *(u16*)cell = kind_fix;
                }
            }
            p = (u16*)(*(u8 **)(obj + 0x70) + off);
            v = *p;
            off += 2;
            *p = v & 0xF;
        } while (off < limit);
    }
#else
    u16 *skip_mask;
    s32 cell_addr;
    s32 off;
    u8 *tile_info;
    s32 limit;
    u16 v;
    s32 kind_match;
    s32 kind_fix;
    s32 width_minus_1;
    s32 height_minus_1;
    u16 *p;

    width_minus_1 = *(u16 *)(obj + 0x8A);
    width_minus_1 -= 1;
    height_minus_1 = *(u16 *)(obj + 0x88);
    height_minus_1 -= 1;
    cell_addr = width_minus_1 * height_minus_1;

    if (cell_addr > 0) {
        skip_mask = (u16 *)(stream_state + 0x767E);
        tile_info = *(u8 **)(stream_state + 0x32F2);
        kind_match = 8;
        kind_fix = 2;
        off = 0;
        limit = cell_addr * 2;
        do {
            if (!(*skip_mask & 0x8000)) {
                cell_addr = off + *(u32 *)(obj + 0x70);
                if (*(u16*)cell_addr & 0x8000) {
                    *(u16*)cell_addr = 0;
                }
            }
            if (!(*skip_mask & 0x4000)) {
                cell_addr = off + *(u32 *)(obj + 0x70);
                if (*(u16*)cell_addr & 0x4000) {
                    *(u16*)cell_addr = 0;
                }
            }
            if (!(*skip_mask & 0x2000)) {
                cell_addr = off + *(u32 *)(obj + 0x70);
                if ((*(u16*)cell_addr & 0x2000) && (*(u32 *)(obj + 0x60) & 0x13)) {
                    *(u16*)cell_addr = 0;
                }
            }
            if (!(*skip_mask & 0x1000)) {
                cell_addr = off + *(u32 *)(obj + 0x70);
                if ((*(u16*)cell_addr & 0x1000) && (*(u32 *)(obj + 0x60) & 4)) {
                    *(u16*)cell_addr = 0;
                }
            }
            if (*(u16 *)(tile_info + 0x1E) == kind_match) {
                cell_addr = off + *(u32 *)(obj + 0x70);
                if (*(u16*)cell_addr == 0) {
                    *(u16*)cell_addr = kind_fix;
                }
            }
            p = (u16*)(off + *(u32*)(obj + 0x70));
            v = *p;
            off += 2;
            *p = v & 0xF;
        } while (off < limit);
    }
#endif
}
