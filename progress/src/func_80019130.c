s32 func_80005CB8();
s32 rebase_words();
s32 rebaseRecords();
s32 func_8007EF5C();
s32 heapQueryFreeSize();
s32 resolve_path();
s32 func_80081664();
s32 func_80081B44();
extern s32 gFreeHeap1;
extern s32 gFreeHeap2;
extern s32 gSceneHeapBlock;
extern u8 D_8009BBBC;
extern s32 D_8009D4E8;
extern s32 rebase_base_addr;
extern char D_800A4190[];
extern char gOrderState[];
extern char gStreamState[];

/* Sets up the sound and resource state, picks the stream buffer size from the
 * level setting at gStreamState+0x7678, then runs the per-entry setup over the
 * list at arg0 (a pointer to the entries, with the count in its +4 field).
 * Returns arg0. */
void *func_80019130(u8 *arg0)
{
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    u8 *var_s1;
    s32 var_s0;
    u8 *var_s2;
    u8 *var_s3;
    s32 v;


    var_s3 = arg0;
    resolve_path(D_800A4190);
    rebase_base_addr = func_80081664(gSceneHeapBlock, gOrderState + 0x23D8);
    D_8009D4E8 = func_80081664(gSceneHeapBlock, gStreamState + 0x5B82);
    func_80081B44();
    gFreeHeap1 = heapQueryFreeSize(1);
    gFreeHeap2 = func_8007EF5C(2);
    if (D_8009BBBC == 0) {
        v = *(u8 *)(gStreamState + 0x7678);
        switch (v) {
        case 0: *(s32 *)(gOrderState + 0x72F4) = func_80005CB8(1, 0xF618, 0xD6D8, 1, 6); break;
        case 1: *(s32 *)(gOrderState + 0x72F4) = func_80005CB8(1, 0xFA00, 0xD6D8, 1, 6); break;
        case 2: *(s32 *)(gOrderState + 0x72F4) = func_80005CB8(1, 0xFA00, 0xD6D8, 1, 6); break;
        case 3: *(s32 *)(gOrderState + 0x72F4) = func_80005CB8(1, 0xFA00, 0xC350, 1, 6); break;
        default: goto skip;
        }

    }
skip:
    rebase_words(var_s3, 1, rebase_base_addr);
    var_s1 = *(u8 **)var_s3;
    rebase_words(var_s1, *(u16 *)(var_s3 + 4), rebase_base_addr);
    var_s2 = var_s3;
    for (var_s0 = 0; var_s0 < (s32)*(u16 *)(var_s2 + 4); var_s0++) {
        rebaseRecords(var_s1);
        var_s1 += 8;
    }
    return var_s3;
}
