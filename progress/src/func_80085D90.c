#define F(e,t,o) (*(t*)((u8*)(e)+(o)))
s32 taskOpen(s32, s32, s32);
s32 taskRecvMsg(s32);
s32 func_8007F73C(s32, s32);
void motor_pak_init_all(void);
void func_80086370(s32);
void motor_pak_reset(s32, u8);
s32 osContStartQuery(void *);
s32 osContGetQuery(void *);
s32 osContStartReadData(void *);
s32 osContGetReadData(void *);
extern void *gContCtx;
extern s32 gOrderState;

/* Controller polling loop, runs forever. Each pass waits for the pad-poll flag, reads the
 * controllers, and updates each pad's button state and its node timers. Every 30 passes
 * it calls motor_pak_init_all once. */
void func_80085D90(void)
{
  void *cont;
  s32 hit_count;
  s32 handle;
  s32 prev;
  s32 i;
  s32 frame;
  void *ctl_base;
  s32 state_two;
  s32 node_state;
  u16 buttons;
  u16 mask;
  void *base;
  void *slot;
  void *ctl;
  void *pad;
  void *ctl2;
  frame = 0;
  i = taskOpen(4, 0, 8);
  handle = i;
  cont = (u8 *) (&gOrderState);
  cont = cont + 0x5A38;
  state_two = 2;
  *((u8 *) (((u8 *) gContCtx) + 0x39C)) = (u8) ((*((u8 *) (((u8 *) gContCtx) + 0x39C))) | 1);
  loop:
  taskRecvMsg(handle);

  if (!((*((u8 *) (((u8 *) gContCtx) + 0x39C))) & 1))
  {
    goto loop;
  }
  osContStartReadData(cont);
  func_8007F73C(0, 3);
  osContGetReadData(((u8 *) gContCtx) + 0x1C);
  osContStartQuery(cont);
  func_8007F73C(0, 3);
  osContGetQuery(((u8 *) gContCtx) + 0xC);
  base = gContCtx;
  for (i = 0; i < (*((s32 *) (((u8 *) base) + 4))); i++)
  {
    slot = (void *) ((i * 4) + ((s32) base));
    buttons = *(*((u16 **) (((u8 *) slot) + 0x34)));
    pad = (void *) (((*((u8 *) (((u8 *) (*((void **) (((u8 *) slot) + 0x38C)))) + 3))) * 2) + ((s32) base));
    *((u16 *) (((u8 *) pad) + 0x44)) = buttons;
    mask = (*((u16 *) (((u8 *) pad) + 0x4C))) | (~buttons);
    *((u16 *) (((u8 *) pad) + 0x4C)) = mask;
    *((s16 *) (((u8 *) pad) + 0x54)) = (s16) ((*((u16 *) (((u8 *) pad) + 0x44))) & mask);
    ctl = *((void **) (((u8 *) slot) + 0x38C));
    node_state = *((s32 *) (((u8 *) ctl) + 4));
    if (node_state == 1)
    {
      prev = *((s32 *) (((u8 *) ctl) + 8));
      if (prev == node_state)
      {
        hit_count = *((s32 *) (((u8 *) ctl) + 0x10));
        *((s32 *) (((u8 *) ctl) + 0x10)) = hit_count + 1;
        if ((*((s32 *) (((u8 *) ctl) + 0xC))) == hit_count)
        {
          func_80086370(*((s32 *) (((u8 *) (*((void **) (((u8 *) slot) + 0x38C)))) + 0)));
          *((s32 *) (((u8 *) (*((void **) (((u8 *) (((u8 *) gContCtx) + (i * 4))) + 0x38C)))) + 0x10)) = prev;
        }
        else
        {
          ctl2 = *((void **) (((u8 *) slot) + 0x38C));
          if ((*((s32 *) (((u8 *) ctl2) + 0x10))) == state_two)
          {
            motor_pak_reset(*((s32 *) (((u8 *) ctl2) + 0)), *((u8 *) (((u8 *) ctl2) + 0x14)));
          }
        }
      }
      else
        if ((*((volatile s32 *) (((u8 *) ctl) + 8))) == 0)
      {
        motor_pak_reset(*((s32 *) (((u8 *) ctl) + 0)), *((u8 *) (((u8 *) ctl) + 0x14)));
        *((s32 *) (((u8 *) (*((void **) (((u8 *) (((u8 *) gContCtx) + (i * 4))) + 0x38C)))) + 8)) = state_two;
      }
    }
    base = gContCtx;
  }

  frame++;
  if ((frame & 0xFF) != 0x1E)
  {
    goto loop;
  }
  frame = 0;
  motor_pak_init_all();
  goto loop;
}
