extern char gStreamState[];
void osSendMesg(char *a, int b, int c);
void pif_unlock(void) { osSendMesg(gStreamState + 0x10312, 0, 0); }
