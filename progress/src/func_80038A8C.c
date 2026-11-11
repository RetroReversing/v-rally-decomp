extern s32 gStreamState[];
s32 voice_queue_add(s32, s32);

/* Passes the 12-byte record for voice voiceIndex (table at gStreamState+0x7F26) and the level at gStreamState+0x332E, scaled by 128, to voice_queue_add. */
void func_80038A8C(s32 voiceIndex)
{
    voice_queue_add(*((s32 *) (((u8 *) gStreamState) + 0x7F26)) + ((voiceIndex & 0xFF) * 0xC), (s32) (*((f32 *) (((u8 *) gStreamState) + 0x332E)) * 128.0f));
}
