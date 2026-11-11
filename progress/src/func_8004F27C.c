typedef struct { u8 pad50[0x50]; s32 count; u8 pad54[0x14]; void *items; } ItemList;
typedef struct { void *obj; s16 state; u16 kind; } ItemSlot;
typedef struct { u8 pad1c[0x1c]; u16 type; } ItemObj;
s32 heapFreeBlock(void *);

/* Frees the heap blocks of every idle item in the list: its object, when the object's type is 0 or 5, and the slot itself when its kind is 1. */
void func_8004F27C(ItemList *list) {
    u32 i;
    s32 count;
    ItemSlot *slot;
    ItemSlot *base;
    u16 type;
    ItemObj *obj;
    char pad[8];

    count = list->count;
    base = list->items;
    i = 0;
    if (count != 0) do {
        slot = &base[i];
        if (slot->state == 0) {
            obj = slot->obj;
            type = obj->type;
            if ((type == 5) | (type == 0)) heapFreeBlock(obj);
            if (slot->kind == 1) heapFreeBlock(slot);
        }
        i++;
    } while (i < list->count);
}
