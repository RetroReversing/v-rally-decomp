extern u8 *gSelectState;
void UpdateSelectedEntry();
void select_load_texture_pack();
void select_set_active_sub(s32, u8);

/* Steps the select counter at +0x239 down by one (taking the starting value from the table
 * at +0x23d when it is zero), flags the state at +0x2BD, reloads the texture pack and sets
 * the active sub-selection to the new counter. Returns 0. */
s32 func_8007AC68(s32 sub)
{
    u8 counter;
    counter = gSelectState[0x239];
    if (!counter)
        counter = (gSelectState + gSelectState[0x238])[0x23d];
    gSelectState[0x239] = --counter;
    {
        u8 *p = gSelectState;
        p[0x2bd] = (counter - counter) + 1;
    }
    UpdateSelectedEntry();
    select_load_texture_pack();
    select_set_active_sub(sub, gSelectState[0x239]);
    return 0;
}
