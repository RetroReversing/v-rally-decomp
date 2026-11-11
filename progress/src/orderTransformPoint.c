s32 mat3_transform_vec();
extern char gOrderState[];

/* Transforms the point src by the order's 3x3 matrix (at gOrderState + 0x7928), then adds the order's translation (three s32 words at 0x793C) and writes the result to dst. */
void orderTransformPoint(s16 *src, void *dst) {
    mat3_transform_vec(gOrderState + 0x7928, src, dst);
    *(s32 *)((char *)dst + 0) = (s32) (*(s32 *)((char *)dst + 0) + *(s32 *)(gOrderState + 0x793C));
    *(s32 *)((char *)dst + 4) = (s32) (*(s32 *)((char *)dst + 4) + *(s32 *)(gOrderState + 0x7940));
    *(s32 *)((char *)dst + 8) = (s32) (*(s32 *)((char *)dst + 8) + *(s32 *)(gOrderState + 0x7944));
}
