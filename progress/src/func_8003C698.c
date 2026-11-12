/* Copies the mode from obj's state block into obj's flag at +0x7A: mode 0 maps to 0, mode 1 to 1, and larger values pass through. */ void func_8003C698(void *obj)
{
    u32 mode;
    void *state;

    state = *((void **) (((char *) (*((void **) (((char *) obj) + 0xA8)))) + 0x24));
    if (state != NULL)
    {
        mode = *(*((u32 **) (((char *) state) + 0x50)));
        if (mode < 2U)
        {
            if (mode == 0)
            {
                *((s16 *) (((char *) obj) + 0x7A)) = 0;
            }
            else
            {
                *((s16 *) (((char *) obj) + 0x7A)) = 1;
            }
        }
        else
        {
            *((s16 *) (((char *) obj) + 0x7A)) = (s16) mode;
        }
    }
}
