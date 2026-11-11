typedef struct { u16 type; u16 anim; u16 val; u16 time; } AnimEntry;
typedef struct Anim { u8 pad0[0xC]; void (*fn)(struct Anim *); u8 pad10[0x10]; s32 x20; u8 pad24[0xC]; s32 x30; u8 pad34[0x54]; u32 x88; } Anim;
typedef struct { u8 pad0[0x6C]; void *link; u8 pad70[0x14]; u16 idx; u16 timer; u32 value; } AnimObj;
typedef struct Trk { u8 pad0[8]; s16 id; u8 padA[0x52]; struct Trk *next; } Trk;
typedef struct { u8 pad0[0x28]; Trk *trk; } Sub8C;
typedef struct { u8 pad0[0x34]; u32 state; } Sub9C;
typedef struct { u8 pad0[0x8C]; Sub8C *p8C; u8 pad90[0xC]; Sub9C *p9C; } Car;
typedef struct { u8 pad0[0x24]; Car *car; u8 pad28[0xEC]; f32 x114; u8 pad118[0x18]; s32 x130; f32 x134; s32 x138; } Cam;
extern Cam *g_camera;
extern AnimEntry gAnimSeq[];
extern s32 D_800ADFE8;
Anim *func_80022668(void *, s32);
void setStreamPaused(Anim *, s32);

/* Per-frame update of the car's animation sequence object. Picks the animation
 * for the car's race state, advances the sequence index on a timer or on the
 * track check, then runs the chosen animation's update callback. */
void anim_seq_update(AnimObj *seq)
{
  Cam *cam;
  Car *car;
  Anim *a;
  Trk *t;
  s32 ok;
  s32 g;

  cam = g_camera;
  car = cam->car;
  a = NULL;
  cam->x130 = 0;
  cam->x134 = 100.0f;
  cam->x138 = 0;
  cam->x114 = 1.0f;
  if (car == NULL) return;
  switch (car->p9C->state) {
  case 0:
    if (seq->timer != 0) seq->timer--;
    a = func_80022668(seq->link, gAnimSeq[seq->idx].anim);
    if (seq->timer == 0) {
      ok = 1;
      if (gAnimSeq[seq->idx].type == 2) ok = a->x88 >= 50;
      if (ok) {
        if (++seq->idx == 6) seq->idx = 0;
        seq->timer = gAnimSeq[seq->idx].time;
        seq->value = 0;
        a = func_80022668(seq->link, gAnimSeq[seq->idx].anim);
        if (gAnimSeq[seq->idx].type == 2) {
          a->x88 = 0x33;
        } else {
          car = g_camera->car;
          t = car->p8C->trk;
          g = D_800ADFE8;
          ok = 0;
          if (t->id == g) {
            ok = 1;
          } else if (t->next != NULL) {
            if (t->next->id == g) ok = 1;
            else if (t->next->next != NULL && t->next->next->id == g) ok = 1;
          }
          if (ok) {
            seq->idx = 0;
            seq->timer = gAnimSeq[0].time + 200;
            seq->value = 0;
            a = func_80022668(seq->link, gAnimSeq[seq->idx].anim);
          }
        }
      }
    }
    if (gAnimSeq[seq->idx].type == 1) a->x20 = 1;
    else setStreamPaused(a, 0);
    a->x30 = gAnimSeq[seq->idx].val;
    break;
  case 1:
    a = func_80022668(seq->link, gAnimSeq[1].anim);
    a->x30 = gAnimSeq[1].val;
    if (a->x88 < 50) a->x88 = 0x33;
    break;
  case 2:
    a = func_80022668(seq->link, gAnimSeq[0].anim);
    a->x30 = gAnimSeq[0].val;
    break;
  case 3:
    a = func_80022668(seq->link, gAnimSeq[2].anim);
    a->x30 = gAnimSeq[2].val;
    if (gAnimSeq[seq->idx].type == 1) a->x20 = 1;
    break;
  case 4:
    a = func_80022668(seq->link, gAnimSeq[3].anim);
    a->x30 = gAnimSeq[3].val;
    break;
  case 5:
    a = func_80022668(seq->link, gAnimSeq[4].anim);
    a->x30 = gAnimSeq[4].val;
    if (gAnimSeq[seq->idx].type == 1) a->x20 = 1;
    break;
  case 6:
    a = func_80022668(seq->link, gAnimSeq[5].anim);
    a->x30 = gAnimSeq[5].val;
    seq->timer = 0;
    if (gAnimSeq[seq->idx].type == 1) a->x20 = 1;
    break;
  }
  a->fn(a);
}
