s32 rand_scaled(s32 scale);

/* Reads two bytes of note data: the first is scaled by a random value and stored at arg0+0xB5, then the second is added and stored there too. Returns the data pointer past both bytes. */
unsigned char *FrandNote(char *arg0, unsigned char *arg1) {
    int v = rand_scaled(*arg1++);
    arg0[0xB5] = v;
    v += *arg1;
    arg0[0xB5] = v;
    return arg1 + 1;
}
