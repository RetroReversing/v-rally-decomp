s32 voice_queue_add(s32, s32);
extern char stream_state[];

/* Queues the 12-byte voice record at index (low 8 bits) of the table whose base
 * pointer is stored at stream_state+0x7F26, passing the owner value, which is the
 * float at stream_state+0x332E scaled by 128. */
void voice_queue_add_slot(s32 index)
{
    voice_queue_add(*(s32 *)(stream_state + 0x7F26) + ((index & 0xFF) * 0xC),
                    (s32)(*(f32 *)(stream_state + 0x332E) * 128.0f));
}
