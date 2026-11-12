/* Advances the particle list of an emitter one frame: each live particle moves by its
 * velocity plus a third of the offset from the emitter origin to the target, then ages,
 * steps its animation frame and alpha, and clears its active flag when its life runs out. */
void particle_list_advance(void *obj, void *emitter, void *target)
{
    s32 count;
    s32 n;
    char *p;
    char *origin;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 step_x, step_y, step_z;
    u16 timer;
    u16 life;

    count = *(u16 *)((char *)emitter + 0x16);
    p = *(char **)((char *)emitter + 0x10);
    n = count;
    count--;
    origin = *(char **)((char *)obj + 0x5C);
    dx = *(s32 *)((char *)target + 0x14) - *(s32 *)(origin + 0x54);
    dy = *(s32 *)((char *)target + 0x18) - *(s32 *)(origin + 0x58);
    dz = *(s32 *)((char *)target + 0x1C) - *(s32 *)(origin + 0x5C);
    if (n == 0)
    {
        return;
    }
    step_x = dx / 3; step_y = dy / 3; step_z = dz / 3;
    do
    {
        if (*(u16 *)p != 0)
        {
            *(u16 *)(p + 0x4) = *(u16 *)(p + 0x4) + (*(u16 *)(p + 0xA) + step_x);
            *(u16 *)(p + 0x6) = *(u16 *)(p + 0x6) + (*(u16 *)(p + 0xC) + step_y);
            *(u16 *)(p + 0x8) = *(u16 *)(p + 0x8) + (*(u16 *)(p + 0xE) + step_z);
            timer = *(u16 *)(p + 0x2);
            *(u16 *)(p + 0x2) = timer + 0xFFFF;
            if (timer == 0)
            {
                if (*(u16 *)(p + 0x12) != 7)
                {
                    *(u16 *)(p + 0x12) = *(u16 *)(p + 0x12) + 1;
                }
                *(u16 *)(p + 0x2) = *(u16 *)(p + 0x16);
            }
            if (*(u8 *)(p + 0x14) != 0)
            {
                *(u8 *)(p + 0x14) = *(u8 *)(p + 0x14) + *(u8 *)(p + 0x15);
            }
            *(u16 *)(p + 0x18) = *(u16 *)(p + 0x18) + *(u16 *)(p + 0x1A);
            if (*(u16 *)(p + 0x1C) < *(u16 *)(p + 0x18))
            {
                *(u16 *)(p + 0x18) = *(u16 *)(p + 0x1C);
            }
            life = *(u16 *)(p + 0x10);
            *(u16 *)(p + 0x10) = life + 0xFFFF;
            if (life == 0)
            {
                *(u16 *)p = 0;
            }
        }
        p += 0x24;
    } while (count-- != 0);
}
