extern f32 vtx_scale;
extern f32 uv_scale;
extern f32 D_8009CEC8;

/* Sets the vertex scale (and the second vertex scale D_8009CEC8) from the object's word at +0x90, and the UV scale from +0xDC, both in 1/100 units. */
void objSetTexScales(void *arg0) {
    vtx_scale = (f32) *(s32 *)((char *)arg0 + 0x90) * 0.01f;
    D_8009CEC8 = (f32) *(s32 *)((char *)arg0 + 0x90) * 0.01f;
    uv_scale = (f32) *(s32 *)((char *)arg0 + 0xDC) * 0.01f;
}
