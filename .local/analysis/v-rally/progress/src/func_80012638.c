extern int D_800AE004;
s32 func_8001FEE8(void *);
void *func_80042290(void *);
u64 osGetTime(void);
s32 func_80098090(void);
s32 func_800980C4();
extern u8 D_8009BA34;
extern s32 D_8009D538;
extern char D_800A73E0[];
extern char D_800C02AE[];
typedef struct { s32 x, y, z; } Vec;
typedef struct Node {
  u8 p0[8];
  s16 type;
  u8 pA[2];
  Vec pos;
  u8 p18[0xC];
  struct Node *next;
  struct Node *sub;
  s32 f2C_pad[0xB];
  struct Node *f58;
  struct Node *f5C;
  struct Node *f60;
  u8 p64[0x18];
  struct Node *f7C;
  u8 p80[8];
  u16 f88;
} Node;
typedef struct {
  u8 p0[0x88];
  u32 timer;
  Node *target;
} Ctl;
typedef struct Obj {
  u8 p0[0x28];
  s32 f28;
  u8 p2c[0x2c];
  Node *f58;
  u8 p5c[4];
  struct Obj *f60;
  u8 p64[0x28];
  struct Obj *f8C;
} Obj;
typedef struct {
  u8 p0[0x20];
  u16 flags;
  u8 p22[2];
  Obj *node;
  u8 p28[0xe0];
  s32 f108;
  u8 p10c[8];
  f32 f114, f118, f11c, f120, f124, f128, f12c;
  s32 f130;
  f32 f134;
  s32 f138;
} Cam;

void func_80012638(Ctl *ctl)
{
  Cam *cam;
  Vec delta;
  Vec pos;
  Obj *obj;
  Node *first;
  Node *n;
  Node *best;
  Node *bestGrp;
  Node *it;
  Node *nx;
  Node *nx2;
  s32 found;
  s32 r;
  s32 t;
  s16 i;
  u32 min;
  u32 d;

  func_800980C4((u32) osGetTime());
  cam = *(Cam **)(D_800C02AE + 0x7cd6);
  bestGrp = NULL;
  cam->f130 = 0;
  cam->f134 = 100.0f;
  cam->f138 = 0;
  cam->f114 = 1.0f;
  if (!(D_8009D538 & 2) && D_8009BA34 == 0 && D_800AE004 != 0) {
    obj = cam->node;
    pos = obj->f58->pos;
    r = func_8001FEE8(obj);
    first = (Node *)obj->f8C->f28;
    best = NULL;
    n = first;
    if (first->f58 != NULL) n = first->f58;
    min = 99999999;
    i = 0;
    do {
      found = 0;
      if (n->f7C != NULL) {
        it = n->f7C;
        do {
          if (it == ctl->target) found = 1;
          delta.x = pos.x - it->pos.x;
          delta.z = pos.z - it->pos.z;
          d = (delta.x >> 4) * (delta.x >> 4) + (delta.z >> 4) * (delta.z >> 4);
          if (min >= d) {
            min = d;
            best = n->f7C;
            bestGrp = n;
          }
          if (n->f7C == n->f7C->next) break;
          it = it->next;
        } while (it != NULL);
        if (found) best = ctl->target;
      }
      if (n->f5C != NULL) n = n->f5C;
      i++;
    } while (i < 3);
    if (best != NULL) {
      if (ctl->target != best && ctl->timer >= 0x33) {
        if (bestGrp == first)
        {
          d = obj->f60->f28;
          if ((u32)(bestGrp->f88 - d) < 10U)
          {
            nx = bestGrp->f5C;
            if (nx != NULL)
            {
              if (nx->f7C != NULL)
              {
                best = nx->f7C;
                bestGrp = nx;
              }
            }
          }
        }
        if (((r >= 0x83) & (bestGrp != NULL)) && ((nx2 = bestGrp->f5C, nx2 != NULL)))
        {
          found = bestGrp != NULL;
          if (bestGrp->type != 1)
          {
            if (nx2->f7C != NULL)
            {
              best = nx2->f7C;
            }
            goto block_33;
          }
        }
        else
        {
          block_33:
          found = bestGrp != NULL;
        }
        if ((bestGrp != NULL) & (best != NULL))
        {
          i = func_80098090() % 6;
          while (i > 0)
          {
            if (best->next != NULL)
              best = best->next;
            else
              best = bestGrp->f7C;
            i -= 1;
          }
        }
        ctl->target = best;
        ctl->timer = 0;
      } else {
        ctl->timer++;
      }
      cam = *(Cam **)(D_800C02AE + 0x7cd6);
      cam->flags &= 0xFF77;
      cam->f118 = ctl->target->pos.x;
      cam->f11c = ctl->target->pos.y;
      cam->f120 = ctl->target->pos.z;
      cam->f124 = pos.x;
      cam->f128 = pos.y;
      cam->f12c = pos.z;
      cam->f108 = 0;
      if (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0xE) == 1) {
        cam->f114 = 0.5f;
      } else {
        cam->f114 = 1.0f;
      }
    }
  }
  func_80042290(*(void **)(D_800C02AE + 0x7CD6));
}
