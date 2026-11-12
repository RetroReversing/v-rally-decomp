extern char stream_state[];
void osSendMesg(char *a, int b, int c);

/* Posts a zero message to the PIF queue kept at stream_state+0x10312. */
void pif_unlock(void) {
    osSendMesg(stream_state + 0x10312, 0, 0);
}