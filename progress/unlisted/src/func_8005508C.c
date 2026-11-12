typedef struct {
    s32 points;
    u8 tagA;
    u8 tagB;
    u8 name[4];
    u8 bonus;
    u8 flag;
    u8 used;
    u8 padD[3];
} Entry;
extern Entry D_800C3A90[3][4];
extern u8 *gRecords;
extern u8 *copyStringAligned(u8 *dst, u8 *src);
extern s32 strCmp(const u8 *arg0, const u8 *arg1);
extern void sort_split_times(void *);

/* Rebuilds the season standings. For each of the four drivers (name at
 * gRecords + i*40 + 0x44) it totals the points and bonus from the first two
 * point tables (up to three slots each). If the driver scored in both tables
 * and their total is not already in the third table, it is written into the
 * third table's slot 3 and that table is re-sorted. */
void func_8005508C(void)
{
char *rankAddr;

    s32 points[4];
    s32 bonus[4];
    u8 driverName[6];
    u8 driver, slot, found, cont, first, k;
    s32 ok;

    for (driver = 0; driver < 4; driver++) {
        copyStringAligned(driverName, gRecords + (driver * 40 + 0x44));
        first = 0;
        found = 0;
        cont = 1;
        slot = 0;
        points[driver] = 0;
        bonus[driver] = 0;
        while (cont && slot < 3) {
            if (D_800C3A90[0][slot].used == 1 && strCmp(driverName, D_800C3A90[0][slot].name) == 0) {
                points[driver] += D_800C3A90[0][slot].points;
                bonus[driver] += D_800C3A90[0][slot].bonus;
                found = 1;
                cont = 0;
                break;
            }
            slot++;
        }
        if (found) {
            first = 1;
        }
        found = 0;
        cont = 1;
        slot = 0;
        while (cont && slot < 3) {
            if (D_800C3A90[1][slot].used == 1 && strCmp(driverName, D_800C3A90[1][slot].name) == 0) {
                points[driver] += D_800C3A90[1][slot].points;
                bonus[driver] += D_800C3A90[1][slot].bonus;
                found = 1;
                cont = 0;
                break;
            }
            slot++;
        }
        if (first & found) {
            ok = 1;
            for (k = 0; k < 3; k++) {
                if (strCmp(driverName, D_800C3A90[2][k].name) == 0) {
                    ok &= -(D_800C3A90[2][k].points != points[driver]);
                }
            }
            if ((u8)ok) {
                D_800C3A90[2][3].points = points[driver];
rankAddr = (char *)(gRecords + driver * 40 + 0x4E);

                D_800C3A90[2][3].tagA = *(u16 *)(rankAddr);
                D_800C3A90[2][3].tagB = *(u16 *)(gRecords + 0x16);
                copyStringAligned(D_800C3A90[2][3].name, gRecords + (driver * 40 + 0x44));
                D_800C3A90[2][3].bonus = ((u32)bonus[driver] >> 3) + 4;
                D_800C3A90[2][3].flag = 0;
                D_800C3A90[2][3].used = 1;
                sort_split_times(D_800C3A90[2]);
            }
        }
    }
}
