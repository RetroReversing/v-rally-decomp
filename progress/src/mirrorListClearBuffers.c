extern s32 gMirrorListHead;

/* Clears the 32-byte buffer that each node's +0x74 pointer refers to, walking the list from gMirrorListHead until it loops back or ends. */
void mirrorListClearBuffers(void)
{
    s32 temp_s1;
    s32 var_s0;

    var_s0 = gMirrorListHead;
    temp_s1 = var_s0;
    do {
        memset(*(void **)(var_s0 + 0x74), 0, 0x20);
        var_s0 = *(s32 *)(var_s0 + 0x5C);
    } while ((var_s0 != temp_s1) & (var_s0 != 0));
}
