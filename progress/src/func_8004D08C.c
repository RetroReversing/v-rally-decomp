void *list_nth_node(s32, s32);
s32 func_8004CEB4(s32, void *, s16 *, u8, s32, s32, s32, s32, s32);
extern s32 gStreamList;

/* Looks up object `id` in the table, then queues a draw with its scaled x/y extents.
 * The two f32 scales are applied to the object's stored width and height. */
void func_8004D08C(s32 arg0, s32 id, s16 x, s16 y, f32 scaleX, f32 scaleY, u8 arg6, u8 arg7) {
    s16 box[4];
    void *obj;

    obj = list_nth_node(gStreamList, id & 0xFFFF);
    if (obj != NULL) {
        box[0] = x;
        box[1] = y;
        box[2] = (s16)(s32)((f32)*(u16 *)(*(char **)(*(char **)(*(char **)((char *)obj + 0xC) + 4)) + 6) * scaleX);
        box[3] = (s16)(s32)((f32)*(u16 *)(*(char **)(*(char **)(*(char **)((char *)obj + 0xC) + 4)) + 8) * scaleY);
        func_8004CEB4(arg0, *(void **)(*(char **)(*(char **)((char *)obj + 0xC) + 4)), box, arg6, arg7, arg7, arg7, arg7, 0);
    }
}
