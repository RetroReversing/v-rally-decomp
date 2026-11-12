/* Voice layout used by the pitch/glide update. Offsets are the ones the matched code reads. */
typedef struct VRALVoice {
    u8 pad00[0x20]; f32 pitchBend; f32 lastPitch; f32 pitch; u8 pad2C[0x1C];
    f32 glideTarget; f32 glidePitch; u8 pad50[0x52]; u16 glideLength;
    u8 padA4[0xC]; u8 glideSteps; s8 vibratoDepth; u8 vibratoReset;
} VRALVoice;

s32 alSynSetPitch(void *, s32, f32);
f32 func_80089300(f32);
extern f64 D_800A6D40;
extern u8 gOrderState[];
extern s32 stream_state;

/* Advances a voice's pitch by its glide and vibrato, then sends the new pitch to the synth if it changed. */
void voiceUpdatePitch(VRALVoice *voice, s32 voiceIndex, f32 pitchOffset) {
    f32 temp_ft0;
    f64 scaled;
    f32 pitch;
    s32 temp_v1;
    s32 vibrato;
    u16 temp_a0;
    u8 temp_a0_2;
    u8 temp_v0;

    temp_v0 = voice->glideSteps;
    pitch = voice->pitch;
    temp_v1 = temp_v0 & 0xFF;
    if (temp_v1 != 0) {
        temp_a0 = voice->glideLength;
        if (temp_v0 >= temp_a0) {
            temp_ft0 = voice->glideTarget;
            pitch = temp_ft0 + (((pitch - temp_ft0) / (f32) temp_v1) * (f32) temp_a0);
        }
        voice->glidePitch = pitch;
    }
    temp_a0_2 = voice->vibratoReset;
    vibrato = voice->vibratoDepth * (1 - temp_a0_2);
    pitch = pitch + (pitchOffset + voice->pitchBend + (f32) vibrato);
    voice->vibratoReset = 0U;
    if (pitch != voice->lastPitch) {
        scaled = (f64) pitch * D_800A6D40;
        voice->lastPitch = pitch;
        alSynSetPitch(gOrderState + 0x2304, *(s32 *) ((s8 *) &stream_state + 0x7576) + (voiceIndex * 0x1C), func_80089300((f32) scaled));
    }
}
