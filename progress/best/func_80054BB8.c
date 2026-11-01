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
extern Game *D_800C35A0;
extern Rec D_800C3650[4][4];
extern Rec D_800C3A50[4];
extern void func_800535F4(Rec *);
extern void func_8006CB9C(void);
extern void func_8006F75C(void);
extern s32 func_80098180(char *, char *);
extern void func_80098290(char *, char *);

void func_80054BB8(void)
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
        func_80098290(name, D_800C35A0->e[c].name);
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
                if (D_800C3650[g][k].e == 1 && func_80098180(name, D_800C3650[g][k].name) == 0)
                {
                    acc.time[c] += D_800C3650[g][k].time;
                    found = 1;
                    acc.laps[c] += D_800C3650[g][k].c;
                    searching = 0;
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
                if (func_80098180(name, D_800C3A50[k].name) == 0)
                {
                    ok &= -(D_800C3A50[k].time != acc.time[c]);
                }
                k++;
            } while (k < 3);
            if ((u8) ok)
            {
                D_800C3A50[3].time = acc.time[c];
                D_800C3A50[3].car = D_800C35A0->e[D_800C35A0->sel[c]].w;
                D_800C3A50[3].b = D_800C35A0->x16;
                func_80098290(D_800C3A50[3].name, D_800C35A0->e[D_800C35A0->sel[c]].name);
                D_800C3A50[3].c = (u32) acc.laps[c] / 18;
                D_800C3A50[3].d = 0;
                D_800C3A50[3].e = 1;
                func_800535F4(D_800C3A50);
            }
        }
        c++;
    } while (c < 4);
    func_8006CB9C();
    func_8006F75C();
}
