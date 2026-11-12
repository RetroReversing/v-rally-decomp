extern void *gSelectState;
extern u8 gOrderState[];
extern u8 D_800A13C0[];
void heapQueryFreeSize(s32);
void strCpy(void *, s32);
void text_load_and_parse(void *, void *);

/* Resets the select state: clears the flags, loads the entry for the current table
   index into a local record, runs the state's callback if one is set, and marks the
   state as stage 3. */
void select_reset_state(s32 src)
{
    s32 record[6];
    u8 tableIdx;
    char *state;
    void (*callback)();

    heapQueryFreeSize(1);
    heapQueryFreeSize(2);
    strCpy(record, src);
    state = gSelectState;
    state[0x235] = 0;
    tableIdx = gOrderState[0x120C];
    *((s32 *)(state + 0x1F0)) = 0;
    text_load_and_parse(D_800A13C0 + tableIdx * 0x24, record);
    callback = *((void (**)())((char *)gSelectState + 0x288));
    if (callback != NULL)
    {
        callback();
    }
    *((char *)gSelectState + 0x249) = 3;
    *((s32 *)((char *)gSelectState + 0x1E4)) = 0;
}
