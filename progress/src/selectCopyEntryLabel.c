/* adapted from similar verified C in func_8005B0C8 in V-RALLY (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in selectCopyEntryLabel in V-RALLY (matched), with its names changed by decompdecomp */
void *select_get_entry(u32); void copyStringAligned(char *a, int b); void func_800595EC(char *a);
int selectCopyEntryLabel(int arg0, int arg1) { char buf[16]; copyStringAligned(buf, (int)select_get_entry(arg1) + 48); func_800595EC(buf); return 0; }
