typedef void (*SpriteHook)(void *);
typedef struct { u8 pad[0x7A]; s16 x7A; u8 pad2[0x28]; s32 xA4; void *xA8; } Btn3CD18;
typedef struct { u8 pad[8]; s16 x; s16 y; s16 w; s16 h; } Rect3CD18;
typedef struct { u8 pad[0xC]; s32 type; u8 pad2[0x168]; Rect3CD18 *rect; } Obj3CD18;
typedef struct { u8 pad[0xE]; u16 mode; u8 pad2[2]; u16 flags; u8 pad3[0xA]; u16 x1E; } Mgr3CD18;
s32 getTexturePack(void *, s32);
void *sprite_create(void *, s16, s16, s32, SpriteHook, s32);
Obj3CD18 *find_object_by_id(s32);
void obj_sync_counter(void *);
void obj_copy_child_count(void *);
void objUpdateNeighborFlagByCount(void *);
extern char gGameState[];
extern Mgr3CD18 *gRecords;
extern Obj3CD18 *g_camera;
#define gCurCount (*(u8 *)(gGameState + 0x6C00))
#define D_800ADFE1 (*(u8 *)(gGameState + 0x6C01))

#define BTN_A(X, Y, CB) \
    btn = ((Btn3CD18 *)sprite_create((void *)(parent), X, Y, 2, (SpriteHook)(CB), 0)); \
    name = (u8 *)slotInfo + 0x4C; \
    btn->xA4 = getTexturePack(name, 0); \
    btn->xA8 = g_camera;
#define BTN_B(X, Y, CB) \
    btn = ((Btn3CD18 *)sprite_create((void *)(parent), X, Y, 2, (SpriteHook)(CB), 0)); \
    btn->xA4 = getTexturePack(name, 0); \
    btn->x7A = 15; \
    btn->xA8 = g_camera;
#define BTN_C(X, Y, CB) \
    btn = ((Btn3CD18 *)sprite_create((void *)(parent), X, Y, 2, (SpriteHook)(CB), 0));

/* Lays out the button row for the selected slot: picks a layout from the
 * record mode and the slot's object, places three sprite buttons along the
 * object's rect, and sets each button's texture and countdown value. */
void layout_slot_buttons(void *parent, void *slotInfo, u16 slotIndex)
{

    Btn3CD18 *btn;
    Obj3CD18 *slotObj;
    Rect3CD18 *rect;
    s32 left;
    s32 top;
    s32 innerTop;
    s32 innerX;
    s32 innerW;
    s32 bottom;
    s32 innerH;
    u16 rightX;
    s16 btnY;

    u8 *countPtr;

    if (gRecords->x1E == 7) {
        return;
    }
    countPtr = &gCurCount;
    if (*countPtr < 2) {
        return;
    }
    slotObj = find_object_by_id(((slotIndex - 1) * 2) | 1);
    rect = slotObj->rect;
    g_camera = slotObj;
    left = rect->x;
    top = rect->y;
    bottom = rect->h;
    innerX = left + 0x14;
    innerW = rect->w - 0x10;
    innerTop = top + 6;
    innerH = bottom - 8;
    switch (gRecords->mode) {
    case 1:
        if (D_800ADFE1 || gRecords->x1E == 0) {
            rightX = innerX + innerW;
            btnY = top + 0x10;
{ u8 *name; 
            BTN_A(rightX - 0x38, btnY, obj_sync_counter)
            BTN_B(rightX - 0x31, btnY, objUpdateNeighborFlagByCount)
            BTN_C(rightX - 0x2A, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
        } else {
            rightX = innerX + innerW;
            btnY = top + 0x10;
{ u8 *name; 
            BTN_A(rightX - 0x38, btnY, obj_copy_child_count)
            BTN_B(rightX - 0x31, btnY, 0)
            BTN_C(rightX - 0x2A, btnY, 0)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
        }
        break;
    case 2:
        if (gRecords->x1E == 0) {
            if (gRecords->flags & 1) {
                innerX = left;
                btnY = top + 0x10;
{ u8 *name; 
                BTN_A(innerX, btnY, obj_sync_counter)
                BTN_B(innerX + 7, btnY, objUpdateNeighborFlagByCount)
                BTN_C(innerX + 14, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            } else if (slotObj->type == 3) {
                if (D_800ADFE1) {
                    rightX = innerX + innerW;
                    btnY = top + 0x10;
{ u8 *name; 
                    BTN_A(rightX - 0x32, btnY, obj_sync_counter)
                    BTN_B(rightX - 0x32 + 7, btnY, objUpdateNeighborFlagByCount)
                    BTN_C(rightX - 0x32 + 14, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
                } else {
                    rightX = innerX + innerW;
                    btnY = top + 0x10;
{ u8 *name; 
                    BTN_A(rightX - 0x32, btnY, obj_copy_child_count)
                    BTN_B(rightX - 0x32 + 7, btnY, 0)
                    BTN_C(rightX - 0x32 + 14, btnY, 0)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
                }
            } else if (D_800ADFE1) {
                btnY = top + 0x10;
{ u8 *name; 
                BTN_A(innerX, btnY, obj_sync_counter)
                BTN_B(left + 0x1B, btnY, objUpdateNeighborFlagByCount)
                BTN_C(left + 0x22, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            } else {
                btnY = top + 0x10;
{ u8 *name; 
                BTN_A(innerX, btnY, obj_copy_child_count)
                BTN_B(left + 0x1B, btnY, 0)
                BTN_C(left + 0x22, btnY, 0)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            }
        } else if (gRecords->flags & 1) {
            if (slotObj->type == 1) {
                innerTop = top + 8;
            }
            rightX = innerX;
            if (D_800ADFE1) {
                btnY = innerTop + innerH - 0x15;
{ u8 *name; 
                BTN_A(left, btnY, obj_sync_counter)
                BTN_B(rightX - 0x14 + 7, btnY, objUpdateNeighborFlagByCount)
                BTN_C(rightX - 0x14 + 14, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            } else {
                btnY = innerTop + innerH - 0x15;
{ u8 *name; 
                BTN_A(left, btnY, obj_copy_child_count)
                BTN_B(rightX - 0x14 + 7, btnY, 0)
                BTN_C(rightX - 0x14 + 14, btnY, 0)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            }
        } else {
            if (slotObj->type == 3) {
                innerX = left + 6;
            }
            if (D_800ADFE1) {
                btnY = bottom - 0x26;
{ u8 *name; 
                BTN_A(innerX, btnY, obj_sync_counter)
                BTN_B(innerX + 7, btnY, objUpdateNeighborFlagByCount)
                BTN_C(innerX + 14, btnY, objUpdateNeighborFlagByCount)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            } else {
                btnY = bottom - 0x26;
{ u8 *name; 
                BTN_A(innerX, btnY, obj_copy_child_count)
                BTN_B(innerX + 7, btnY, 0)
                BTN_C(innerX + 14, btnY, 0)
    btn->xA4 = getTexturePack(name, 0);
    btn->xA8 = g_camera;
    btn->x7A = *countPtr - 1;
}
            }
        }
        break;
    default:
        return;
    }

}
