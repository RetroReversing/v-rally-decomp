extern s32 *gSoundState;

/* Fills every 3rd word of the table at gSoundState with the entry IDs for the selected set (2, 3, or 0/1 in the default path). Unknown sets do nothing. */
void setSoundEntryTable(s32 setId)
{
    s32 set;
    s32 *tbl;

    set = setId & 0xFF;
    if (set == 2) {
        goto block_6;
    }
    if (set < 3) {
        goto block_4;
    }
    if (set == 3) {
        goto block_7;
    }
    return;
block_4:
    if (set < 0) {
        return;
    }
    tbl = gSoundState;
    tbl[0] = 8;
    tbl[3] = 9;
    tbl[6] = 0xA;
    tbl[9] = 0xB;
    tbl[12] = 0xC;
    tbl[15] = 0xE;
    tbl[18] = 0xF;
    tbl[51] = 0x1F;
    tbl[54] = 0x20;
    tbl[57] = 0x21;
    return;
block_6:
    tbl = gSoundState;
    tbl[0] = 0x3B;
    tbl[3] = 0x3C;
    tbl[6] = 0x3D;
    tbl[9] = 0x3E;
    tbl[12] = 0x3F;
    tbl[15] = 0x40;
    tbl[18] = 0x41;
    tbl[51] = 0x42;
    tbl[54] = 0x43;
    tbl[57] = 0x44;
    return;
block_7:
    tbl = gSoundState;
    tbl[0] = 0x31;
    tbl[3] = 0x32;
    tbl[6] = 0x33;
    tbl[9] = 0x34;
    tbl[12] = 0x35;
    tbl[15] = 0x36;
    tbl[18] = 0x37;
    tbl[51] = 0x38;
    tbl[54] = 0x39;
    tbl[57] = 0x3A;
}
