extern s32 *gDmaThreadStack; extern u8 *gVoices; extern s32 gVoiceCount;

/* Picks a voice for a request record: req[0] is the sound key, req[4] receives the started voice and
 * req[8] is set to 1 when one was found. Uses the first free voice, else the active voice with the
 * lowest value that is below the key's priority threshold. */
s32 voice_alloc_request(void *req) {
    s32 best, min, i, limit, spare[2];
    u8 *p, *selected;
    s32 val, count;
    best = gDmaThreadStack[*(s32 *)req];
    min = best + 1;
    p = gVoices;
    count = gVoiceCount;
    i = 0;
    if (count > 0) {
        limit = count;
        do {
            count = *(s32 *)p;
            if (count == 0) goto found;
            if (*(u16 *)(p + 0x9e) != 0) {
                val = *(s32 *)(p + 0x44);
                if (val < min) {
                    min = val;
                    selected = p;
                }
            }
            i++;
            p += 0x134;
        } while (i < limit);
    }
    if (min < best) {
        *(s32 *)((u8 *)req + 4) = func_800898D0(selected, *(s32 *)req, 0x80, 0x80, best);
        *((u8 *)req + 8) = 1;
        return 1;
    }
    return 0;
found:
    *(s32 *)((u8 *)req + 4) = func_800898D0(p, *(s32 *)req, 0x80, 0x80, best);
    *((u8 *)req + 8) = 1;
    return 1;
}
