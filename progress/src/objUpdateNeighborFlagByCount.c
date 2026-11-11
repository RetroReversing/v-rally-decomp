extern unsigned char gCurCount;

/* Compares the neighbour's count (the word at its +0x70 record, plus one) with gCurCount: bit 4 of the object's flags at +0x80 is cleared when gCurCount is above it, set otherwise. */
void objUpdateNeighborFlagByCount(void *object) {
    char * obj = object;
    unsigned int count = **(unsigned int **)(*(char **)(*(char **)(obj + 0xA8) + 0x24) + 0x70) + 1;
    if (count != gCurCount && gCurCount >= count) {
        *(int *)(obj + 0x80) &= ~4;
    } else {
        *(int *)(obj + 0x80) |= 4;
    }
}
