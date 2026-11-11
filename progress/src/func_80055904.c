typedef struct { u8 r, g, b, a; } Col;
typedef struct { s8 a, b; } Pair;
typedef struct {
    Col c0, c1, c2;
    u16 x, y, z;
    Pair n[3];
    u16 id;
} SrcEntry;
typedef struct {
    Col c0, c1, c2, c3;
    u16 x, y, z;
    s16 w;
    Pair n[3];
    u8 e, f;
    u16 id;
} DstEntry;
typedef struct { SrcEntry *items; u16 count; } SrcEntryList;
s32 strCmp(u8 *, u8 *);
extern u8 D_800A1300[];
extern u8 D_800A1308[];
extern u8 gOrderState[];

/* Converts a list of source entries into destination entries, writing through the
 * cursor *dst and advancing it. Each entry copies the geometry and normals, sets its first
 * colour to 6-alpha and clears the fourth colour. Entries whose name (looked up by id, 20
 * bytes per name) matches either special name are painted white. */
void func_80055904(DstEntry **dst, SrcEntryList *list)
{
    SrcEntry *src = list->items;
    u16 count = list->count;
    s32 i;
    u8 *name;

    for (i = 0; i < count; src++, i++) {
        (*dst)->x = src->x;
        (*dst)->y = src->y;
        (*dst)->z = src->z;
        (*dst)->w = 0;
        (*dst)->c0 = src->c0;
        (*dst)->c0.a = 6;
        (*dst)->c1 = src->c1;
        (*dst)->c2 = src->c2;
        (*dst)->c3.r = 0;
        (*dst)->c3.g = 0;
        (*dst)->c3.b = 0;
        (*dst)->c3.a = 0;
        (*dst)->n[0] = src->n[0];
        (*dst)->n[1] = src->n[1];
        (*dst)->n[2] = src->n[2];
        (*dst)->e = 0;
        (*dst)->f = 0;
        (*dst)->id = src->id;
        name = *(u8 **)(gOrderState + 0x237C) + src->id * 0x14;
        if (strCmp(name, D_800A1300) == 0 || strCmp(name, D_800A1308) == 0) {
            (*dst)->c0.r = 0xFF;
            (*dst)->c0.g = 0xFF;
            (*dst)->c0.b = 0xFF;
            (*dst)->c1.r = 0xFF;
            (*dst)->c1.g = 0xFF;
            (*dst)->c1.b = 0xFF;
            (*dst)->c1.a = 0xFF;
            (*dst)->c2.r = 0xFF;
            (*dst)->c2.g = 0xFF;
            (*dst)->c2.b = 0xFF;
            (*dst)->c2.a = 0xFF;
        }
        (*dst)++;
    }
}
