extern char gOrderState[];

/* Finds the entry in the order list (head at gOrderState+0x73F0) whose index (+0x6C record's
 * +8 word) is idx + step, where idx is rec's index. step is +1 when idx is below 2, else -1.
 * Also sets obj's +0xE to the u16 at obj->+0xA8->+0x178->+0xA plus 0x10 (or 6 when step is -1).
 * Returns the matching entry, or NULL. */
void *orderFindNeighbor(void *obj, void *rec)
{
    s16 offset;
    s32 step;
    u32 idx;
    void *node;
    int target;

    idx = *((u32 *)(((char *)(*((void **)(((char *)rec) + 0x6C)))) + 8));
    step = 1;
    if (idx >= 2U)
    {
        step = -1;
        offset = (*((u16 *)(((char *)(*((void **)(((char *)(*((void **)(((char *)obj) + 0xA8)))) + 0x178)))) + 0xA))) + 6;
    }
    else
    {
        offset = (*((u16 *)(((char *)(*((void **)(((char *)(*((void **)(((char *)obj) + 0xA8)))) + 0x178)))) + 0xA))) + 0x10;
    }
    *((s16 *)(((char *)obj) + 0xE)) = offset;
    node = *(*((void ***)(gOrderState + 0x73F0)));
    if (node != NULL)
    {
        target = idx + step;
    loop_5:
        if ((*((s32 *)(((char *)(*((void **)(((char *)node) + 0x6C)))) + 8))) != target)
        {
            node = *((void **)(((char *)node) + 4));
            if (node != NULL)
            {
                goto loop_5;
            }
        }
    }
    return node;
}
