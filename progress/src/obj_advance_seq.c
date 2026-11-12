typedef struct { s32 next; s32 cur; } SeqCounter;

/* Sets seq->next to seq->cur + 1, where seq is the SeqCounter pointer stored at obj+0x50. */
void obj_advance_seq(void *obj) {
    SeqCounter *seq;

    seq = *(SeqCounter **)((s8 *)obj + 0x50);
    seq->next = seq->cur + 1;
}
