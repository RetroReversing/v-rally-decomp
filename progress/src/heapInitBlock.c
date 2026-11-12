/* Initialises a heap block of the given size: a header at the start and a 0x14-byte end marker at the end, both linked to each other. */
void heapInitBlock(void *block, s32 size) {
    void *end;

    end = (char *)block + size;
    end = (char *)end - 0x14;
    *(void **)((char *)block + 0) = end;
    *(s32 *)((char *)block + 4) = 0;
    *(s8 *)((char *)block + 8) = 1;
    *(s8 *)((char *)block + 0xA) = 0;
    *(s8 *)((char *)block + 0xB) = 0;
    *(s32 *)((char *)block + 0x10) = 0;
    *(s32 *)((char *)end + 0) = 0;
    *(void **)((char *)end + 4) = block;
    *(s8 *)((char *)end + 8) = 1;
    *(s8 *)((char *)end + 0xA) = 1;
    *(s8 *)((char *)end + 0xB) = 0;
}
