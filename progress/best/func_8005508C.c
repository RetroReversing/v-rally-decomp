typedef struct {
    s32 val;
    u8 b4;
    u8 b5;
    u8 name[4];
    u8 bonus;
    u8 bB;
    u8 used;
    u8 padD[3];
} Entry;
extern Entry D_800C3A90[3][4];
extern u8 *D_800C35A0;
extern u8 *func_80098290(u8 *dst, u8 *src);
extern s32 func_80098180(const u8 *arg0, const u8 *arg1);
extern void func_800535F4(void *);

void func_8005508C(void)
{
char *__repair_addr;

    s32 val[4];
    s32 bon[4];
    u8 pos[6];
    u8 i, j, found, cont, first, k;
    s32 ok;

    for (i = 0; i < 4; i++) {
        func_80098290(pos, D_800C35A0 + (i * 40 + 0x44));
        first = 0;
        found = 0;
        cont = 1;
        j = 0;
        val[i] = 0;
        bon[i] = 0;
        while (cont && j < 3) {
            if (D_800C3A90[0][j].used == 1 && func_80098180(pos, D_800C3A90[0][j].name) == 0) {
                val[i] += D_800C3A90[0][j].val;
                bon[i] += D_800C3A90[0][j].bonus;
                found = 1;
                break;
            }
            j++;
        }
        if (found) {
            first = 1;
        }
        found = 0;
        cont = 1;
        j = 0;
        while (cont && j < 3) {
            if (D_800C3A90[1][j].used == 1 && func_80098180(pos, D_800C3A90[1][j].name) == 0) {
                val[i] += D_800C3A90[1][j].val;
                bon[i] += D_800C3A90[1][j].bonus;
                found = 1;
                break;
            }
            j++;
        }
        if (first & found) {
            ok = 1;
            for (k = 0; k < 3; k++) {
                if (func_80098180(pos, D_800C3A90[2][k].name) == 0) {
                    ok &= -(D_800C3A90[2][k].val != val[i]);
                }
            }
            if ((u8)ok) {
                D_800C3A90[2][3].val = val[i];
__repair_addr = (char *)(D_800C35A0 + i * 40 + 0x4E);

                D_800C3A90[2][3].b4 = *(u16 *)(__repair_addr);
                D_800C3A90[2][3].b5 = *(u16 *)(D_800C35A0 + 0x16);
                func_80098290(D_800C3A90[2][3].name, D_800C35A0 + (i * 40 + 0x44));
                D_800C3A90[2][3].bonus = ((u32)bon[i] >> 3) + 4;
                D_800C3A90[2][3].bB = 0;
                D_800C3A90[2][3].used = 1;
                func_800535F4(D_800C3A90[2]);
            }
        }
    }
}
