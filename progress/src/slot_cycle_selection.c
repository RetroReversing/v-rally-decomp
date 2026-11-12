extern char *gRecords;
void slotSetSelected(int slot, int selected_index);

/* Steps the selected index of the current record up (capped at 2), then marks that slot as selected. Always returns 0. */
int slot_cycle_selection(int slot)
{
    char *rec = gRecords;
    unsigned short sel_index = *(unsigned short *)(rec + 0x16);

    if (sel_index < 2) {
        sel_index++;
        *(unsigned short *)(rec + 0x16) = sel_index;
        slotSetSelected(slot, sel_index);
    }
    return 0;
}
