s32 osViBlack(s32);
extern void (*gPrevVideoHandler)(void);

/* Video-off handler: runs the previously installed handler, then blanks the display. */
void video_blank_on_exit(void) {
    gPrevVideoHandler();
    osViBlack(1);
}
