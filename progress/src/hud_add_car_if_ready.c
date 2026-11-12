extern char stream_state[];
void add_car_hud_entry(void);

/* Adds a car HUD entry once the stream counter at +0x32AA reaches 3. */
void hud_add_car_if_ready(void) {
    if (*(s32 *)(stream_state + 0x32AA) == 3) {
        add_car_hud_entry();
    }
}
