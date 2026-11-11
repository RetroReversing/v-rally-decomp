typedef struct {u8 pad0[2]; s16 index; u8 pad4[12]; u8 *items;} Table;
typedef struct {u8 pad0[13]; u8 a,b; u8 pad15[5];} Item;
typedef struct {u8 pad0[0x228]; s8 idx; u8 pad229[2]; u8 flag; u8 pad22c[0x54]; u8 clear0, clear1, clear2, copy[4];} SelectState;
extern u8 D_800B5C6C; extern s16 D_800C6F12; extern SelectState *gSelectState; extern u8 *gRecords; extern Table *gLeague; extern void func_80057D5C(s32,s32,s32,s32);

/* Loads the selected record into the select state, clears its fields, and marks the
   league entry at the current index as active. */
void func_800679D8(void)
{
    u8 mode;
    u8 *src;
    u8 i;
    Table *league;
    Item *item;

    mode = D_800B5C6C & 3;
    D_800C6F12 = 0;
    D_800B5C6C = mode;
    gSelectState->flag = mode;
    {
        s8 idx = gSelectState->idx;
        u8 *base = gRecords;
        src = base + (idx * 40 + 0x44);
    }
    gSelectState->clear2 = 0;
    gSelectState->clear1 = 0;
    gSelectState->clear0 = 0;
    i = 0;
    do {
        gSelectState->copy[i] = src[i];
        i++;
    } while (i < 4);
    league = gLeague;
    item = (Item *)((u8 *)league->items + league->index * 20);
    item->b = item->a;
    func_80057D5C(10, 11, 2, 6);
}
