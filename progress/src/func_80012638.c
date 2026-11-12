extern int D_800AE004;
s32 getCounterValue(void *);
void *streamSetCurrent(void *);
u64 osGetTime(void);
s32 rand_next15(void);
s32 rand_seed();
extern u8 D_8009BA34;
extern s32 gPadFlags;
extern char gGameState[];
extern char stream_state[];
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

/* Chase-camera AI: picks the next track node for the target from the nodes in the
   groups ahead of the player (nearest first, with a random skip once a target is
   reached) and aims the camera at the target and the player. Does nothing while
   the race flags or the pause byte are set. */
void func_80012638(Ctl *ctl)
{
  Cam *cam;
  Vec diff;
  Vec pos;
  Obj *follow;
  Node *first;
  Node *grp;
  Node *best;
  Node *best_grp;
  Node *it;
  Node *next_grp;
  Node *next_grp2;
  s32 hit;
  s32 gap;
  s32 t;
  s16 k;
  u32 min_d;
  u32 dsq;

  rand_seed((u32) osGetTime());
  cam = *(Cam **)(stream_state + 0x7cd6);
  best_grp = NULL;
  cam->f130 = 0;
  cam->f134 = 100.0f;
  cam->f138 = 0;
  cam->f114 = 1.0f;
  if (!(gPadFlags & 2) && D_8009BA34 == 0 && D_800AE004 != 0) {
    follow = cam->node;
    pos = follow->f58->pos;
    gap = getCounterValue(follow);
    first = *(Node **)&follow->f8C->f28;
    best = NULL;
    grp = first;
    if (first->f58 != NULL) grp = first->f58;
    min_d = 99999999;
    k = 0;
    do {
      hit = 0;
      if (grp->f7C != NULL) {
        it = grp->f7C;
        do {
          if (it == ctl->target) hit = 1;
          diff.x = pos.x - it->pos.x;
          diff.z = pos.z - it->pos.z;
          dsq = (diff.x >> 4) * (diff.x >> 4) + (diff.z >> 4) * (diff.z >> 4);
          if (min_d >= dsq) {
            min_d = dsq;
            best = grp->f7C;
            best_grp = grp;
          }
          if (grp->f7C == grp->f7C->next) break;
          it = it->next;
        } while (it != NULL);
        if (hit) best = ctl->target;
      }
      if (grp->f5C != NULL) grp = grp->f5C;
      k++;
    } while (k < 3);
    if (best != NULL) {
      if (ctl->target != best && ctl->timer >= 0x33) {
        if (best_grp == first)
        {
          dsq = follow->f60->f28;
          if ((u32)(best_grp->f88 - dsq) < 10U)
          {
            next_grp = best_grp->f5C;
            if (next_grp != NULL)
            {
              if (next_grp->f7C != NULL)
              {
                best = next_grp->f7C;
                best_grp = next_grp;
              }
            }
          }
        }
        if (((gap >= 0x83) & (best_grp != NULL)) && ((next_grp2 = best_grp->f5C, next_grp2 != NULL)))
        {
          hit = best_grp != NULL;
          if (best_grp->type != 1)
          {
            if (next_grp2->f7C != NULL)
            {
              best = next_grp2->f7C;
            }
            goto block_33;
          }
        }
        else
        {
          block_33:
          hit = best_grp != NULL;
        }
        if ((best_grp != NULL) & (best != NULL))
        {
          k = rand_next15() % 6;
          while (k > 0)
          {
            if (best->next != NULL)
              best = best->next;
            else
              best = best_grp->f7C;
            k -= 1;
          }
        }
        ctl->target = best;
        ctl->timer = 0;
      } else {
        ctl->timer++;
      }
      cam = *(Cam **)(stream_state + 0x7cd6);
      cam->flags &= 0xFF77;
      cam->f118 = ctl->target->pos.x;
      cam->f11c = ctl->target->pos.y;
      cam->f120 = ctl->target->pos.z;
      cam->f124 = pos.x;
      cam->f128 = pos.y;
      cam->f12c = pos.z;
      cam->f108 = 0;
      if (*(u16 *)(*(char **)(stream_state + 0x32F2) + 0xE) == 1) {
        cam->f114 = 0.5f;
      } else {
        cam->f114 = 1.0f;
      }
    }
  }
  streamSetCurrent(*(void **)(stream_state + 0x7CD6));
}
