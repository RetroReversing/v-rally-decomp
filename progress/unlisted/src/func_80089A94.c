extern s32 D_800AB970,D_800AB974; extern void *gVoiceQueue[4]; extern s32 D_800AFA54; extern s32 voiceKeyIsFree(void*); extern void voice_alloc_request(void*); extern void voiceSetVolumeByKey(void*,s32);
/* Services the head of the 4-slot voice queue gVoiceQueue (head D_800AB970, count D_800AB974):
 * a flagged head voice whose key is free is dequeued; an unflagged one is stopped and its
 * volume set to D_800AFA54. */
void func_80089A94(void) { s32 i; void *voice; if(D_800AB974!=0){ voice=gVoiceQueue[D_800AB970]; if(*(u8*)((u8*)voice+8)!=0){ if(voiceKeyIsFree(voice)!=0){ i=D_800AB970; gVoiceQueue[i]=0; D_800AB970=i+1; if((u32)D_800AB970<4){} else D_800AB970=0; D_800AB974--;
return;
 } } else {voice_alloc_request(voice); voiceSetVolumeByKey(gVoiceQueue[D_800AB970],D_800AFA54);} } }
