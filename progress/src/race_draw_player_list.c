extern char stream_state[];
void draw_player_views(void **players);

/* Draws the player views from the player list head stored in the stream state. */
void race_draw_player_list(void) {
    draw_player_views(*(void ***)(stream_state + 0x80C6));
}
