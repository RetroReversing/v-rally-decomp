extern u8 stream_state[];
s32 add_car_hud_entry();

/* Adds the HUD entry for the car only when the stream state word at 0x32AA equals 3. */
void hud_add_entry_if_ready(void) {
    if (*(s32 *)(stream_state + 0x32AA) == 3) {
        add_car_hud_entry();
    }
}
