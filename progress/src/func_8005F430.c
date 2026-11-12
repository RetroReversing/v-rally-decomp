extern char *gSelectState; void select_group_set_value(int a, int b);
/* Clears selection group 0 and the gSelectState+0x24D flag (the counterpart of func_80070FB0). */
int func_8005F430(void) { select_group_set_value(0, 0); *(char *)(gSelectState + 0x24D) = 0; return 0; }
