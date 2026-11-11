s32 getPressedButtonValue();
s32 advanceStreamFrame();
s32 setStreamPaused();
s32 func_800855F8();
extern s32 gPadFlags;

/* Per-frame pause input for one stream. Unless gPadFlags has 0x800 set, reads the player slot
 * stored in the record at obj+0x48 and gets that player's pressed-button value. Bit 0x400 acks
 * the pause and advances the stream frame; bit 0x800 sets or clears the stream's paused flag. */
void updatePlayerPauseInput(s32 stream, void *obj) {
    s32 playerSlot;
    s32 buttons;
    s32 var_v0;

    if (!(gPadFlags & 0x800)) {
        playerSlot = *(s32 *)(*(u8 **)((u8 *)obj + 0x48));
        buttons = 0;
        if (playerSlot < 4) {
            buttons = getPressedButtonValue(playerSlot & 0xff);
        }
        if (buttons & 0x400) {
            func_800855F8(*(u8 *)(*(u8 **)((u8 *)obj + 0x48) + 3), 0x400);
            func_800855F8(*(u8 *)(*(u8 **)((u8 *)obj + 0x48) + 3), 0x800);
            advanceStreamFrame(stream, obj);
            setStreamPaused(stream, 0);
        }
        var_v0 = buttons & 0x800;
        if (var_v0 != 0) {
            setStreamPaused(stream, 1);
        } else {
            setStreamPaused(stream, 0);
        }
    }
}
