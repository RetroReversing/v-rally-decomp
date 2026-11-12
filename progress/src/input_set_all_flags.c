/* identical to func_8008B0D0 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to input_set_all_flags in V-RALLY (matched), with its names changed by decompdecomp */

extern char *gControllerInputContext;
/* Sets the controller input flags for one slot to all ones (0xFFFF). */ void input_set_all_flags(unsigned char slot) { *(unsigned short *)(gControllerInputContext + slot * 2 + 0x4C) = 0xFFFF; }
