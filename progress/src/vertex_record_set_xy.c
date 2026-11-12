/* Writes x, y and a zero flag into the 16-byte vertex record idx of obj's table at +0x70. */
void vertex_record_set_xy(char *obj, unsigned short idx, short x, short y) {
#ifdef PORT
    char *tbl = *(char **)(obj + 0x70);
    int o = idx << 4;
    *(short *)(tbl + o) = x;
    *(short *)(tbl + o + 2) = y;
    *(short *)(tbl + o + 4) = 0;
#else
    int o = idx << 4; *(short *)(o + *(int *)(obj + 0x70)) = x; *(short *)(o + *(int *)(obj + 0x70) + 2) = y; *(short *)(o + *(int *)(obj + 0x70) + 4) = 0;
#endif
}
