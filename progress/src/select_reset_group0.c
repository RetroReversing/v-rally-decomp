/* Resets select group 0 to value 1 and sets the state flag at +0x24D; same code as select_reset_defaults at 0x8005F3FC. */ /* identical to select_reset_defaults (matched), with its names changed by decompdecomp */

extern char *gSelectState; void select_group_set_value(int a, int b);
int select_reset_group0(void) { select_group_set_value(0, 1); *(char *)(gSelectState + 0x24D) = 1; return 0; }
