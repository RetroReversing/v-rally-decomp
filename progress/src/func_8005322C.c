#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define M gRecords
extern u8 gOrderState[];
extern u8 stream_state[];
extern u8 *gSlotTableB[];
void func_800529F0(void);
void update_record_entries(void);
void func_800783A8(void);
extern u8 *gRecords;
/* Advances the record counter at +0x22 and, when it reaches the entry's stored
   target, marks the entry done, runs the refresh steps and resets the state. */
void func_8005322C(void)
{
  u8 *state;
  u8 *flag_tbl;
  u8 *entry;
  u8 **slot_ptr;
  u16 slot;
  u8 *state2;
  u8 *tbl2;
  u8 *entry_copy;
  u16 index;
  u16 counter;
  s32 off;
  state = M;
  counter = H(state, 0x22);
  flag_tbl = gOrderState + 0x7db0;
  slot = H(state, 0x1e);
  slot_ptr = &gSlotTableB[slot];
  index = H(state, 0x20);
  counter++;
  off = index * 2;
  H(state, 0x22) = counter;
  entry = (*slot_ptr) + (index * 0x2c4);
  if (counter == H(entry, 0x14))
  {
    *((s16 *) ((flag_tbl + off) + 0x10)) = 1;
    entry_copy = entry;
    H(entry, 0x10) |= 2;
    func_800529F0();
    update_record_entries();
    func_800783A8();
    state = M;
    state2 = state;
    stream_state[0x7f4f] = 5;
    stream_state[0x7f51] = H(state2, 0xe);
    stream_state[0x7f50] = H(state2, 0x20);
    index = H(state2, 0x20);
    H(state2, 0x1e) = 8;
    do
    {
      if (index < 8)
      {
        H(state2, 0x22) = index;
      }
      else
      {
        switch (index)
        {
          case 8:
            H(state2, 0x22) = 0;
            break;

          case 9:
            H(state2, 0x22) = 3;
            break;

          case 10:
            H(state2, 0x22) = 5;
            break;

          case 11:
            H(state2, 0x22) = 6;
            break;

        }

      }
    }
    while (0);
    tbl2 = gOrderState + 0x8030;
    state2 = tbl2;
    *(s32 *)state2 = 6;
    H(M, 0x20) = 0;
  }
}
