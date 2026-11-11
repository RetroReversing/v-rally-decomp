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
extern Game *gRecords;
extern Node **gCarList;
extern s32 gPadFlags;
extern u8 gTimeText[];
extern void formatRecordTime(s32, u8 *);

/* Writes the HUD digit for one position cell: finds the car it shows (or the owner's car in
   the single-player/attract state), formats its score or time into gTimeText, and sets the
   cell colour and blink from the result. */
void hud_update_digit(void *object) {
    Hud *hud = object;
    Node *car;
    s32 score;
    u8 ch;
    u32 idx;
    s32 carId;

    if (gRecords->state == 0) {
        car = hud->owner->node;
        if (*car->p70 == 1) {
            car = NULL;
            hud->flags |= 4;
        }
    } else {
        for (car = *gCarList; car != NULL; car = car->next) {
            if (hud->id == car->info->id) {
                break;
            }
        }
    }
    if (car != NULL) {
        score = car->info->score;
        if (gRecords->state == 0 && (score & 0xFF000000)) {
            score = -score;
        }
        if (hud->digit == 0) {
            formatRecordTime(score, gTimeText);
            ch = gTimeText[hud->digit];
            hud->flags &= ~4;
            hud->blink = 0;
            hud->val = ch - '0';
        } else {
            hud->flags &= ~4;
            if (gRecords->state == 0) {
                if ((u32)(score - 30001) < 29999) {
                    hud->blink = 1;
                } else {
                    hud->blink = 0;
                }
                idx = hud->digit;
            } else {
                idx = hud->digit;
                hud->blink = 0;
            }
            hud->val = gTimeText[idx] - '0';
        }
        if (car != NULL) {
            if (car->info->score != 0 && gRecords->state == 0) {
                if (car->info->score > 0) {
                    hud->r = 10;
                    hud->g = 200;
                    hud->b = 10;
                    hud->a = 255;
                    if (!(gPadFlags & 2)) {
                        hud->blink--;
                    }
                    return;
                }
                hud->r = 250;
                hud->g = 50;
                hud->b = 10;
                hud->a = 255;
            } else if (car->info->done == 0) {
                car = hud->owner->node;
                carId = car->info->id;
                if (carId == hud->id) {
                    hud->r = 254;
                    hud->g = 213;
                    hud->b = 30;
                    hud->a = 255;
                } else {
                    hud->r = 255;
                    hud->g = 255;
                    hud->b = 255;
                    hud->a = 255;
                }
            }
        }
    }
}
