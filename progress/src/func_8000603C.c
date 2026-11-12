/* Returns how many 8-byte entries lie between the begin and end pointers stored at offsets 0x10 and 0x14 of arg0. */
s32 func_8000603C(void *arg0) {
    return (s32) (*(s32 *)((s8 *)arg0 + 0x14) - *(s32 *)((s8 *)arg0 + 0x10)) >> 3;
}
