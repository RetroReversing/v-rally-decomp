typedef struct {
  u32 score;
  u8 b4;
  u8 b5;
  char name[4];
  u8 laps;
  u8 bB;
  u8 flag;
  u8 pad[3];
} Item;
typedef struct {
  Item item[4];
} Sub;
typedef struct {
  u8 pad0[0x14];
  u16 cnt;
  u8 pad16[0x2C - 0x16];
  Sub sub[(0x2C4 - 0x2C) / 0x40];
  u8 pad[0x2C4 - 0x2C - ((0x2C4 - 0x2C) / 0x40) * 0x40];
} Rec;
extern char D_800C02AE[];
#define G (*(u8 **)(D_800C02AE + 0x32F2))
typedef struct { Rec *p; } RP;
#define RECS (((RP *)(D_800C02AE + 0x10386))->p)
typedef struct { u16 n; } NR;
#define NRECS (((NR *)(D_800C02AE + 0x10370))->n)
#define ITEMS ((Item *)(D_800C02AE + 0x38A2))
s32 func_800535F4(Item *);
s32 func_80098180(char *, char *);
s32 func_80098290(char *, void *);
void func_800548A0(void)
{
  u32 tot[8];
  char name[8];
  u8 i;
  u32 *t;
  u32 *pt;
  Rec *rec;
  u16 *cp;
  u8 j;
  u8 k;
  u8 m;
  u8 ok;
  s32 srch;
  u8 c;
  u8 good;

  i = 0;
  t = tot;
  for (; i < 4; i++) {
    func_80098290(name, (u8 *)G + (i * 40 + 0x44));
    rec = RECS;
    t[i] = 0;
    t[i + 4] = 0;
    ok = 1;
    j = 0;
    if (NRECS != 0) {
      pt = &t[i];
      cp = &rec->cnt;
      do {
        c = *cp != 0;
        k = 0;
        if (ok & c) {
          do {
            ok = 0;
            srch = 1;
            m = 0;
            do {
              if (rec->sub[k].item[m].flag == 1 && func_80098180(name, rec->sub[k].item[m].name) == 0) {
                pt[0] += rec->sub[k].item[m].score;
                ok = 1;
                pt[4] += rec->sub[k].item[m].laps;
                srch = 0;
                break;
              }
              m++;
              c = m < 3;
            } while (srch & c);
            k++;
            c = k < *cp;
          } while (ok & c);
        }
        cp = (u16 *)((u8 *)cp + sizeof(Rec));
        rec++;
        j++;
        c = j < NRECS;
      } while (ok & c);
    }
    if (ok) {
      good = 1;
      for (m = 0; m < 3; m++) {
        if (func_80098180(name, ITEMS[m].name) == 0) {
          c = -(*(u32 *)((u8 *)ITEMS + (m << 4)) != t[i]);
          good &= c;
        }
      }
      if (good) {
        ITEMS[3].score = t[i];
        ITEMS[3].b4 = *(u16 *)(G + (G + i)[0x32] * 40 + 0x4E);
        ITEMS[3].b5 = *(u16 *)(G + 0x16);
        func_80098290(ITEMS[3].name, (u8 *)G + (G[i + 0x32] * 40 + 0x44));
        ITEMS[3].laps = t[i + 4] / 50;
        ITEMS[3].bB = 0;
        ITEMS[3].flag = 1;
        func_800535F4(ITEMS);
      }
    }
  }
}
