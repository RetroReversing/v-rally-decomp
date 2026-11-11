s32 voice_alloc_request(); s32 voiceKeyIsFree(); s32 voiceSetVolumeByKey(); s64 osGetTime(void); s32 func_80098090(); s32 rand_seed(u32); extern char gStreamState[];

/* Ticks the spawn timers in the spawn table. Each active slot's timer counts
 * down; while a slot's roll is below its chance value the slot's three fade
 * levels step down (floored at 90) and the chance steps up. When a timer
 * reaches zero it is reloaded to 0x113 and an object of the slot's type is
 * placed in a free object slot. */
void update_spawn_timers(void)
{
    u32 roll;
    s32 i;
    s32 idx;
    u8 *cur;
    u16 *timer;
    char *base;
    u16 t;
    u8 a, b, c, d;
    s32 obj;

    rand_seed((u32)osGetTime());
    roll = func_80098090() % 100;
    base = gStreamState + 0x331b;
    i = 0;
    if (*(u8 *)base) {
        cur = (u8 *)(base + 7);
        do {
            do {
                idx = i & 255;
                timer = (u16 *)(idx * 2 + (u32)cur);
                t = *timer;
                if (t) *timer = t - 1;
                if (roll < *(u8 *)(gStreamState + 0x331f + idx)) goto next;
                a = cur[-3] - 1;
                cur[-3] = a;
                roll = 0;
                if (a < 90) cur[-3] = 90;
                b = cur[-2] - 1;
                cur[-2] = b;
                if (b < 90) cur[-2] = 90;
                c = cur[-1] - 1;
                cur[-1] = c;
                if (c < 90) cur[-1] = 90;
                d = *(u8 *)(gStreamState + 0x331f + idx) + 4;
                *(u8 *)(gStreamState + 0x331f + idx) = d;
                if (d >= 99) *(u8 *)(gStreamState + 0x331f + idx) = 92;
            } while (0);
            if (*timer == 0) {
                *timer = 0x113;
                b = *(u8 *)(gStreamState + 0x331c + idx);
                obj = *(s32 *)(gStreamState + 0x7f26) + b * 12;
                if (voiceKeyIsFree(obj)) {
                    voice_alloc_request(obj);
                    voiceSetVolumeByKey(obj, (s32) *(f32 *)(cur + 0x14));
                }
            }
next:
            i++;
        } while ((u8)i < *(u8 *)(gStreamState + 0x331b));
    }
}
