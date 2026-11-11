typedef void (*SpriteHook)(void *);
s32 getTexturePack();
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
s32 str_ncasecmp();
void func_8003FD04(void *);
void func_8004C04C(void *);
extern char D_800A4C00[];
extern char D_800A4C08[];
extern char gStreamState[];

/* Creates the sprite for a named object at arg1 (its name sits at +0x4C) and stores the name id at sprite+0xA4. Objects of the special kind (type 7) are matched against a second tag table. Returns NULL when no tag matches. */
void *func_80040084(s32 parent, s32 record, s32 flags) {
    void *sprite;
    s32 nameId;
    s32 temp_s0;

    sprite = NULL;
    if (*(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x1E) != 7) {
        if (str_ncasecmp(D_800A4C00, record + 0x4C, 4) == 0) {
            sprite = ((void *)sprite_create((void *)(parent), 0, 0, flags & 0xFFFF, func_8004C04C, 1));
        } else {
            sprite = ((void *)sprite_create((void *)(parent), 0, 0, flags & 0xFFFF, (SpriteHook)(0), 1));
        }
        *(s32 *)((char *)sprite + 0xA4) = getTexturePack(record + 0x4C, 0);
    } else {
        temp_s0 = record + 0x4C;
        if (str_ncasecmp(D_800A4C00, temp_s0, 4) == 0) {
            sprite = ((void *)sprite_create((void *)(parent), 0, 0, flags & 0xFFFF, func_8004C04C, 1));
            *(s32 *)((char *)sprite + 0xA4) = getTexturePack(temp_s0, 0);
        } else if (str_ncasecmp(D_800A4C08, temp_s0, 4) == 0) {
            nameId = getTexturePack(temp_s0, 0);
            sprite = ((void *)sprite_create((void *)(parent), 0, 0, flags & 0xFFFF, func_8003FD04, 1));
            *(s32 *)((char *)sprite + 0xA4) = nameId;
        }
    }
    return sprite;
}
