/* Reads a big-endian u16 from the stream into obj+0xAA, clears obj+0xAC, and returns the stream past the two bytes. */ /* identical to func_8008D4DC in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to read_be16_field_aa in V-RALLY (matched), with its names changed by decompdecomp */

unsigned char *read_be16_field_aa(char *obj, unsigned char *src) { unsigned int b0 = *src++; unsigned int b1 = *src; *(short *)(obj + 0xAC) = 0; *(short *)(obj + 0xAA) = b1 | (b0 << 8); return src + 1; }
