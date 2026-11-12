s32 select_set_active_sub();
extern char stream_state[];

/* Steps the current stream cursor (+0x22) to the next entry of the current track list, wrapping to 0
 * after the last one, then tells the select code the new cursor. Always returns 0. */
s32 func_80071978(s32 arg0)
{
    if (*((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x22)) >= *((u16 *)(*((char **)(stream_state + 0x10386 + *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x1E)) * 4)) + *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x20)) * 0x2C4 + 0x14)) - 1)
    {
        *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x22)) = 0;
    }
    else
    {
        *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x22)) = *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x22)) + 1;
    }

    select_set_active_sub(arg0, *((u16 *)(*((char **)(stream_state + 0x32F2)) + 0x22)));
    return 0;
}
