extern void *gSelectState;
void selectStateSetDefaults(void);
void selectStateSyncFromOrder(void);

/* Resets the select state to its defaults, then sets the flag at +0x29F when keep is nonzero
 * and syncs the order mode into the stream state. */
void selectStateReset(s32 keep)
{
    selectStateSetDefaults();
    if (keep & 0xFF) {
        *(s8 *)((s8 *)gSelectState + 0x29F) = 1;
    }
    selectStateSyncFromOrder();
}
