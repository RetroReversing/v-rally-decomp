extern f32 D_8009BB94;
extern f32 D_8009BB98;
extern f32 D_8009BB9C;
extern f32 D_8009BBA0;

/* Copies the four position words of the object at arg0 (offsets 0x90, 0xDC, 0x128, 0x174), converted to float, into D_8009BB94..D_8009BBA0. */
void objCopyPositionF(void *arg0) {
    D_8009BB94 = (f32) *(s32 *)((char *)arg0 + 0x90);
    D_8009BB98 = (f32) *(s32 *)((char *)arg0 + 0xDC);
    D_8009BB9C = (f32) *(s32 *)((char *)arg0 + 0x128);
    D_8009BBA0 = (f32) *(s32 *)((char *)arg0 + 0x174);
}
