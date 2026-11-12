/* Reads the AI_LEN register: the number of audio bytes left in the DMA buffer. */
u32 ai_get_len(void) { return *(vu32 *)0xA4500004; }
