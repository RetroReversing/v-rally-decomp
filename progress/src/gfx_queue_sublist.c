void gfx_call_sublist(int parent, int sub, int flags);

/* Submits a display-list node's sublist: passes the node's sublist pointer (+0x20) and its
 * 16-bit flags (+0x14) to gfx_call_sublist, which appends the G_DL call to parent. */
void gfx_queue_sublist(int parent, int unused, char *node) {
    gfx_call_sublist(parent, *(int *)(node + 0x20), *(unsigned short *)(node + 0x14));
}
