/* Sets up the two league result slots: picks a winner flag for each from the current
 * select state and the stored entry, then draws both slots through select_propagate_values. */
extern unsigned char D_800C7112;
extern int gLeague;
void *select_get_entry(u32);
s32 slotSetSelected();
void select_propagate_values(s32, u32, u32);
s32 select_flag_4000_set();
s32 record_set_byte9();
extern void *gSelectState;
extern char stream_state[];
void func_80070630(void)
{
  s32 mode;
  s8 flag;
  void *slot;
  s32 new_var;
  slot = select_get_entry(1);
  new_var = select_flag_4000_set();
  flag = 0;
  if (new_var != 0)
  {
    mode = 1;
    if ((D_800C7112 & 3) == (*((u16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0xE))))
    {
      flag = 1;
      mode = 0;
    }
  }
  else
  {
    mode = 1;
  }
  record_set_byte9(gLeague, 1, flag);
  *((s8 *) (((char *) slot) + 0x41)) = flag;
  select_propagate_values(1, mode, *((s32 *) (((char *) gSelectState) + 0x14)));
  slot = select_get_entry(2);
  if ((*((u16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0x38))) != 0)
  {
    flag = 1;
    mode = 0;
  }
  else
  {
    flag = 0;
    mode = 1;
  }
  record_set_byte9(gLeague, 2, flag);
  *((s8 *) (((char *) slot) + 0x41)) = flag;
  slotSetSelected(2, ((u16) (*((u16 *) (((char *) (*((void **) (stream_state + 0x32F2)))) + 0x20)))) >= 8U);
  select_propagate_values(2, mode, *((s32 *) (((char *) gSelectState) + 0x14)));
}
