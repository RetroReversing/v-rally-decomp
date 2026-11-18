void func_80010AF4(void);
void race_draw_player_list(void);

/* Emits the HUD object display lists, then draws the player views for the race. */
void race_draw_views(void) {
    func_80010AF4();
    race_draw_player_list();
}
