typedef struct { s16 x, y, z, pad; } SVec;
typedef struct { s32 x, y, z, pad; } LVec;
s32 func_8001FEDC();
s32 func_8002D2A0();
s32 func_8002E778();
extern char gOrderState[];

typedef struct Car {
    char pad0[4];
    struct Car *next;
    char pad8[0x50];
    char *pos;      /* 0x58 */
    char pad5C[4];
    char *info;     /* 0x60 */
    char pad64[0x1C];
    char *body;     /* 0x80 */
    char pad84[8];
    s32 *team;     /* 0x8C */
} Car;

typedef struct {
    s32 count;
    s32 team[4];
    s32 score[4];
    s32 ref28[4];
    s32 ref30[4];
    s32 progress[4];
    s32 gap[4];
    s32 rank[4];
    Car *car[4];
    s32 nLeft;
    s32 leftIdx[4];
    s32 nRight;
    s32 rightIdx[4];
    s32 rightDir[4];
} Out;

#define FIELD_S32(p, off) (*(s32 *)((char *)(p) + (off)))

/* Fills `out` with the cars near `me` (the car list at gOrderState+0x73F0, skipping `me`) that
 * are on our team or ahead of us on score. For each one it records team, score, rank and gap, then
 * sorts it into the left or right side list based on the cross products of the two cars' body
 * corners. */
void func_80034134(Out *out, Car *me)
{
    SVec mineFront, mineSide, theirFront, theirSide;
    LVec v;
    Car *car;
    s32 myRank;
    s32 myScore;
    s32 myTeam;
    s32 i;
    s32 cross1, cross2, dot;

    car = **(Car ***)(gOrderState + 0x73F0);
    myRank = FIELD_S32(me->info, 0x17C);
    myScore = FIELD_S32(me->info, 0x14);
    i = 0;
    myTeam = *me->team;
    out->nLeft = 0;
    out->nRight = 0;
    out->count = 0;
    while (car != NULL) {
        if (car != me) {
            out->team[i] = *car->team;
            out->score[i] = FIELD_S32(car->info, 0x14);
            out->ref28[i] = FIELD_S32(car->info, 0x28);
            out->ref30[i] = FIELD_S32(car->info, 0x30);
            if (out->team[i] == myTeam || out->team[i] == FIELD_S32(myTeam, 0x5C)) {
            mineFront.x = FIELD_S32(me->body, 0x2B8) - FIELD_S32(me->body, 0x2CC);
            mineFront.z = FIELD_S32(me->body, 0x2C0) - FIELD_S32(me->body, 0x2D4);
            mineSide.x = FIELD_S32(me->body, 0x240) - FIELD_S32(me->body, 0x254);
            mineSide.z = FIELD_S32(me->body, 0x248) - FIELD_S32(me->body, 0x25C);
            theirFront.x = FIELD_S32(car->body, 0x254) - FIELD_S32(me->body, 0x2CC);
            theirFront.z = FIELD_S32(car->body, 0x25C) - FIELD_S32(me->body, 0x2D4);
            theirSide.x = FIELD_S32(car->body, 0x2CC) - FIELD_S32(me->body, 0x254);
            theirSide.z = FIELD_S32(car->body, 0x2D4) - FIELD_S32(me->body, 0x25C);
            cross1 = mineFront.x * theirFront.z - mineFront.z * theirFront.x;
            cross2 = mineSide.x * theirSide.z - mineSide.z * theirSide.x;
            dot = mineFront.x * theirFront.x + mineFront.z * theirFront.z;
            if (out->ref28[i] >= myScore || out->team[i] == FIELD_S32(myTeam, 0x5C)) {
            out->progress[i] = func_8001FEDC(car);
            out->rank[i] = FIELD_S32(car->info, 0x17C);
            out->car[i] = car;
            v.x = FIELD_S32(me->pos, 0xC) - FIELD_S32(car->pos, 0xC);
            v.z = FIELD_S32(me->pos, 0x14) - FIELD_S32(car->pos, 0x14);
            func_8002E778(&v, &v);
            out->gap[i] = func_8002D2A0(v.x + v.z);
            if (((cross1 < 0) & (cross2 < 0)) && out->rank[i] < myRank + 20 && myRank - 20 < out->rank[i]) {
                out->leftIdx[out->nLeft] = i;
                out->nLeft++;
            }
            if (((0 < cross1) & (cross2 < 0)) && out->rank[i] < myRank + 25 && myRank - 25 < out->rank[i]) {
                out->rightIdx[out->nRight] = i;
                if (dot < 0) {
                    out->rightDir[out->nRight] = 0;
                } else {
                    out->rightDir[out->nRight] = 1;
                }
                out->nRight++;
            }
            i++;
            out->count++;
            }
            }
        }
        car = car->next;
    }
}
