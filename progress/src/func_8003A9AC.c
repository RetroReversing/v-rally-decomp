typedef void (*SpriteHook)(void *);
extern s32 g_camera;
s32 getTexturePack();
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern void func_8003A73C(void *);

/* Spawns a row of sprites under parent at (x, y): three rounds, each adding a sprite with the
 * arg3 hook and stepping x by 7. Round 1 adds a second sprite with the default hook (func_8003A73C)
 * at a 4-unit step. Each sprite records the timer, the camera and, if given, a 4-byte colour. */
void func_8003A9AC(void *parent, s32 x, s32 y, SpriteHook hook, s32 timerOffset, u16 flags, u8 *color)
{
    s32 var_s2;
    s32 var_s5;
    s32 var_s4;
    u32 var_s3;
    u16 var_s6;
    u8 *var_s0;
    SpriteHook var_fp;
    s32 ret;
    s32 d;

    var_s2 = x;
    var_fp = hook;
    var_s6 = flags;
    var_s5 = (s16)y;
    var_s4 = timerOffset + 0x4C;
    var_s3 = 0;
    do {
        var_s0 = ((void *)sprite_create(parent, (s16)var_s2, (s16)var_s5, 2, (SpriteHook)(var_fp), 0));
        *(u16 *)(var_s0 + 0x78) = var_s3;
        ret = getTexturePack(var_s4, 0);
        d = g_camera;
        var_s2 += 7;
        *(s32 *)(var_s0 + 0xA4) = ret;
        *(u16 *)(var_s0 + 0x76) = var_s6;
        *(s32 *)(var_s0 + 0xA8) = d;
        if (color != NULL) {
            var_s0[0x90] = color[0];
            var_s0[0x91] = color[1];
            var_s0[0x92] = color[2];
            var_s0[0x93] = color[3];
        }
        if (var_s3 == 1) {
            var_s0 = ((void *)sprite_create(parent, (s16)var_s2, (s16)var_s5, 2, func_8003A73C, 0));
            ret = getTexturePack(var_s4, 0);
            d = g_camera;
            var_s2 += 4;
            *(s32 *)(var_s0 + 0xA4) = ret;
            *(u16 *)(var_s0 + 0x76) = var_s6;
            *(s16 *)(var_s0 + 0x7A) = 0xC;
            *(s32 *)(var_s0 + 0xA8) = d;
            if (color != NULL) {
                var_s0[0x90] = color[0];
                var_s0[0x91] = color[1];
                var_s0[0x92] = color[2];
                var_s0[0x93] = color[3];
            }
        }
        var_s3++;
    } while (var_s3 < 3);
}
