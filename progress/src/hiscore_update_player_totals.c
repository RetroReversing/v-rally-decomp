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
extern char gStreamState[];
#define G (*(u8 **)(gStreamState + 0x32F2))
typedef struct { Rec *p; } RP;
#define RECS (((RP *)(gStreamState + 0x10386))->p)
typedef struct { u16 n; } NR;
#define NRECS (((NR *)(gStreamState + 0x10370))->n)
#define ITEMS ((Item *)(gStreamState + 0x38A2))
s32 sort_split_times(Item *);
s32 strCmp(char *, char *);
s32 copyStringAligned(char *, void *);

/* For each of the four players in the current session, totals the score and laps
 * of the records whose name matches the player's name (up to three entries per
 * record). If the player is the top scorer it is written into the high-score
 * slot at ITEMS[3] and the table is re-sorted. */
void hiscore_update_player_totals(void)
{
char *__repair_addr;

  u32 totals[8];
  char name[8];
  u8 player;
  u32 *tp;
  u32 *pp;
  Rec *rec;
  u16 *cp;
  u8 r;
  u8 s;
  u8 it;
  u8 found;
  s32 srch;
  u8 cond;
  u8 match;

  player = 0;
  tp = totals;
  for (; player < 4; player++) {
    copyStringAligned(name, (u8 *)G + (player * 40 + 0x44));
    rec = RECS;
    tp[player] = 0;
    tp[player + 4] = 0;
    found = 1;
    r = 0;
    if (NRECS != 0) {
      pp = &tp[player];
      cp = &rec->cnt;
      do {
        cond = *cp != 0;
        s = 0;
        if (found & cond) {
          do {
            found = 0;
            srch = 1;
            it = 0;
            do {
              if (rec->sub[s].item[it].flag == 1 && strCmp(name, rec->sub[s].item[it].name) == 0) {
                pp[0] += rec->sub[s].item[it].score;
                found = 1;
                pp[4] += rec->sub[s].item[it].laps;
                srch = 0;
                break;
              }
              it++;
              cond = it < 3;
            } while (srch & cond);
            s++;
            cond = s < *cp;
          } while (found & cond);
        }
        cp = (u16 *)((u8 *)cp + sizeof(Rec));
        rec++;
        r++;
        cond = r < NRECS;
      } while (found & cond);
    }
    if (found) {
      match = 1;
      for (it = 0; it < 3; it++) {
        if (strCmp(name, ITEMS[it].name) == 0) {
          cond = -(*(u32 *)((u8 *)ITEMS + (it << 4)) != tp[player]);
          match &= cond;
        }
      }
      if (match) {
        ITEMS[3].score = tp[player];
__repair_addr = (char *)(G + (G + player)[0x32] * 40 + 0x4E);

        ITEMS[3].b4 = *(u16 *)(__repair_addr);
        ITEMS[3].b5 = *(u16 *)(G + 0x16);
        copyStringAligned(ITEMS[3].name, (u8 *)G + (G[player + 0x32] * 40 + 0x44));
        ITEMS[3].laps = tp[player + 4] / 50;
        ITEMS[3].bB = 0;
        ITEMS[3].flag = 1;
        sort_split_times(ITEMS);
      }
    }
  }
}
