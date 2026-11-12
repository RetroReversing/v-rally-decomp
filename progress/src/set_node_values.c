/* Stores two values into the sub-record reached through node->0x10->0x14 (offsets 0x8 and 0xC). */
void set_node_values(void *node, s32 value0, s32 value1)
{
    *(s32 *)((s8 *)*(void **)((s8 *)*(void **)((s8 *)node + 0x10) + 0x14) + 8) = value0;
    *(s32 *)((s8 *)*(void **)((s8 *)*(void **)((s8 *)node + 0x10) + 0x14) + 0xC) = value1;
}
