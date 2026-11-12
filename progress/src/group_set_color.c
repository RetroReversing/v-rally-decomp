typedef struct { u8 start; u8 count; } Group;
typedef struct {
    u8 pad0[0xD0];
    Group groups[10];
    void *items[1];
} GroupTable;
typedef struct {
    u8 pad0[0xA];
    s8 group;
} GroupOwner;

void font_set_color(void *item, s32 r, s32 g, s32 b, u8 a);
extern GroupTable *gSelectState;

/* Sets the colour of every item in the owner's group. */
void group_set_color(GroupOwner *owner, u8 r, u8 g, u8 b, u8 a) {
    u8 i;

    for (i = gSelectState->groups[owner->group].start;
         i < gSelectState->groups[owner->group].start + gSelectState->groups[owner->group].count; i++) {
        font_set_color((void *)(gSelectState->items[i]), (s32)((u8)(r)), (s32)((u8)(g)), (s32)((u8)(b)), (u8)(a));
    }
}
