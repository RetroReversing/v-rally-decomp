typedef struct RoomEntry {
    u8 pad0[6];
    u8 name[6];
    u8 type;
    u8 padD[64 - 0xD];
} RoomEntry;

typedef struct RoomInfo {
    u8 pad0[0x14];
    u16 count;
    u8 pad16[0x2C - 0x16];
    RoomEntry entries[10];
    u8 pad2AC[0x2C4 - 0x2AC];
} RoomInfo;

typedef struct PlayerName {
    u8 name[0x28];
} PlayerName;
typedef struct GameRecords {
    u8 pad0[0x44];
    PlayerName players[5];
} GameRecords;

typedef struct Score {
    u8 v[5];
} Score;

extern u16 D_800D061E;
extern RoomInfo *gSlotTableB;
extern GameRecords *gRecords;
extern Score D_800B0D84[];
s32 strCmp(u8 *, u8 *);

/* For every room in gSlotTableB and every entry of type 1 in it, finds the player whose
   name matches the entry (search stops at index 4) and adds 2 points to that player's
   score and to the total in slot 4. */
void func_80053F44(void)
{
    u8 i;
    u8 j;
    u8 k;
    RoomInfo *room = gSlotTableB;

    for (i = 0; i < D_800D061E; room++, i++) {
        for (j = 0; j < room->count; j++) {
            if (room->entries[j].type == 1) {
                k = 0;
                while (strCmp(gRecords->players[k].name, room->entries[j].name) != 0 && k < 4) {
                    k++;
                }
                D_800B0D84[k].v[0] += 2;
                D_800B0D84[4].v[0] += 2;
            }
        }
    }
}
