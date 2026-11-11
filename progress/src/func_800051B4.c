typedef struct { u16 x, y, w, h; } Rect8;

/* Object created by func_800051B4: two rects (r0 current, r1 saved), handles
 * h20/h24, a 4-word array at p1C and float tuning values. */
typedef struct {
  Rect8 r0;
  Rect8 r1;
  u8 b10, b11, b12, b13;
  s32 pad14;
  s32 v18;
  s32 *p1C;
  s32 h20;
  s32 h24;
  u16 flags28;
  u16 pad2A[4];
  s16 v32;
  f32 f34;
  f32 f38;
  f32 f3C;
  f32 f40;
  f32 f44;
} Obj51B4;

s32 func_800056F4(void *, s32);
s32 func_80005744(void *);
s32 func_80005CB8(s32, s32, s32, s32, s32);
s32 streamFreeObject(s32);
void *poolAlloc(s32, s32);
s32 *func_8007ED48(s32, s32, s32);
s32 heapFreeBlock(void *);
extern f32 D_8009BB94;
extern f32 D_8009BB98;
extern f32 D_8009BB9C;
extern f32 D_8009BBA0;

/* Allocates and sets up an Obj51B4 from rect. arg2 != 0 acquires one handle
 * (two when flags & 2) through func_80005CB8; on any failure the handles and
 * the object are released. Returns the object, or NULL. */
Obj51B4 *func_800051B4(Rect8 *rect, u16 id, s32 arg2, s32 arg3, u16 flags)
{
  Obj51B4 *obj;
  Obj51B4 *ret = NULL;
  s32 h1, h2;
  s32 *p;
  s32 i;

  obj = poolAlloc(6, sizeof(Obj51B4));
  if (obj != NULL) {
    if (arg2 != 0) {
      h1 = func_80005CB8(id, arg2, arg3, 1, 6);
      if (h1 != 0) {
        obj->h20 = h1;
        if (flags & 2) {
          h2 = func_80005CB8(id, arg2, arg3, 1, 6);
          if (h2 != 0) {
            obj->h24 = h2;
            ret = obj;
          } else {
            streamFreeObject(h1);
            heapFreeBlock(obj);
          }
        } else {
          obj->h24 = 0;
          ret = obj;
        }
      } else {
        heapFreeBlock(obj);
      }
    } else {
      obj->h20 = 0;
      obj->h24 = 0;
      ret = obj;
    }
  }
  if (ret != NULL) {
    p = func_8007ED48(1, 0x10, 8);
    obj->p1C = p;
    i = 4;
    do {
      *p++ = 0;
    } while (--i != 0);
    {
      u16 x = rect->x, y = rect->y, w = rect->w, h = rect->h;
      obj->r1.x = x; obj->r1.y = y; obj->r1.w = w; obj->r1.h = h;
    }
    {
      u16 x = rect->x, y = rect->y, w = rect->w, h = rect->h;
      obj->r0.x = x; obj->r0.y = y; obj->r0.w = w; obj->r0.h = h;
    }
    obj->f34 = (s16)rect->w;
    obj->f34 = (s16)rect->h;
    func_80005744(ret);
    obj->f3C = 150.0f;
    obj->f40 = 20000.0f;
    D_8009BB94 = 150.0f;
    D_8009BB9C = 13000.0f;
    D_8009BB98 = 130.0f;
    D_8009BBA0 = 8000.0f;
    obj->f44 = 4096.0f;
    *(s16 *)((char *)obj + 0x32) = 0x10;
    func_800056F4(ret, 1);
    obj->flags28 = flags;
    obj->b10 = 0;
    obj->b11 = 0;
    obj->b12 = 0;
    obj->b13 = 0;
    obj->v18 = 0;
  }
  return ret;
}
