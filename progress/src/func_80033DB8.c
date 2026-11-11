s32 func_8001FEDC();
s16 track_sample_lookup(void *obj, s32 index, void *out);

/* Picks a sample index bias from the value func_8001FEDC returns (larger value, larger
 * bias: 2, 3, 4 or 5), then looks up the track sample at base + bias. arg0 is unused. */
void func_80033DB8(s32 unused0, void *track, s32 base, void *out) {
    s32 speed;
    s32 bias;

    speed = func_8001FEDC();
    bias = (-(speed >= 0x1388) & 5) | 4;
    if (speed < 0xBB8) {
        bias = 3;
    }
    if (speed < 0x3E8) {
        bias = 2;
    }
    track_sample_lookup(track, base + bias, out);
}
