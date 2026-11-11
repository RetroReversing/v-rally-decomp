extern short D_8009E2AC[];
short wave_table_get_mirrored(short arg0) { return D_8009E2AC[(0x100 - arg0) & 0x3FF]; }
