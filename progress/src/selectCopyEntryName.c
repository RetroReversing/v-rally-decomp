extern void *gSelectState;
#ifdef PORT
s32 strCpy(void *, void *);
void selectCopyEntryName(u8 *srcEntry) {
    strCpy((u8 *)gSelectState + 0x210, srcEntry + 0x4C);
}
#else
s32 strCpy(s32, s32);
void selectCopyEntryName(s32 srcEntry) {
    strCpy((s32)((u8 *)gSelectState + 0x210), srcEntry + 0x4C);
}
#endif
