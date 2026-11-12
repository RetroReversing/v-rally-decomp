void buildLinkPacket(void);
void save_race_to_pak(void);
void select_state_reset_b(s32, s32);

/* Builds the link packet, saves the race to the controller pak, then resets select state. */
s32 race_save_and_reset(void) {
    buildLinkPacket();
    save_race_to_pak();
    select_state_reset_b(0, 0);
    return 0;
}
