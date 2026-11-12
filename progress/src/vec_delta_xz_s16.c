/* Stores the x and z differences (to) - (from) as 16-bit values in dst[0] and dst[2]. */
void vec_delta_xz_s16(void *dst, void *from, void *to)
{
    *(s16 *)((s8 *)dst + 0) = (s16) (*(s32 *)((s8 *)to + 0) - *(s32 *)((s8 *)from + 0));
    *(s16 *)((s8 *)dst + 4) = (s16) (*(s32 *)((s8 *)to + 8) - *(s32 *)((s8 *)from + 8));
}
