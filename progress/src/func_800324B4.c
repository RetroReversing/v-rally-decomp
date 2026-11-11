typedef struct CarInfo { u8 pad0[4]; s16 speedA; s16 speedB; u8 pad8[8]; s16 posX; s16 posY; u8 pad14[4]; u16 limit; u8 laneSide; u8 driveState; } CarInfo;
typedef struct Car { u8 pad0[8]; s32 flags; u8 padC[0x4C]; struct Car *prev; struct Car *next; u8 pad60[0x18]; CarInfo *info; u8 pad7C[0xC]; u16 gridN; u8 pad8A[2]; u16 id; u8 pad8E[4]; u8 key0; u8 key1; } Car;
typedef struct TrackHdr { u8 pad[0x12]; u16 width; } TrackHdr;
typedef struct LimitRule { u8 key0; u8 key1; u16 id; u8 laneSide; u8 driveState; u16 limit; } LimitRule;
typedef struct TrackParam { s32 value; s32 pad[5]; } TrackParam;
extern f32 D_8009CEC8;
extern s32 gSnapIndex;
extern TrackParam gSnapTable[], gSpeedPenalty[], gDraftFactor[];
extern TrackHdr *g_rec_val;
extern LimitRule D_8009F42C[][3];
#define CAR_LOW_FLAGS(c) (*(u16 *)((char *)(c) + 0xA))
/* Sets each car's speed limit (CarInfo.limit) from its speed, its neighbours' speeds and
 * the track penalties, then applies the per-track override rules. Walks the car ring. */
void func_800324B4(Car *firstCar)
{
  Car *car;
  s32 t, d, e, px, py, side, dist, sp, m, lim, fl, i;
#define curKind py
#define nextKind px
#define capped py
  t = D_8009CEC8 * (f32)g_rec_val->width;
  side = 0;
  d = t * 400 / 4096;
  e = t * 900 / 4096;
  car = firstCar;
  do {
    dist = 0;
    if (car->prev != NULL && car->next != NULL) {
      px = car->info->posX;
      py = car->info->posY;
      if (px > d && py < -d) { dist = px - py; side = (car->gridN - 1) / 2; }
      if (px < -d) if (py > d) { dist = py - px; side = (car->gridN - 1) / 2; }
      if (px >= 0 && py < -e) { dist = px - py; side = (car->gridN - 1) / 2; }
      if (px > e && py < 1) { dist = px - py; side = (car->gridN - 1) / 2; }
      if (px < 1 && py > e) { dist = py - px; side = (car->gridN - 1) / 2; }
      if (px < -e && py >= 0) { dist = py - px; side = (car->gridN - 1) / 2; }
      py = px;
      px = car->prev->info->posY;
      if (px > d && py < -d) { dist = px - py; side = 0; }
      if (px < -d) if (py > d) { dist = py - px; side = 0; }
      if (px >= 0 && py < -e) { dist = px - py; side = 0; }
      if (px > e && py < 1) { dist = px - py; side = 0; }
      if (px < 1 && py > e) { dist = py - px; side = 0; }
      if (px < -e && py >= 0) { dist = py - px; side = 0; }
      if (side == 0) {
        if ((CAR_LOW_FLAGS(car) & 0x800) && (CAR_LOW_FLAGS(car->prev) & 0x800) && (CAR_LOW_FLAGS(car->next) & 0x800)) dist = 0;
      } else if (CAR_LOW_FLAGS(car) & 0x800) {
        dist = 0;
      }
    }
    curKind = ((car->flags & 0x402) == 0x402) * 2;
    nextKind = 0;
    if ((car->flags & 0x201) == 0x201) curKind = 1;
    if (car->next != NULL) {
      fl = car->next->flags;
      if ((fl & 0x402) == 2) nextKind = 2;
      if ((fl & 0x201) == 1) nextKind = 1;
    }
    if (nextKind == 1 && curKind == 1) {
      sp = car->info->speedA + ((u32)(car->next->info->speedA * gDraftFactor[gSnapIndex].value) >> 12);
    } else if (nextKind == 2 && curKind == 2) {
      sp = car->info->speedB + ((u32)(car->next->info->speedB * gDraftFactor[gSnapIndex].value) >> 12);
    } else {
      sp = 0;
    }
    m = car->info->speedA;
    curKind = car->info->speedB;
    if (m < curKind) m = curKind;
    capped = 0;
    if (sp > 300) {
      lim = 12000 - ((u32)(sp * gSpeedPenalty[gSnapIndex].value) >> 12);
      capped = 1;
      if (lim < 0) lim = 0;
    } else if (m > 300) {
      lim = 12000 - ((u32)(m * gSpeedPenalty[gSnapIndex].value) >> 12);
      if (lim < 0) lim = 0;
    } else {
      lim = 12000;
    }
    if (dist != 0) {
      lim -= (u32)(dist * gSnapTable[gSnapIndex].value) >> 12;
      car->info->laneSide = side;
      car->info->driveState = 2;
      if (lim < 0) lim = 0;
      car->info->limit = lim;
      car->prev->info->limit = lim;
      car->prev->info->laneSide = *((u8 *)car->prev + 0x89) - 2;
      car->prev->info->driveState = 0;
    }
    if (capped) {
      car->next->info->limit = lim;
      car->next->info->laneSide = 0;
      car->info->laneSide = *((u8 *)car + 0x89) - 2;
    }
    if (car->info->limit == 0) car->info->limit = lim;
    for (i = 0; i < 3; i++) {
      if (D_8009F42C[gSnapIndex][i].id == 0) break;
      if (D_8009F42C[gSnapIndex][i].id == car->id && D_8009F42C[gSnapIndex][i].key0 == car->key0 && D_8009F42C[gSnapIndex][i].key1 == car->key1) {
        car->info->limit = D_8009F42C[gSnapIndex][i].limit;
        car->info->laneSide = D_8009F42C[gSnapIndex][i].laneSide;
        car->info->driveState = D_8009F42C[gSnapIndex][i].driveState;
      }
    }
    car = car->next;
  } while (car != firstCar && car != NULL);
}
