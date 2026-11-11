s32 func_800526E4();
s32 func_80052BB0();
s32 func_800595EC();
s32 select_state_init_hooks();
extern void *gSelectState;
extern u8 D_800A1700;
extern char D_800A5CE4[];
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_80070C34;
extern s32 best_times_select_update;
/* Select-screen update step: in mode 1 it refreshes the flag byte and runs the mode-1 path;
 * otherwise it sets up the mode-0 path and installs the select-screen callbacks. Then it
 * copies the flag word into the byte at gStreamState+0x7F50. */
s32 func_800708F4(s32 arg0, s32 arg1)
{
  u16 *cur_item_flags;
  s32 *cur_item_ptr;
  if (D_800A1700 == 1)
  {
    *((u8 *) (gOrderState + 0x7FC9)) = (u8) (((u16) (*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x20)))) >= 8U);
    func_800526E4((gOrderState + 0x7FC9) - 0x219);
    *((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (((*((s16 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 2))) * 0x14) + (*((s32 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 0x10))))) + 8)))) + 4)))) + 0x2C)) = 7;
    select_state_init_hooks(arg0, arg1);
  }
  else
  {
    func_80052BB0();
    cur_item_flags = (u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x20);
    cur_item_ptr = (s32 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 0x10);
    *cur_item_flags = (u16) (((*((u8 *) (gOrderState + 0x7FC9))) != 0) * 8);
    *((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (((*((s16 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 2))) * 0x14) + (*cur_item_ptr))) + 8)))) + 4)))) + 0x2C)) = 3;
    func_800595EC(&D_800A5CE4);
    *((s32 **) (((char *) gSelectState) + 0x288)) = &func_80070C34;
    *((s32 **) (((char *) gSelectState) + 0x28C)) = &best_times_select_update;
  }
  *((s8 *) (gStreamState + 0x7F50)) = (s8) (*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x20)));
  return 0;
}
