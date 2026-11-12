typedef struct {
    s32 time;
    u8 car;
    u8 b;
    char name[4];
    u8 c;
    u8 d;
    u8 e;
    u8 pad[3];
} Rec;
typedef struct {
    char name[0xA];
    u16 w;
    u8 pad[0x28 - 0xC];
} Ent;
typedef struct {
    u8 pad0[0x16];
    u16 x16;
    u8 pad18[0x32 - 0x18];
    u8 sel[0x12];
    Ent e[4];
} Game;
extern Game *gRecords;
extern Rec D_800C3650[4][4];
extern Rec D_800C3A50[4];
extern void sort_split_times(Rec *);
extern void func_8006CB9C(void);
extern void save_race_to_pak(void);
extern s32 strCmp(char *, char *);
extern void strCpy(char *, char *);

/* For each of the four players: total the times and laps of their name across the
 * record groups (only entries flagged e == 1 count). If the player's total is not
 * already in the top table D_800C3A50, it is written into slot 3 and the table is
 * re-sorted by sort_split_times. */
void hiscore_update_race_records(void)
{
    struct {
        s32 time[4];
        s32 laps[4];
    } acc;
    char name[8];
    u8 c;
    u8 g;
    u8 k;
    u8 found;
    s32 ok;
    s32 searching;

    c = 0;
    do
    {
        strCpy(name, gRecords->e[c].name);
        g = 0;
        acc.time[c] = 0;
        acc.laps[c] = 0;
        do
        {
            found = 0;
            searching = 1;
            k = 0;
            do
            {
                if (D_800C3650[g][k].e == 1 && strCmp(name, D_800C3650[g][k].name) == 0)
                {
                    acc.time[c] += D_800C3650[g][k].time;
                    found = 1;
                    acc.laps[c] += D_800C3650[g][k].c;
                    searching = 0;
                    break;
                }
                else
                {
                    k++;
                }
            } while ((searching != 0) & (k < 3));
            g++;
        } while (g < 4 && found);
        if (found)
        {
            ok = 1;
            k = 0;
            do
            {
                if (strCmp(name, D_800C3A50[k].name) == 0)
                {
                    ok &= -(D_800C3A50[k].time != acc.time[c]);
                }
                k++;
            } while (k < 3);
            if ((u8) ok)
            {
                D_800C3A50[3].time = acc.time[c];
                D_800C3A50[3].car = gRecords->e[gRecords->sel[c]].w;
                D_800C3A50[3].b = gRecords->x16;
                strCpy(D_800C3A50[3].name, gRecords->e[gRecords->sel[c]].name);
                D_800C3A50[3].c = (u32) acc.laps[c] / 18;
                D_800C3A50[3].d = 0;
                D_800C3A50[3].e = 1;
                sort_split_times(D_800C3A50);
            }
        }
        c++;
    } while (c < 4);
    func_8006CB9C();
    save_race_to_pak();
}
