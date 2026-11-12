void *orderFindNeighbor(void *arg0, void *arg1);
s32 timer_update_from_time(void *arg0, s32 arg1);

/* If the object's +0xA8 record has a neighbour at +0x24, finds that neighbour's order entry and updates the object's timer from its time. */
void objSyncNeighborTimer(void *arg0)
{
    void *neighbor;

    neighbor = *(void **)((char *)*(void **)((char *)arg0 + 0xA8) + 0x24);
    if (neighbor != NULL) {
        neighbor = orderFindNeighbor(arg0, neighbor);
        if (neighbor != NULL) {
            timer_update_from_time(arg0, *(s32 *)((char *)*(void **)((char *)neighbor + 0x6C) + 0xC));
        }
    }
}
