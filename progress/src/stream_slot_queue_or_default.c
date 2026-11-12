/* Returns the queue word (+0x14) of the given stream slot, or of stream_default_slot when slot is NULL. */
extern void *stream_default_slot;

s32 stream_slot_queue_or_default(void *slot) {
    void *var_a0;

    var_a0 = slot;
    if (var_a0 == NULL) {
        var_a0 = stream_default_slot;
    }
    return *(s32 *)((s8 *)var_a0 + 0x14);
}
