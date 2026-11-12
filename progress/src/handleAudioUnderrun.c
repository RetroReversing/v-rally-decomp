u32 ai_get_len(void);
extern s32 gAudioUnderrunFlag;

/* Clears the audio underrun flag when the AI DMA buffer is empty and the flag is already zero. */
void handleAudioUnderrun(void) {
    if (((ai_get_len() >> 2) == 0) && (gAudioUnderrunFlag == 0)) {
        gAudioUnderrunFlag = 0;
    }
}
