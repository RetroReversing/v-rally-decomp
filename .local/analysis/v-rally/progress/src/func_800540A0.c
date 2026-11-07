typedef struct {
    u8 pad0[6];
    u8 name[6];
    u8 active;
    u8 pad0D[0x40 - 0x0D];
} Item;

typedef struct {
    u8 pad0[0x14];
    u16 count;
    u8 pad16[0x2C - 0x16];
    Item items[1];
} Group;

typedef struct {
    u8 name[40];
} Entry;

typedef struct {
    u8 pad0[0x44];
    Entry entries[5];
} Cfg;

typedef struct {
    u8 score;
    u8 pad[4];
} Slot;

extern u16 D_800D0620;
extern u16 D_800D0622;
extern u16 D_800D0624;
extern u16 D_800D0626;
extern Group *D_800D0638;
extern Group *D_800D063C;
extern Group *D_800D0640;
extern Group *D_800D0644;
extern Cfg *D_800C35A0;
extern Slot D_800B0D80[];
s32 func_80098180(const u8 *, const u8 *);

#define SCAN(cnt, grp)                                                         \
    g = grp;                                                                   \
    for (i = 0; i < cnt; i++) {                                                \
        for (j = 0; j < g->count; j++) {                                       \
            if (g->items[j].active == 1) {                                     \
                for (k = 0; func_80098180(D_800C35A0->entries[k].name,         \
                                          g->items[j].name) != 0 && k < 4;     \
                     k++) {                                                    \
                }                                                              \
                D_800B0D80[k].score += 4;                                      \
                D_800B0D80[4].score += 4;                                      \
            }                                                                  \
        }                                                                      \
    }

void func_800540A0(void)
{
    u8 i;
    u8 j;
    u8 k;
    Group *g;

    SCAN(D_800D0620, D_800D0638);
    SCAN(D_800D0622, D_800D063C);
    SCAN(D_800D0624, D_800D0640);
    SCAN(D_800D0626, D_800D0644);
}
