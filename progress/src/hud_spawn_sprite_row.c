typedef void (*SpriteHook)(void *);
s32 getTexturePack();
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
extern char gStreamState[];
extern s32 sprite_hook_find_record;

/* Spawns a row of four sprites above the HUD slot of the local car, when its flag bit 4 is
 * set and its state is neither 0 nor 7 and its mode is 1. Each sprite gets a value from
 * getTexturePack (base + 0x4C) and an index 1..4. */
void hud_spawn_sprite_row(s32 owner, s32 base)
{
    u8 *car;
    u8 *info;
    u32 i;
    s32 y;
    s32 x;
    void *sprite;
    s32 value;
    u32 slotOff;

    car = *(u8 **)(gStreamState + 0x32F2);
    slotOff = car[0x32] * 0x28;
    if (*(u8 *)(car + slotOff + 0x48) & 4) {
        if ((*(u16 *)(car + 0x1E) != 0) & (*(u16 *)(car + 0x1E) != 7)) {
            if (*(u16 *)(car + 0xE) == 1) {
                info = *(u8 **)(*(u8 **)(gStreamState + 0x7CD6) + 0x178);
                y = *(u16 *)(info + 0xA) + 6;
                x = (*(u16 *)(info + 0x8) + 0x36) << 16;
                for (i = 0; i < 4; i++) {
                    sprite = ((void *)sprite_create((void *)(owner), x >> 16, (s16)(y + i * 11 - 2), 5, &sprite_hook_find_record, 1));
                    value = getTexturePack(base + 0x4C, 0);
                    *(s32 *)((u8 *)sprite + 0xA4) = value;
                    *(u16 *)((u8 *)sprite + 0x78) = i + 1;
                }
            }
        }
    }
}
