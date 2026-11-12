extern s16 g_obj_state_copy;

/* Copies the 16-bit low half of the word at obj+0x90 into g_obj_state_copy. */
void obj_copy_state_0x90(void *obj) {
    g_obj_state_copy = (s16) *(s32 *)((s8 *)obj + 0x90);
}
