/* Refreshes the hi-score tables: updates the race records, then the season standings. */
extern void hiscore_update_player_totals(void);
extern void hiscore_update_race_records(void);
extern void hiscore_update_season_standings(void);

void hiscore_refresh_all(void) {
    hiscore_update_player_totals();
    hiscore_update_race_records();
    hiscore_update_season_standings();
}
