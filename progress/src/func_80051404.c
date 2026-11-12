extern char gOrderState[];
extern char stream_state[];

/* Walks the order-state chain for the entry at index entry->0x114 of the
 * 0x44-byte entry array at arg0, stepping once per index (twice when the
 * slot's flag at +0x1B is set), and returns the node reached. */
void *func_80051404(char *arg0)
{
    char *new_var;
    void *node;
    char *temp_a0;
    u8 count;
    u16 flags;
    u8 slot_flag;
    u8 i;

    count = arg0[0x114];
    new_var = *((char **) (stream_state + 0x32F2));
    temp_a0 = arg0 + (count * 0x44);
    flags = *((u16 *) (temp_a0 + 8));
    node = *((void **) (*((void **) (gOrderState + 0x73F0))));
    temp_a0 = new_var;
    flags = flags >> 4;
    slot_flag = temp_a0[0x1B];
    if (flags & 1)
    {
        node = *((void **) (((char *) node) + 4));
    }
    i = 0;
    if (count != 0)
    {
        slot_flag = slot_flag;
        do
        {
            node = *((void **) (((char *) node) + 4));
            if (slot_flag != 0)
            {
                node = *((void **) (((char *) node) + 4));
            }
            i++;
        }
        while (i < count);
    }
    return node;
}
