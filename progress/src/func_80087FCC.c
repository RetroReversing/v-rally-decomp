/* Reads an index byte from src, looks it up in the table at obj->+0x70's +0x14 pointer,
 * and stores the resulting address in obj+0x7C. Returns src advanced by one byte. */
unsigned char *func_80087FCC(char *obj, unsigned char *src) {
    char *b = *(char **)(obj + 0x70);
#ifdef PORT
    *(char **)(obj + 0x7C) = b + (*(int **)(b + 0x14))[*src];
#else
    *(int *)(obj + 0x7C) = (int)b + (*(int **)(b + 0x14))[*src];
#endif
    return src + 1;
}
