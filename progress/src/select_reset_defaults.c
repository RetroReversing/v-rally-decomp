/* Resets the select state: sets group 0 to 1 and raises the flag byte at +0x24D. */ /* identical to select_reset_group0 (matched), with its names changed by decompdecomp */
/* identical to select_reset_defaults (matched), with its names changed by decompdecomp */

extern char *gSelectState; void select_group_set_value(int a, int b);
int select_reset_defaults(void) { select_group_set_value(0, 1); *(char *)(gSelectState + 0x24D) = 1; return 0; }
