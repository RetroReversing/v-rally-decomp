/* Advances the float ramp stored in stream_state at +0x332E by one step. */
extern char stream_state[];
void rampFloatToOne(int unused, char *value);

int stream_ramp_step(int slot)
{
    rampFloatToOne(slot, stream_state + 0x332E);
    return 0;
}
