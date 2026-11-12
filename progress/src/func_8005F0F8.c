extern char stream_state[];
void rampFloatToOne(int index, char *volume);

/* Ramps the volume float at stream_state+0x333A toward 1.0 for the given index; always returns 0. */
int func_8005F0F8(int index)
{
    rampFloatToOne(index, stream_state + 0x333A);
    return 0;
}
