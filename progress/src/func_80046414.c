void voice_queue_add_slot(s32 index);

/* Picks a stream index from an event kind and a mode, then starts it.
 * Mode 1 and mode 2 each map kinds 0..2 to a stream; a few other kinds
 * map to a single stream or are ignored. */
void func_80046414(s32 kind, s32 mode)
{
    if (mode == 1) {
        if (kind == 1) goto s6;
        if (kind == 0) goto s2;
        if (kind == 2) goto s4;
        return;
    s2:
        kind = 2;
        goto call;
    }
    if (mode == 2) {
        if (kind == 1) goto s5;
        if (kind == 0) goto s1;
        if (kind == mode) goto s3;
        return;
    }
    if (kind == 6) {
        if (mode != 8) return;
        kind = 0x12;
        goto call;
    }
    if (kind != 3) return;
    kind = 0;
    goto call;
s6: kind = 6; goto call;
s4: kind = 4; goto call;
s5: kind = 5; goto call;
s1: kind = 1; goto call;
s3: kind = 3;
call:
    voice_queue_add_slot(kind);
}
