f32 __sinf(f32);
extern f64 D_800A6D38;

/* Sine-wave value for an object: when the 0xA2 counter is ahead of the 0xAE counter,
   sets the output at +0x64 to amplitude (+0x1C) times sin(2*pi * elapsed / period),
   where the period is the byte at +0xCD. Returns the stored output value. */
f32 func_80088F1C(void *obj)
{
    s32 elapsed;

    elapsed = *(u16 *)((u8 *)obj + 0xA2) - *(u8 *)((u8 *)obj + 0xAE);
    if (elapsed > 0) {
        *(f32 *)((u8 *)obj + 0x64) = (f32) (__sinf((f32) ((f64) (2.0f * ((f32) elapsed / (f32) *(u8 *)((u8 *)obj + 0xCD))) * D_800A6D38)) * *(f32 *)((u8 *)obj + 0x1C));
    }
    return *(f32 *)((u8 *)obj + 0x64);
}
