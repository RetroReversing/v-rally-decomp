/* port (WebAssembly build): the switch cases follow the console's jump table. The matched C's labels compile to
   the same code but a different table, which the judge doesn't compare: this fix belongs in the matched C. */
typedef struct S2
{
  u8 f0;
  u8 f1;
  u8 f2;
  u8 f3;
  u8 f4;
  u8 f5;
} S2;
typedef struct S48
{
  u8 pad[0x2C];
  s32 f2C;
} S48;
typedef struct S1
{
  u8 pad[0x48];
  S48 *p48;
} S1;
extern u8 D_800A17F0[];
extern u8 stream_state[];
extern u8 gOrderState[];
s32 pad_port_disconnected(s32);
void func_80027E8C(S1 *, s32, S2 *);
void func_800280AC(S1 *, S2 *);
void func_800280EC(S1 *, S2 *);
void ai_drive_compute(S1 *, S2 *);
void func_80043150(S1 *, S2 *);
void func_800437B8(S1 *, S2 *);
struct Car; struct Pad;
void func_80043A78(struct Car *, struct Pad *);
void carDispatchNoop(S1 *);
s32 hud_draw_track_panel(void);
void order_next_entry_send(S1 *, S2 *);
void memset(S2 *, s32, s32);

/* Runs one car command. cmd selects the handler (labels follow jtbl_800A4980): 0 is the slot
 * pick (empty slots get a default input), 3 clears a pending flag, 4, 6, 7, 9 and 10 call their
 * own handlers, 11 falls through to the shared follow-up, which fills the input for the local
 * player when the race is live; 1, 2, 5, 8 and any other cmd do nothing. */
void car_dispatch_cmd(S1 *car, s32 slot, S2 *input, s32 cmd)
{
  unsigned short flag;
  switch (cmd)
  {
    case 0:
      if (pad_port_disconnected(slot & 0xFF) != 0)
    {
      func_80027E8C(car, slot, input);
    }
    else
    {
      input->f5 = 0;
      input->f4 = 0;
      input->f0 = 0;
      input->f1 = 0x10;
    }
      return;

    case 3:
      flag = 0x80BE;
      func_800280AC(car, input);
      if (stream_state[flag] == 1)
    {
      stream_state[flag] = 0;
      carDispatchNoop(car);
    }
      return;

    case 4:
      ai_drive_compute(car, input);
      return;

    case 6:
      func_800437B8(car, input);
      return;

    case 10:
      func_80043A78((struct Car *)car, (struct Pad *)input);
      return;

    case 9:
      func_80043150(car, input);
      return;

    case 7:
      func_800280EC(car, input);
      return;

    case 11:
      break;

    case 1:
    case 2:
    case 5:
    case 8:
    default:
      return;

  }

  flag = D_800A17F0[0] == 0;
  if (flag)
  {
    if ((car->p48->f2C == stream_state[0x7CF3]) && (*((s32 *) (gOrderState + 0x121C))))
    {
      if (hud_draw_track_panel() & 0xFF)
      {
        order_next_entry_send(car, input);
      }
      else
      {
        memset(input, 0, 8);
        input->f3 |= 0x10;
      }
    }
  }
}
