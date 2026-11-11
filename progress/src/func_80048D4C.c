typedef struct Node { s32 a; struct Node *next; s32 rest[18]; } Node;
typedef struct { Node **list; s32 pad4[3]; u32 count; u8 digits[16]; Node *t24; Node *t28; s32 x2c; } Grp;
typedef struct { u32 count; u8 digits[1]; } Cnt;
s32 poolAlloc(s32, s32);
u32 str_len(u8 *);
s32 strCmp(const u8 *, const u8 *);
extern u8 D_800A4E4C[];
extern u8 D_800A4E50[];
extern u8 gOrderState[];
extern u8 gStreamState[];

/* Fills the HUD digit tables for each active slot of the current race record.
   Slot 1 uses the first label set, any other name uses the second; each digit of
   the record's number picks a node from the group's list and copies it into the
   two node tables. */
void func_80048D4C(u8 *rec) {
    Cnt *cnt;
    Grp *grp;
    u8 *hud;
    u8 *p;
    u8 slot_count;
    u32 slot;
    u32 di;
    u8 steps;
    Node *pick;

    cnt = NULL;
    grp = NULL;
    slot_count = *(u8 *)(*(u8 **)(gStreamState + 0x32F2) + 0xF);
    hud = **(u8 ***)(gOrderState + 0x6D94);
    for (slot = 1; slot <= slot_count; slot++) {
        if (strCmp(rec + 0x4C, D_800A4E4C) == 0) {
            hud[0x3C] = *(s32 *)(rec + 0x128);
            hud[0x3D] = *(s32 *)(rec + 0x174);
            cnt = (Cnt *)(hud + 0x1C);
            grp = (Grp *)(hud + 0xC);
            hud[0x3E] = *(s32 *)(rec + 0x1C0);
        } else if (strCmp(rec + 0x4C, D_800A4E50) == 0) {
            hud[0x74] = *(s32 *)(rec + 0x128);
            hud[0x75] = *(s32 *)(rec + 0x174);
            cnt = (Cnt *)(hud + 0x54);
            grp = (Grp *)(hud + 0x44);
            hud[0x76] = *(s32 *)(rec + 0x1C0);
        }
        grp->x2c = poolAlloc(1, 8);
        cnt->count = str_len(rec + 0x98);
        grp->t24 = (Node *)poolAlloc(6, cnt->count * 0xF0);
        grp->t28 = (Node *)poolAlloc(6, cnt->count * 0xF0);
        p = rec + 0x98;
        for (di = 0; di < cnt->count; di++) {
            cnt->digits[di] = *p - '0';
            steps = cnt->digits[di];
            pick = *grp->list;
            while (steps) {
                pick = pick->next;
                steps--;
            }
            __builtin_memcpy(&grp->t24[di], pick, sizeof(Node));
            __builtin_memcpy(&grp->t24[di + cnt->count], pick, sizeof(Node));
            __builtin_memcpy(&grp->t24[cnt->count * 2 + di], pick, sizeof(Node));
            __builtin_memcpy(&grp->t28[di], pick, sizeof(Node));
            __builtin_memcpy(&grp->t28[di + cnt->count], pick, sizeof(Node));
            __builtin_memcpy(&grp->t28[cnt->count * 2 + di], pick, sizeof(Node));
            p++;
        }
        hud = *(u8 **)(hud + 4);
    }
}
