typedef struct Stat Stat;
extern void hud_compute_values(Stat *);
/* Refreshes the race HUD values from the stats block. */ void hud_refresh_stats(Stat *stats) {
    hud_compute_values(stats);
}
