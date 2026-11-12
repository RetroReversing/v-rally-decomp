/* A rectangle entry: position, size and 10 bytes of unused data. */
typedef struct {
    s16 x;
    s16 y;
    u8 w;
    u8 h;
    u8 pad[10];
} RectEnt;
/* Four corners of a rectangle as x[] / y[] pairs. */
typedef struct {
    s16 x[4];
    s16 y[4];
} RectQuad;
/* Source list: entry count followed by the entries. */
typedef struct {
    u8 unk0;
    u8 count;
    u8 pad[6];
    RectEnt ents[1];
} RectList;
typedef struct {
    u8 pad0[8];
    void *ptr;
} RectItem;
typedef struct {
    u8 pad0[8];
    u8 flag;
    u8 pad9[7];
    RectItem *item;
    u8 pad14[4];
    RectEnt *data;
    RectQuad quads[128];
    f32 scale[3];
} RectSet;
extern s16 bswap16(s32);
extern void *poolAlloc(s32, s32);
extern u8 *memcpy(u8 *, u8 *, s32);

/* Builds a RectSet from a rectangle list: copies the entries, converts each entry's x and y
 * with bswap16, and fills the quad corners of every entry whose x is not -128
 * (the 'no rectangle' marker). Scales start at 1.0. */
RectSet *make_rect_set(RectList *src)
{
    RectSet *set;
    RectItem *item;
    u8 count;
    u8 i;
    u32 size;
    RectQuad quad;

    set = poolAlloc(1, sizeof(RectSet));
    item = poolAlloc(1, 0x1C);
    count = src->count;

    size = count * sizeof(RectEnt);
    item->ptr = &src->ents[count];
    set->item = item;
    set->data = poolAlloc(1, size);
    memcpy((i = 0, (u8 *)set->data), (u8 *)src->ents, size);
    for (; i < count; i++) {
        set->data[i].x = bswap16(set->data[i].x);
        set->data[i].y = bswap16(set->data[i].y);
    }
    set->flag = 0;
    for (i = 0; i < 3; i++) {
        set->scale[i] = 1.0f;
    }
    for (i = 0; i < count; i++) {
        s16 x = set->data[i].x;
        if (x != -128) {
            set->quads[i].x[0] = x;
            set->quads[i].y[0] = set->data[i].y + set->data[i].h;
            set->quads[i].x[1] = set->data[i].x + set->data[i].w;
            set->quads[i].y[1] = set->data[i].y + set->data[i].h;
            set->quads[i].x[2] = set->data[i].x + set->data[i].w;
            set->quads[i].y[2] = set->data[i].y;
            set->quads[i].x[3] = set->data[i].x;
            set->quads[i].y[3] = set->data[i].y;
        }
        quad = set->quads[i];
    }
    return set;
}
