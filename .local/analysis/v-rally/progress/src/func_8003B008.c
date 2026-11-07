extern char D_800AE850[];
extern char D_800C02AE[];

typedef struct Info {
    u8 pad0[8];
    s32 id;
    s32 unkC;
    u8 pad10[0x10];
    s32 unk20;
} Info;

typedef struct Node {
    u8 pad0[4];
    struct Node *next;
    u8 pad8[0x64];
    Info *info;
    s32 *unk70;
} Node;

typedef struct Holder {
    u8 pad0[0x24];
    Node *node;
} Holder;

typedef struct Car {
    u8 pad0[0x76];
    u16 id;
    u8 pad78[2];
    s16 unk7A;
    u8 pad7C[4];
    s32 flags;
    u8 pad84[0xC];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8 pad94[0x14];
    Holder *holder;
} Car;

typedef struct Game {
    u8 pad0[0x1E];
    u16 unk1E;
} Game;

#define GAME (*(Game **)(D_800C02AE + 0x32F2))

void func_8003B008(void *object) {
    Car * car = object;
    Node *n;

    if (GAME->unk1E == 0) {
        n = car->holder->node;
    } else {
        for (n = **(Node ***)(D_800AE850 + 0x73F0); n != NULL; n = n->next) {
            if (car->id == n->info->id && n->info->unk20 == 0) {
                break;
            }
        }
    }
    if (n == NULL) {
        return;
    }
    car->flags |= 4;
    if (n->info->unkC == 0) {
        return;
    }
    car->unk7A = 11;
    if (GAME->unk1E == 0) {
        if (n->info->unkC < 0) {
            car->r = 0xFA;
            car->g = 0x32;
            car->b = 10;
            car->unk7A = 11;
            car->a = 0xFF;
        } else {
            car->unk7A = 10;
            car->r = 10;
            car->g = 200;
            car->b = 10;
            car->a = 0xFF;
        }
    } else if (n->info->unk20 == 0) {
        s32 id;
        n = car->holder->node;
        id = n->info->id;
        if (id == car->id) {
            car->r = 0xFE;
            car->g = 0xD5;
            car->b = 0x1E;
            car->a = 0xFF;
        } else {
            car->r = 0xFF;
            car->g = 0xFF;
            car->b = 0xFF;
            car->a = 0xFF;
        }
    }
    if (GAME->unk1E != 0 || *n->unk70 >= 2) {
        car->flags &= ~4;
    }
}
