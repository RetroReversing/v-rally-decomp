/* identical to select_init_flags (matched), with its names changed by decompdecomp */

extern char *gSelectState; void select_set_entry_flag(int a, int b);
/* Sets entry 0 of the select list to flag 1 and turns on the two select-screen flags. */ int select_mark_refresh(void) { select_set_entry_flag(0, 1); *(char *)(gSelectState + 0x24D) = 1; *(char *)(gSelectState + 0x2BD) = 1; return 0; }
