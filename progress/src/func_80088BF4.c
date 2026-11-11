extern f64 D_800A6D30;

/* Stream state for a run-length coded control track. cur/end are in 0x100-per-tick
   time units. data points at the next code byte; count is the ticks left on the
   current value. Codes below 0x80 hold a value for one short run; codes with the
   top bit set hold it for a run length read from the next byte(s). */
typedef struct S88 {
    u8 p0[8];
    s32 end;
    u8 p0c[8];
    s32 cur;
    u8 p18[8];
    f32 value;
    u8 p24[0xc];
    u8 * volatile data;
    u8 p34[0x34];
    f32 scale;
    f32 result;
    u8 p70[0x2c];
    u16 count;
} S88;

/* Advances the stream by one run: consumes the next code, sets result to the
   decoded sample and value to result * scale, and loads the run length. Loops
   until cur reaches end. */
void func_80088BF4(S88 *p) {
    f32 sample;
    u16 remaining;
    u8 *q;
    u8 code;
    u8 *r;
    do {
        p->cur += 0x100;
        remaining = --p->count;
        if (remaining == 0) {
            code = *p->data++;
            if (code >= 0x80) {
                sample = (f32)((f64)(f32)(code & 0x7f) - D_800A6D30);
                q = p->data;
                p->data = q + 1;
                p->result = sample;
                p->value = sample * p->scale;
                code = *q;
                if (code >= 0x80) {
                    s32 high = (code & 0x7f) << 8;
                    p->count = high;
                    r = p->data;
                    p->data = r + 1;
                    high += 2;
                    p->count = *r + high;
                } else {
                    p->count = code + 2;
                }
            } else {
                sample = (f32)((f64)(f32)code - D_800A6D30);
                p->count = 1;
                p->result = sample;
                p->value = sample * p->scale;
            }
        }
    } while ((u32)p->cur < (u32)p->end);
}
