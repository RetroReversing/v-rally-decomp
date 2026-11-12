extern void *gSelectState;
extern char stream_state[];
s32 list_remove_at(u8, s32);

/* If the select count at gSelectState+0x232 is nonzero and list_remove_at removes the entry (object byte +0x93, stream word +0x7672), decrements the count. */
void func_8005861C(void *obj)
{
    if ((*((u8 *) (((u8 *) gSelectState) + 0x232)) != 0) && (list_remove_at(*((u8 *) (((u8 *) obj) + 0x93)), *((s32 *) (stream_state + 0x7672))) & 0xFF)) {
        *((u8 *) (((u8 *) gSelectState) + 0x232)) = (u8) (*((u8 *) (((u8 *) gSelectState) + 0x232)) - 1);
    }
}
