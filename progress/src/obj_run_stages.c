s32 func_800229C0(s32, void *);

/* For each stage 0..10, looks for it in the -1-terminated list of stage ids at obj+0xA0 (one
 * word each). If the list holds the stage, runs it through func_800229C0; a -1 terminator stops
 * the search. */
void obj_run_stages(void *obj)
{
    s32 word;
    s32 stage;
    void *slot;

    stage = 0;
    do {
        word = *(s32 *)((s8 *)obj + 0xA0);
        if ((~word != 0) & (word != stage)) {
            slot = obj;
            do {
                slot += 4;
                word = *(s32 *)((s8 *)slot + 0xA0);
            } while ((~word != 0) & (word != stage));
        }
        if (word != -1) {
            func_800229C0(word, obj);
        }
        stage += 1;
    } while (stage < 0xB);
}
