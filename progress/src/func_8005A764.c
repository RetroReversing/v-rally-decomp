void *select_get_entry(u32);
void func_8005A764(char arg0, int arg1, int arg2) { ((u8 *)select_get_entry(arg2))[0x42] = arg0; }
