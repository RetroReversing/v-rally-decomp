typedef void (*SpriteHook)(void *);
typedef struct { u8 flags; u8 pad[0x27]; } GEntry;
typedef struct {
    u8 pad0[0xE]; u16 count; u8 pad10[2]; u16 flags12; u8 pad14[0xA]; u16 mode; u8 pad20[0x11]; u8 sel[0x17]; GEntry entries[1];
} GState;
extern GState *gRecords;
typedef struct { s16 pad[4]; s16 x, y, w, h; } Rect;
typedef struct Node { u8 pad0[0xC]; s32 kind; u8 pad10[0x168]; Rect *rect; } Node;
extern Node *g_camera;
typedef struct Obj { u8 pad0[0x76]; s16 unk76, unk78, unk7A; u8 pad7C[0x10]; struct Obj *unk8C; u8 pad90[0x14]; void *unkA4; Node *unkA8; } Obj;
extern u8 gCurCount;
extern u8 D_800ADFE1;
typedef void (*Cb)();
Node *find_object_by_id(s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
void *getTexturePack(s32, s32);
void objUpdateNeighborFlag(void *);
void obj_update_layout_flags(void *);
void objUpdateNeighborFlagByCount(void *);
void obj_update_flag_vs_count(void *);

/* Lays out the sprite buttons for every slot in the record list. The layout
 * depends on each slot's mode, its object kind and the selection flags, and
 * the buttons are created with the slot's texture pack at slotInfo+0x4C. */
void layout_slot_sprites(void *layer, s32 slotInfo)
{
    GState *rec = gRecords;
    u32 slotIdx;
    s32 innerTop, innerW, innerH;
    u32 slotCount;
    s32 kindOff;
    s32 left;
    Node *node;
    Rect *rect;
    Obj *btn, *btn2;
    s32 top, width, innerX, bottomY;
    s16 btnX, btnY;

    if (rec->mode == 7)
        return;
    kindOff = 0;
    slotIdx = 1;
    slotCount = rec->count;
    if (slotCount == 0)
        return;
#define slotTex (slotInfo + 0x4C)
    do {
        node = find_object_by_id(((slotIdx - 1) * 2) | 1);
        rect = node->rect;
        left = rect->x;
        top = rect->y;
        g_camera = node;
        innerX = left + 20;
        innerTop = top + 6;
        width = rect->w;
        innerW = width - 16;
        innerH = rect->h - 8;
        rec = gRecords;
        switch (rec->count) {
        case 1:
            if (rec->mode == 0) {
                if (gCurCount >= 2) {
                    if (!(rec->entries[rec->sel[1]].flags & 1)) goto flags4; {
                        btnX = width - 0x47;
                        btnY = top + 0x11;
                        btn = ((Obj *)sprite_create((void *)(layer), btnX, btnY, (s16)(5), objUpdateNeighborFlagByCount, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), btnX, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unk7A = 5;
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), width - 0x31, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unkA8 = g_camera;
                    }
                }
                rec = gRecords;
                {s32 index=((volatile GState*)rec)->sel[1]; index=index*5; index <<=3; rec=(GState*)((u8*)rec+index); if(rec->entries[0].flags & 1) {
                    btnY = top + 7;
                    btn = ((Obj *)sprite_create((void *)(layer), (u16)innerW + (u16)-0x4D, btnY, (s16)(5), (SpriteHook)(NULL), 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn = ((Obj *)sprite_create((void *)(layer), width - 0x74, btnY, (s16)(5), (SpriteHook)(NULL), 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn->unk7A = 1;
                    btn = ((Obj *)sprite_create((void *)(layer), left + 0x32, btnY, (s16)(5), (SpriteHook)(NULL), 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn->unk7A = 1;
                }}
flags4:
                rec = gRecords;
                {s32 index=((volatile GState*)rec)->sel[1]; index=index*5; index <<=3; rec=(GState*)((u8*)rec+index); if(rec->entries[0].flags & 4) {
                    bottomY = innerTop + innerH;
                    btn = ((Obj *)sprite_create((void *)(layer), innerX, bottomY - 0x12, (s16)(5), obj_update_layout_flags, 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn->unk76 = 4;
                    btn->unkA8 = g_camera;
                    btn2 = ((Obj *)sprite_create((void *)(layer), innerX + 0x14, bottomY - 0x44, (s16)(5), (SpriteHook)(NULL), 1));
                    btn2->unkA4 = getTexturePack(slotTex, 0);
                    btn2->unk7A = 4;
                    btn2->unkA8 = g_camera;
                    btn->unk8C = btn2;
                }}
            } else {
                if (rec->entries[rec->sel[1]].flags & 1) {
                    if (D_800ADFE1) {
                        btnX = width - 0x47;
                        btnY = top + 0x11;
                        btn = ((Obj *)sprite_create((void *)(layer), btnX, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unk7A = 5;
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), width - 0x31, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), btnX, btnY, (s16)(5), objUpdateNeighborFlagByCount, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unkA8 = g_camera;
                    } else {
                        btn = ((Obj *)sprite_create((void *)(layer), width - 0x47, top + 0x11, (s16)(5), (SpriteHook)(NULL), 1));
                        btn->unkA4 = getTexturePack(slotInfo + 0x4C, 0);
                        btn->unkA8 = g_camera;
                    }
                    btnY = (u16)(innerTop + innerH) + (u16)-0x17;
                    btn = ((Obj *)sprite_create((void *)(layer), innerX + 0xA, btnY, (s16)(5), objUpdateNeighborFlag, 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn->unk7A = 1;
                    btn->unkA8 = g_camera;
                    btn = ((Obj *)sprite_create((void *)(layer), innerX + 0x21, btnY, (s16)(5), objUpdateNeighborFlag, 1));
                    btn->unkA4 = getTexturePack(slotTex, 0);
                    btn->unkA8 = g_camera;
                }
            }
            break;
        case 2:
            if (rec->mode == 0) {
                if (rec->flags12 & 1) {
                    innerX = left;
                    if (rec->entries[rec->sel[slotIdx]].flags & 1) {
                        btnY = top + 0x11;
                        btn = ((Obj *)sprite_create((void *)(layer), innerX, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unk7A = 5;
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), innerX + 0x17, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unkA8 = g_camera;
                        btn = ((Obj *)sprite_create((void *)(layer), innerX - kindOff, top + 7, (s16)(5), (SpriteHook)(NULL), 1));
                        btn->unkA4 = getTexturePack(slotTex, 0);
                        btn->unk7A = 1;
                    }
                } else {
                    if (rec->entries[rec->sel[slotIdx]].flags & 1) {
                        kindOff = (node->kind == 3) ? 14 : 0;
                        switch(node->kind){case 3:{
                            if (D_800ADFE1) {
                                s32 sx = innerX + innerW;
                                btnY = top + 0x11;
                                btn = ((Obj *)sprite_create((void *)(layer), sx - 0x46, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                                btn->unkA4 = getTexturePack(slotTex, 0);
                                btn->unk7A = 5;
                                btn->unkA8 = g_camera;
                                btn = ((Obj *)sprite_create((void *)(layer), (u16)sx + (u16)-0x2F, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                                btn->unkA4 = getTexturePack(slotTex, 0);
                                btn->unkA8 = g_camera;
                            }
                            btn = ((Obj *)sprite_create((void *)(layer), innerX + innerW - 0x5E, top + 7, (s16)(5), (SpriteHook)(NULL), 1));
                            btn->unkA4 = getTexturePack(slotInfo + 0x4C, 0);
                            btn->unk7A = 1;
                        }break;default:{
                            if (D_800ADFE1) {
                                btnY = top + 0x11;
                                btn = ((Obj *)sprite_create((void *)(layer), innerX, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                                btn->unkA4 = getTexturePack(slotTex, 0);
                                btn->unkA8 = g_camera;
                                btn->unk7A = 5;
                                btn = ((Obj *)sprite_create((void *)(layer), left + 0x2B, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                                btn->unkA4 = getTexturePack(slotTex, 0);
                                btn->unkA8 = g_camera;
                            }
                            btn = ((Obj *)sprite_create((void *)(layer), innerX, top + 7, (s16)(5), (SpriteHook)(NULL), 1));
                            btn->unkA4 = getTexturePack(slotInfo + 0x4C, 0);
                            btn->unk7A = 1;
                        }break;}
                    }
                }
            } else {
                if (rec->flags12 & 1) {
                    if (rec->entries[rec->sel[slotIdx]].flags & 1) {
                        if (node->kind == 1)
                            innerTop = top + 8;
                        if (D_800ADFE1) {
                            btnY = innerTop + innerH - 0x15;
                            btn = ((Obj *)sprite_create((void *)(layer), left, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                            btn->unkA4 = getTexturePack(slotTex, 0);
                            btn->unkA8 = g_camera;
                            btn->unk7A = 5;
                            btn = ((Obj *)sprite_create((void *)(layer), left + 0x17, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                            btn->unkA4 = getTexturePack(slotTex, 0);
                            btn->unkA8 = g_camera;
                        }
                    }
                } else {
                    if (rec->entries[rec->sel[slotIdx]].flags & 1) {
                        if (node->kind == 3)
                            innerX = left + 6;
                        if (D_800ADFE1) {
                            btnY = (u16)innerH + (u16)-0x1D;
                            btn = ((Obj *)sprite_create((void *)(layer), innerX, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                            btn->unkA4 = getTexturePack(slotTex, 0);
                            btn->unk7A = 5;
                            btn->unkA8 = g_camera;
                            btn = ((Obj *)sprite_create((void *)(layer), innerX + 0x17, btnY, (s16)(5), obj_update_flag_vs_count, 1));
                            btn->unkA4 = getTexturePack(slotTex, 0);
                            btn->unkA8 = g_camera;
                        }
                    }
                }
            }
            break;
        }
        slotIdx++;
    } while (slotIdx <= slotCount);
}
