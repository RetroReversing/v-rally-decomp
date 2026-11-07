typedef struct Info {
    u8 pad00[8];
    s32 id;
    s32 score;
    u8 pad10[0x10];
    s32 done;
} Info;
typedef struct Node {
    u8 pad00[4];
    struct Node *next;
    u8 pad08[0x64];
    Info *info;
    s32 *p70;
} Node;
typedef struct Owner {
    u8 pad00[0x24];
    Node *node;
} Owner;
typedef struct Hud {
    u8 pad00[0x76];
    u16 id;
    u16 digit;
    s16 val;
    u8 pad7C[4];
    s32 flags;
    u8 pad84[0xC];
    u8 r, g, b, a;
    u8 blink;
    u8 pad95[0x13];
    Owner *owner;
} Hud;
typedef struct Game {
    u8 pad00[0x1E];
    u16 state;
} Game;
extern Game *D_800C35A0;
extern Node **D_800B5C40;
extern s32 D_8009D538;
extern u8 D_8009FE24[];
extern void func_8003AC30(s32, u8 *);

void func_8003B310(void *object) {
    Hud * h = object;
    Node *n;
    s32 v;
    u8 c;
    u32 d;
    s32 id;

    if (D_800C35A0->state == 0) {
        n = h->owner->node;
        if (*n->p70 == 1) {
            n = NULL;
            h->flags |= 4;
        }
    } else {
        for (n = *D_800B5C40; n != NULL; n = n->next) {
            if (h->id == n->info->id) {
                break;
            }
        }
    }
    if (n != NULL) {
        v = n->info->score;
        if (D_800C35A0->state == 0 && (v & 0xFF000000)) {
            v = -v;
        }
        if (h->digit == 0) {
            func_8003AC30(v, D_8009FE24);
            c = D_8009FE24[h->digit];
            h->flags &= ~4;
            h->blink = 0;
            h->val = c - '0';
        } else {
            h->flags &= ~4;
            if (D_800C35A0->state == 0) {
                if ((u32)(v - 30001) < 29999) {
                    h->blink = 1;
                } else {
                    h->blink = 0;
                }
                d = h->digit;
            } else {
                d = h->digit;
                h->blink = 0;
            }
            h->val = D_8009FE24[d] - '0';
        }
        if (n != NULL) {
            if (n->info->score != 0 && D_800C35A0->state == 0) {
                if (n->info->score > 0) {
                    h->r = 10;
                    h->g = 200;
                    h->b = 10;
                    h->a = 255;
                    if (!(D_8009D538 & 2)) {
                        h->blink--;
                    }
                    return;
                }
                h->r = 250;
                h->g = 50;
                h->b = 10;
                h->a = 255;
            } else if (n->info->done == 0) {
                n = h->owner->node;
                id = n->info->id;
                if (id == h->id) {
                    h->r = 254;
                    h->g = 213;
                    h->b = 30;
                    h->a = 255;
                } else {
                    h->r = 255;
                    h->g = 255;
                    h->b = 255;
                    h->a = 255;
                }
            }
        }
    }
}
