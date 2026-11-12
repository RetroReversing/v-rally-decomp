void func_8008E3D0();
extern s32 D_800A2500;

/* Closes the audio system if it is open: runs func_8008E3D0 and clears the open flag. */
void alClose(void) {
    if (D_800A2500 != 0) {
        func_8008E3D0();
        D_800A2500 = 0;
    }
}
