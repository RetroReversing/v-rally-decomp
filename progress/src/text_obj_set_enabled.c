/* Sets the enable byte (+0x1A) of the text object with the given index. */
void *textObjGet(u32);

void text_obj_set_enabled(u32 index)
{
    *(s8 *)((s8 *)textObjGet(index) + 0x1A) = 1;
}
