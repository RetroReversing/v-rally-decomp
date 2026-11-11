typedef void (*CbFn)(void *, s32, s32);

typedef struct AlFilter {
    struct AlFilter *child;
    s32 unk4;
    CbFn cb;
} AlFilter;

typedef struct AlResample {
    AlFilter *child;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 rate;
    s32 flush;
    s32 pending;
    s32 active;
    s32 unk28;
    s32 unk2C;
    s32 stopping;
} AlResample;

/* Sets one parameter on a resampler. Param 1 sets the child filter, 2 starts (clears state and
 * sends the child 4), 3 stops (sends the child 9), 4 sets the rate, 5 requests a flush, 6..9 do
 * nothing. Any other param is forwarded to the child's callback. Always returns 0. */
s32 alResampleParam(AlResample *resample, s32 param, s32 value) {
    AlResample *self = resample;
    AlFilter *node;

    switch (param) {
    case 1:
        resample->child = (AlFilter *)value;
        return 0;
    case 2:
        self->pending = 0;
        self->active = 1;
        self->stopping = 0;
        self->flush = 0;
        node = resample->child;
        if (node != NULL) {
            node->cb(node, 4, 0);
        }
        return 0;
    case 3:
        self->stopping = 1;
        node = resample->child;
        if (node != NULL) {
            node->cb(node, 9, 0);
        }
        return 0;
    case 4:
        self->rate = value;
        return 0;
    case 5:
        self->flush = 1;
        return 0;
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    default:
        break;
    }
    node = resample->child;
    if (node != NULL) {
        node->cb(node, param, value);
    }
    return 0;
}
