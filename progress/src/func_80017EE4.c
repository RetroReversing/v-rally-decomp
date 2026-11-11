extern f32 vtx_scale;
extern f32 uv_scale;
extern f32 D_8009CEC8;

/* Scales the three s32 values at +0, +4 and +8 of the record that *rec points
 * to: the first by vtx_scale, the second by uv_scale, the third by D_8009CEC8. */
void func_80017EE4(void **rec) {
    void *temp_v0;

    temp_v0 = *rec;
    *(s32 *)((s8 *)temp_v0 + 0) = (s32) ((f32) *(s32 *)((s8 *)temp_v0 + 0) * vtx_scale);
    *(s32 *)((s8 *)temp_v0 + 4) = (s32) ((f32) *(s32 *)((s8 *)temp_v0 + 4) * uv_scale);
    *(s32 *)((s8 *)temp_v0 + 8) = (s32) ((f32) *(s32 *)((s8 *)temp_v0 + 8) * D_8009CEC8);
}
