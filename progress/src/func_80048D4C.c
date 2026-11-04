typedef struct Node { s32 a; struct Node *next; s32 rest[18]; } Node;
typedef struct { Node **list; s32 pad4[3]; u32 count; u8 digits[16]; Node *t24; Node *t28; s32 x2c; } Grp;
typedef struct { u32 count; u8 digits[1]; } Cnt;
s32 func_8007EAA0(s32, s32);
u32 func_8008E118(u8 *);
s32 func_80098180(const u8 *, const u8 *);
extern u8 D_800A4E4C[];
extern u8 D_800A4E50[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];

void func_80048D4C(u8 *arg0) {
    Cnt *cnt;
    Grp *grp;
    u8 *s2;
    u8 *p;
    u8 n;
    u32 j;
    u32 i;
    u8 k;
    Node *node;

    cnt = NULL;
    grp = NULL;
    n = *(u8 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0xF);
    s2 = **(u8 ***)(D_800AE850 + 0x6D94);
    for (j = 1; j <= n; j++) {
        if (func_80098180(arg0 + 0x4C, D_800A4E4C) == 0) {
            s2[0x3C] = *(s32 *)(arg0 + 0x128);
            s2[0x3D] = *(s32 *)(arg0 + 0x174);
            cnt = (Cnt *)(s2 + 0x1C);
            grp = (Grp *)(s2 + 0xC);
            s2[0x3E] = *(s32 *)(arg0 + 0x1C0);
        } else if (func_80098180(arg0 + 0x4C, D_800A4E50) == 0) {
            s2[0x74] = *(s32 *)(arg0 + 0x128);
            s2[0x75] = *(s32 *)(arg0 + 0x174);
            cnt = (Cnt *)(s2 + 0x54);
            grp = (Grp *)(s2 + 0x44);
            s2[0x76] = *(s32 *)(arg0 + 0x1C0);
        }
        grp->x2c = func_8007EAA0(1, 8);
        cnt->count = func_8008E118(arg0 + 0x98);
        grp->t24 = (Node *)func_8007EAA0(6, cnt->count * 0xF0);
        grp->t28 = (Node *)func_8007EAA0(6, cnt->count * 0xF0);
        p = arg0 + 0x98;
        for (i = 0; i < cnt->count; i++) {
            cnt->digits[i] = *p - '0';
            k = cnt->digits[i];
            node = *grp->list;
            while (k) {
                node = node->next;
                k--;
            }
            __builtin_memcpy(&grp->t24[i], node, sizeof(Node));
            __builtin_memcpy(&grp->t24[i + cnt->count], node, sizeof(Node));
            __builtin_memcpy(&grp->t24[cnt->count * 2 + i], node, sizeof(Node));
            __builtin_memcpy(&grp->t28[i], node, sizeof(Node));
            __builtin_memcpy(&grp->t28[i + cnt->count], node, sizeof(Node));
            __builtin_memcpy(&grp->t28[cnt->count * 2 + i], node, sizeof(Node));
            p++;
        }
        s2 = *(u8 **)(s2 + 4);
    }
}
