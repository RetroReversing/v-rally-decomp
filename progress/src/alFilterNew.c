typedef struct ALFilter_s {
    struct ALFilter_s *source;
    s32 (*handler)(void *, s32 *);
    void *setParam;
    s16 inp;
    s16 out;
    s32 type;
} ALFilter;

/* Initializes an ALFilter audio processing node. */
void alFilterNew(ALFilter *filter, void *handler, void *setParam, s32 type) {
    filter->source = NULL;
    filter->handler = handler;
    filter->setParam = setParam;
    filter->inp = 0;
    filter->out = 0;
    filter->type = type;
}
