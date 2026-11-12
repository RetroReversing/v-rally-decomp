/* Ors the low 16 bits of flags into the node's flag word (offset 0x14), keeping existing bits. */
void setNodeFlags(void *node, s32 flags) {
    *(s32 *)((s8 *)node + 0x14) = (s32) (*(s32 *)((s8 *)node + 0x14) | (flags & 0xFFFF));
}
