#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  u8 pad0[0xE];
  u16 kind;
} Arg;
typedef struct 
{
  u8 pad0[0x558];
  void *cur;
  void *task;
  s32 enabled;
} State;
typedef void (*Handler)();
extern s32 D_800A19B4;
extern u8 D_800AE850[];
extern Handler D_800C8038[];
extern void func_8007F394(void *, s32);
extern s32 func_8007F73C(s32, s32);
extern void func_8007F7DC(s32, s32, s32);
extern void func_8008DD00(void *);
extern void func_8008DF40(void);
extern s32 osRecvMesg(void *, void **, s32);
extern s32 osSendMesg(void *, void *, s32);
extern void osSpTaskStartGo(void *);
extern s32 osSpTaskYielded(void *);
extern void osWritebackDCacheAll(void);
static inline s16 *inline_fn(void *arg0, int arg1)
{
  return (s16 *) (((u8 *) arg0) + arg1);
}

void func_8007FC44(Arg *self)
{
  Arg *obj = self;
  State *state = (State *) (D_800AE850 + 0x1D10);
  s32 mode2 = 2;
  s32 mode1 = 1;
  Handler *table = D_800C8038;
  void *old;
  s32 result = 0;
  void *msg = 0;
  s32 action;
  for (;;)
  {
    osRecvMesg(((u8 *) obj) + 0x14, &msg, 1);
    osWritebackDCacheAll();
    old = state->cur;
    D_800A19B4 = 0;
    if (old != 0)
    {
      if ((*((s16 *) (((u8 *) msg) + 0x4A))) < (*inline_fn(old, 0x4A)))
      {
        result = func_8007F73C(0x22, 2);
        D_800A19B4 = mode2;
      }
      else
      {
        func_8008DF40();
        result = func_8007F73C(0x22, 2);
        if (osSpTaskYielded(old))
        {
          D_800A19B4 = mode1;
        }
        else
        {
          D_800A19B4 = mode2;
        }
      }
    }
    func_8007F394(obj, 0);
    ((s32 (*)(void))table[obj->kind])();
    state->task = msg;
    *((void **) (((u8 *) msg) + 0x40)) = D_800AE850 + 0x6728;
    func_8008DD00(msg); osSpTaskStartGo(msg);
    result = func_8007F73C(0x22, 2);
    ((void (*)(void *))table[0x90 / 4])(msg);
    state->task = 0;
    if (state->enabled)
    {
      osSendMesg(((u8 *) state) + 0x10, &result, 1);
    }
    action = D_800A19B4;
    if (action == mode1)
    {
      func_8008DD00(old);
      osSpTaskStartGo(old);
    }
    else
      if (action == mode2)
    {
      func_8007F7DC(0x22, 2, result);
    }
    osSendMesg(*((void **) (((u8 *) msg) + 0x40)), *((void **) (((u8 *) msg) + 0x44)), 1);
  }

}


