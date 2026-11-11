/* Stores the RGBA colour bytes at offset 4 of an item. */
typedef struct {
    u8 pad0[4];
    u8 r, g, b, a;
} ItemColor;

void func_8000C22C(void *item, s32 r, s32 g, s32 b, u8 a) {
    ItemColor *color = (ItemColor *)item;

    color->r = (u8)r;
    color->g = (u8)g;
    color->b = (u8)b;
    color->a = (u8)a;
}
