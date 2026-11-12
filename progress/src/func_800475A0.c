s32 viewport_build_dl(s32, s32, s32, s32);
s32 list_nth_node(void *, s32);
extern char stream_state[];

/* If list_nth_node accepts the stream list at stream_state+0x7672 (with its +8 field),
 * builds the viewport display list from the object at stream_state+0x7CD6 (field +0x178). */
void func_800475A0(void) {
    void *list;

    list = *(void **)(stream_state + 0x7672);
    if (list_nth_node(list, *(s32 *)((char *)list + 8)) != 0) {
        viewport_build_dl(*(s32 *)((char *)*(void **)(stream_state + 0x7CD6) + 0x178), 0, 0, 0);
    }
}
