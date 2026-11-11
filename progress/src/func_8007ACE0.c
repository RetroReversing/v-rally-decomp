/* Select screen state, gSelectState. Offsets checked in func_8007ACE0 and func_8007A6D0. */
typedef struct VRSelectState {
    u8 pad000[0x1E4];
    s32 texturePack;      /* 0x1E4 */
    u8 pad1E8[0x237 - 0x1E8];
    u8 selected;          /* 0x237 */
    u8 curEntry;          /* 0x238 */
    u8 subIndex;          /* 0x239 */
    u8 pad23A[0x23D - 0x23A];
    u8 subCounts[0x2BD - 0x23D];  /* 0x23D, indexed by curEntry */
    s8 dirty;             /* 0x2BD */
} VRSelectState;

s32 select_set_active_sub(s32, u8);
s32 UpdateSelectedEntry(u8);
s32 select_load_texture_pack();
extern VRSelectState *gSelectState;

/* Steps the select screen to the next sub-item of the current entry, wrapping to 0 at the end,
 * then reloads the texture pack and re-flags the active sub-item. */
s32 func_8007ACE0(s32 slot) {
    u8 prevSub;

    prevSub = gSelectState->subIndex;
    if ((s32) prevSub >= (s32) gSelectState->subCounts[gSelectState->curEntry] - 1) {
        gSelectState->subIndex = 0;
    } else {
        gSelectState->subIndex = (u8) (prevSub + 1);
    }
    gSelectState->dirty = 1;
    UpdateSelectedEntry(prevSub);
    select_load_texture_pack();
    select_set_active_sub(slot, gSelectState->subIndex);
    return 0;
}
