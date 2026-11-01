typedef struct { u16 type; u16 anim; u16 val; u16 time; } AnimEntry;
typedef struct Anim { u8 pad0[0xC]; void (*fn)(struct Anim *); u8 pad10[0x10]; s32 x20; u8 pad24[0xC]; s32 x30; u8 pad34[0x54]; u32 x88; } Anim;
typedef struct { u8 pad0[0x6C]; void *link; u8 pad70[0x14]; u16 idx; u16 timer; u32 value; } AnimObj;
typedef struct Trk { u8 pad0[8]; s16 id; u8 padA[0x52]; struct Trk *next; } Trk;
typedef struct { u8 pad0[0x28]; Trk *trk; } Sub8C;
typedef struct { u8 pad0[0x34]; u32 state; } Sub9C;
typedef struct { u8 pad0[0x8C]; Sub8C *p8C; u8 pad90[0xC]; Sub9C *p9C; } Car;
typedef struct { u8 pad0[0x24]; Car *car; u8 pad28[0xEC]; f32 x114; u8 pad118[0x18]; s32 x130; f32 x134; s32 x138; } Cam;
extern Cam *D_800C7F84;
extern AnimEntry D_8009BA40[];
extern s32 D_800ADFE8;
Anim *func_80022668(void *, s32);
void func_80010F3C(Anim *, s32);

void func_800122A4(AnimObj *o)
{
  Cam *cam;
  Car *car;
  Anim *a;
  Trk *t;
  s32 ok;
  s32 g;

  cam = D_800C7F84;
  car = cam->car;
  a = NULL;
  cam->x130 = 0;
  cam->x134 = 100.0f;
  cam->x138 = 0;
  cam->x114 = 1.0f;
  if (car == NULL) return;
  switch (car->p9C->state) {
  case 0:
    if (o->timer != 0) o->timer--;
    a = func_80022668(o->link, D_8009BA40[o->idx].anim);
    if (o->timer == 0) {
      ok = 1;
      if (D_8009BA40[o->idx].type == 2) ok = a->x88 >= 50;
      if (ok) {
        if (++o->idx == 6) o->idx = 0;
        o->timer = D_8009BA40[o->idx].time;
        o->value = 0;
        a = func_80022668(o->link, D_8009BA40[o->idx].anim);
        if (D_8009BA40[o->idx].type == 2) {
          a->x88 = 0x33;
        } else {
          car = D_800C7F84->car;
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
            o->idx = 0;
            o->timer = D_8009BA40[0].time + 200;
            o->value = 0;
            a = func_80022668(o->link, D_8009BA40[o->idx].anim);
          }
        }
      }
    }
    if (D_8009BA40[o->idx].type == 1) a->x20 = 1;
    else func_80010F3C(a, 0);
    a->x30 = D_8009BA40[o->idx].val;
    break;
  case 1:
    a = func_80022668(o->link, D_8009BA40[1].anim);
    a->x30 = D_8009BA40[1].val;
    if (a->x88 < 50) a->x88 = 0x33;
    break;
  case 2:
    a = func_80022668(o->link, D_8009BA40[0].anim);
    a->x30 = D_8009BA40[0].val;
    break;
  case 3:
    a = func_80022668(o->link, D_8009BA40[2].anim);
    a->x30 = D_8009BA40[2].val;
    if (D_8009BA40[o->idx].type == 1) a->x20 = 1;
    break;
  case 4:
    a = func_80022668(o->link, D_8009BA40[3].anim);
    a->x30 = D_8009BA40[3].val;
    break;
  case 5:
    a = func_80022668(o->link, D_8009BA40[4].anim);
    a->x30 = D_8009BA40[4].val;
    if (D_8009BA40[o->idx].type == 1) a->x20 = 1;
    break;
  case 6:
    a = func_80022668(o->link, D_8009BA40[5].anim);
    a->x30 = D_8009BA40[5].val;
    o->timer = 0;
    if (D_8009BA40[o->idx].type == 1) a->x20 = 1;
    break;
  }
  a->fn(a);
}
