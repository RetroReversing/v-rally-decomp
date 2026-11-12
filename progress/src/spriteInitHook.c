extern u8 gSpriteInitStage;

/* Sprite callback installed by func_80040084 for matched textures. Until gSpriteInitStage reaches 2 it only advances the stage; after that it sets bit 4 in the sprite flags (+0x80) unless bits 0x44 are already set. */
void spriteInitHook(void *sprite) {
    s32 spriteFlags;

    if ((u8) gSpriteInitStage >= 2U) {
        spriteFlags = *(s32 *)((char *)sprite + 0x80);
        if (!(spriteFlags & 0x44)) {
            *(s32 *)((char *)sprite + 0x80) = (s32) (spriteFlags | 4);
        }
    } else {
        gSpriteInitStage += 1;
    }
}
