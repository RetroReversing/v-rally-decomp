s32 osSendMesg();
extern char gOrderState[];

void func_8007F798(s32 arg0, s32 arg1, s32 arg2) {
    osSendMesg(((arg0 + arg1) * 0x5C) + (gOrderState + 0x5924), arg2, 0);
}
