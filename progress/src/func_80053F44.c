typedef struct Entry53 {
    u8 pad0[6];
    u8 name[6];
    u8 type;
    u8 padD[64 - 0xD];
} Entry53;

typedef struct Room53 {
    u8 pad0[0x14];
    u16 count;
    u8 pad16[0x2C - 0x16];
    Entry53 entries[10];
    u8 pad2AC[0x2C4 - 0x2AC];
} Room53;

typedef struct Player53 {
    u8 name[0x28];
} Player53;
typedef struct Game53 {
    u8 pad0[0x44];
    Player53 players[5];
} Game53;

typedef struct Score53 {
    u8 v[5];
} Score53;

extern u16 D_800D061E;
extern Room53 *D_800D0634;
extern Game53 *D_800C35A0;
extern Score53 D_800B0D84[];
s32 func_80098180(u8 *, u8 *);

void func_80053F44(void)
{
    u8 i;
    u8 j;
    u8 k;
    Room53 *room = D_800D0634;

    for (i = 0; i < D_800D061E; room++, i++) {
        for (j = 0; j < room->count; j++) {
            if (room->entries[j].type == 1) {
                k = 0;
                while (func_80098180(D_800C35A0->players[k].name, room->entries[j].name) != 0 && k < 4) {
                    k++;
                }
                D_800B0D84[k].v[0] += 2;
                D_800B0D84[4].v[0] += 2;
            }
        }
    }
}
