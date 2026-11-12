/* Looks up a wave table entry at a quarter-wave mirrored index (0x100 - index), wrapped to 0x400 entries. */
extern s16 D_8009E2AC[];

s16 wave_table_get_mirrored(s16 index) {
    return D_8009E2AC[(0x100 - index) & 0x3FF];
}
