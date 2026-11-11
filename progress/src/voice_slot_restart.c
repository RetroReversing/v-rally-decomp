s32 alSynStartVoice();
s32 alSynStopVoice();
extern char gOrderState[];
extern char gStreamState[];

/* Restarts one voice slot. If the slot is already playing (+0xC1), its voice is stopped
 * first. The slot is then marked playing, its voice is started with the pending parameter
 * at +4, and that field is cleared. The voice block is at index * 0x1C in the table pointed
 * to by gStreamState+0x7576. */
void voice_slot_restart(void *slot, s32 index) {
    if (*(u8 *)((char *)slot + 0xC1) != 0) {
        alSynStopVoice(gOrderState + 0x2304, *(s32 *)(gStreamState + 0x7576) + (index * 0x1C));
    }
    *(u8 *)((char *)slot + 0xC1) = 1U;
    alSynStartVoice(gOrderState + 0x2304, *(s32 *)(gStreamState + 0x7576) + (index * 0x1C), *(s32 *)((char *)slot + 4));
    *(s32 *)((char *)slot + 4) = 0;
}
