s32 osSetIntState(s32);

/* Pushes player arg1 onto the front of the list headed at arg0 (next pointer at +0), copying the head's +0x20 word into the player's +0x10, with interrupts masked around the update. */
void alSynAddPlayer(void *arg0, void *arg1) {
    s32 temp_v0;

    temp_v0 = osSetIntState(1);
    *(s32 *)((char *)arg1 + 0x10) = (s32) *(s32 *)((char *)arg0 + 0x20);
    *(void **)((char *)arg1 + 0) = (void *) *(void **)((char *)arg0 + 0);
    *(void **)((char *)arg0 + 0) = arg1;
    osSetIntState(temp_v0);
}
