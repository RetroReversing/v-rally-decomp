extern char stream_state[];
void voice_alloc_request(s32,u8); void voiceSetVolumeByKey(s32,s32);

/* Per-frame stream voice update: when the stream's voice slot is in use (not 0xff) and its
 * record type is not 7, scale the stream volume by 112 and apply it to the slot's voice. */
void streamUpdateVoiceVolume(void) {
 u8 *slot=(u8 *)(stream_state+0x331A);
 if(*slot!=0xff && *(u16 *)(*(u8 **)(stream_state+0x32F2)+0x1e)!=7) {
  s32 slotIdx=*slot, off;
  *(f32 *)(stream_state+0x3336)=*(f32 *)(stream_state+0x3332)*112.0f;
  off=(slotIdx<<1)+slotIdx; off=off<<2;
  voice_alloc_request(*(s32 *)(stream_state+0x7f26)+off,*slot);
  voiceSetVolumeByKey(*(s32 *)(stream_state+0x7f26)+*slot*12,(s32)*(f32 *)(stream_state+0x3336));
 }
}
