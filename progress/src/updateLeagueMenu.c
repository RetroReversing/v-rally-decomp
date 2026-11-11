typedef struct {
    u8 pad00[0x2A];
    u16 flags2A;
    u16 flags2C;
    u8 pad2E[0x2F - 0x2E];
    u8 slotMask;
    u8 pad30[0x38 - 0x30];
    u16 count38;
} Records;

typedef struct {
    u8 pad00[0x41];
    s8 flag41;
} MenuObj;

void *select_get_entry(u32);
s32 slot_set_selected();
void *list_advance(u32, void *);
s32 func_8008A0D8();
extern void *gSelectState;
extern u8 D_800A154C[];
extern s32 D_800A18D0;
extern char gStreamState[];
extern VRMenuManager *gLeague;
extern Records *gRecords;

/* Refreshes the league menu: clears the stale item flags, then sets the
 * radio groups and toggles from the records' option bits. */
void updateLeagueMenu(void)
{
    s32 i;
    long idx;
    u8 level;
    s32 temp_a0;
    u16 opts;
    s32 mask;

    func_8008A0D8(gLeague, 0x20U, 0);
    func_8008A0D8(gLeague, 0x21U, 0);
    i = 0;
    do
    {
        idx = i & 0xFF;
        func_8008A0D8(gLeague, *(D_800A154C + idx), 0);
        i += 1;
        ((MenuObj *)list_advance((*(D_800A154C + idx)) - 0x17, *(void **)((char *)gSelectState + 0xC)))->flag41 = 0;
    }
    while (((u32)(i & 0xFF)) < 3U);
    func_8008A0D8(gLeague, 0x17U, 0);
    ((MenuObj *)select_get_entry(0))->flag41 = 0;
    func_8008A0D8(gLeague, 0x18U, 0);
    ((MenuObj *)select_get_entry(1))->flag41 = 0;

    opts = gRecords->flags2A;
    temp_a0 = 0;
    if (opts & 0x1000)
    {
        temp_a0 = 1;
    }
    level = temp_a0;
    if (opts & 0x2000)
    {
        level = temp_a0 + 1;
    }
    if (opts & 0x4000)
    {
        level += 1;
    }
    slot_set_selected(0x1B, level & 0xFF);
    slot_set_selected(0x1D, gRecords->count38 != 0);
    slot_set_selected(0x1A, (gRecords->flags2C >> 8) & 1);
    if (!(D_800A18D0 & 0x10))
    {
        gRecords->flags2C |= 0x100;
        func_8008A0D8(gLeague, 0x1A, 0);
        ((MenuObj *)select_get_entry(3))->flag41 = 0;
    }
    slot_set_selected(0x1E, (gRecords->flags2C >> 0xE) & 1);
    if (!(D_800A18D0 & 0x10))
    {
        func_8008A0D8(gLeague, 0x1EU, 0);
        ((MenuObj *)select_get_entry(7))->flag41 = 0;
    }
    slot_set_selected(0x17, (gRecords->flags2C >> 9) & 1);
    if (!(D_800A18D0 & 0x10))
    {
        func_8008A0D8(gLeague, 0x17U, 0);
        ((MenuObj *)select_get_entry(0))->flag41 = 0;
    }
    slot_set_selected(0x22, (gRecords->flags2C >> 0xC) & 1);
    mask = gRecords->slotMask;
    for (i = 0; (u32)(i & 255) < 6; i++)
    {
        if (!((mask >> i) & 1))
        {
            break;
        }
    }

    slot_set_selected(0x1C, i & 0xFF);
    gLeague->items[gLeague->count].value = 0x19;
}
