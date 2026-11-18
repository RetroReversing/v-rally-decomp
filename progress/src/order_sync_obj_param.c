extern s32 gOrderState;

/* Copies the 16-bit value at +0x90 of src into the +0x7A field of the current order object, if one is set. */
void order_sync_obj_param(void *src) {
    if (*(void **)((s8 *)&gOrderState + 0x8A28) != NULL) {
        *(s16 *)((s8 *)*(void **)((s8 *)&gOrderState + 0x8A28) + 0x7A) = (s16)*(s32 *)((s8 *)src + 0x90);
    }
}
