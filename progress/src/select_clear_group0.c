/* Select handler for group 0x0F: clears selection group 0 and the gSelectState+0x24D flag. */ /* identical to func_8005F430 (matched), with its names changed by decompdecomp */

extern char *gSelectState; void select_group_set_value(int a, int b);
int select_clear_group0(void) { select_group_set_value(0, 0); *(char *)(gSelectState + 0x24D) = 0; return 0; }
