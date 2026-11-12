typedef struct { u8 b[8]; } Key8;
typedef struct {
    u8 pad0[0x10];
    s32 min_x, min_y, max_x, max_y, min_z, max_z;
    u32 depth;
    s32 slot;
} Ent;
typedef struct {
    Ent *ents;
    u16 n;
} EntList;
typedef struct {
    Key8 key;
    u32 val;
} Rec;
typedef struct {
    u8 pad0[0x20];
    u16 count;
    u16 last;
} RecTable;
extern void add_pos_bias_words(s32, u32);
extern f32 vtx_scale[];
extern u32 g_max_depth;
extern s32 g_pos_bias;
extern u32 g_rec_val;
extern EntList *g_prepared_list;

/* Prepares the entity list for the frame. Appends (key, g_rec_val) to the
 * record table, scales each entity's bounds by vtx_scale (x and z get a
 * 500-unit margin), biases its slot, and tracks the largest depth seen. */
EntList *ent_prepare_list(EntList *list, RecTable *table, Key8 *key)
{
    EntList *h;
    Ent *e;
    s32 i;
    Rec *rec;

    g_max_depth = 0;
#ifdef PORT
    add_pos_bias_words((uintptr_t)list, 1);
#else
    add_pos_bias_words((s32)list, 1);
#endif
    table->last = table->count;
    rec = (Rec *)((u8 *)table + (table->count * 0x38 + 0x3C));
    rec->key = *key;
    rec->val = g_rec_val;
    table->count++;
    h = list;
    e = h->ents;
    for (i = 0; i < h->n; i++) {
        e[i].slot += g_pos_bias;
        e[i].min_x = (s32)(e[i].min_x * vtx_scale[0]) - 500;
        e[i].max_x = (s32)(e[i].max_x * vtx_scale[0]) + 500;
        e[i].min_y = (s32)(e[i].min_y * vtx_scale[1]);
        e[i].max_y = (s32)(e[i].max_y * vtx_scale[1]);
        e[i].min_z = (s32)(e[i].min_z * vtx_scale[2]) - 500;
        e[i].max_z = (s32)(e[i].max_z * vtx_scale[2]) + 500;
        add_pos_bias_words(e[i].slot, e[i].depth);
        {
            u32 t = e[i].depth;
            if (g_max_depth < t) {
                g_max_depth = t;
            }
        }
    }
    g_prepared_list = h;
    return h;
}
