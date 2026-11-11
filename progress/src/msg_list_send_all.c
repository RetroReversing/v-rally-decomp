s32 osSendMesg();

/* Walks the node list at *head (next at +4). Each node carries a 32-bit word at +0xC (type in the low
 * half); nodes are sent `msg` through the queue at +0x10, except nodes whose type is 4 unless the
 * flag bits match 0x40001. */
void msg_list_send_all(void **head, s32 msg)
{
    char *node;

    node = *head;
    if (node != NULL) {
        do {
            if (((*(s32 *)(node + 0xC)) & 0xFFFF0001) == 0x40001 || *(u16 *)(node + 0xC) != 4) {
                osSendMesg(node + 0x10, msg, 0);
            }
            node = *(char **)(node + 4);
        } while (node != NULL);
    }
}
