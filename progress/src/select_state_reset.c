s32 list_set_flag2_at_index(s32);
void func_8005A6E0(u32);
void league_set_flag14(void *);
extern void *gSelectState;
extern void *gLeague;
extern char gStreamState[];

/* Resets the select screen: clears the select state's flag at +0x245 and marks the league
 * flag. If the stream's current object (at gStreamState+0x325A) has type 2, returns its
 * field at +0x20 plus 0xF. Otherwise clears four text-object flags, and returns the same
 * field plus 6. */
s32 select_state_reset(void)
{
    *((s8 *) (((char *) gSelectState) + 0x245)) = 0;
    league_set_flag14(gLeague);
    if ((*((s16 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 2))) == 2)
    {
        return (*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x20))) + 0xF;
    }
    list_set_flag2_at_index(0);
    func_8005A6E0(0x13);
    func_8005A6E0(0x14);
    func_8005A6E0(0x15);
    func_8005A6E0(0x16);
    return (*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0x20))) + 6;
}
