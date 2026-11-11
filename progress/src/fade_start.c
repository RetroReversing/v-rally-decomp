extern s16 gFadeLayer;
extern s32 gFadeDirection;
extern s16 gFadeLevel;
extern s16 gFadeTimer[];

/* Starts a screen fade on one layer. fade_out != 0 starts at full brightness;
 * otherwise it starts at black. duration is clamped to 255 frames and the
 * per-frame step is 255 / duration. */
void fade_start(u8 layer, u16 duration, u8 fade_out)
{
    s16 *timer;
    u32 dur;
    s32 step;

    gFadeLayer = layer;
    timer = gFadeTimer;
    gFadeDirection = fade_out;
    if (fade_out == 1)
    {
        gFadeLevel = 0xFF;
        dur = duration;
    }
    else
    {
        gFadeLevel = 0;
        dur = duration;
    }
    if (dur >= 0x100)
    {
        duration = 0xFF;
    }
    step = 0xFF / duration;
    timer[0] = duration;
    timer[2] = step;
}
