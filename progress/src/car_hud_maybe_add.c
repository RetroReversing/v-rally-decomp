void add_car_hud_entry();
extern u8 stream_state[];

/* Adds the current car's HUD entry, but only when the state word at stream_state+0x32AA is 2. */
void car_hud_maybe_add(void) {
    if (*(s32 *)(stream_state + 0x32AA) == 2) {
        add_car_hud_entry();
    }
}
