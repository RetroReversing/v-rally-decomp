typedef struct { u8 b; u8 pad[0x17]; } E18;
extern E18 D_800C7FA1[];
extern u8 D_800C81FC;
extern u8 gStreamPhase;
extern u8 *gSelectState;
extern char stream_state[];
void select_arm_if_clear(void);
void select_reset_all(s32, s32);
void select_request_reset(s32, s32);

/* Starts a new select round: resets the select state, and when the current
   stream header has flag 0x800 set, sets up the 4-entry slot table from the low
   two bits of its byte 0x23 and clears the header's timer word. Then marks the
   state as 1 and returns 0. */
s32 func_800643F0(s32 arg0, s32 arg1)
{
  u8 *header;
  u8 *header2;
  u8 i;
  u32 v;
  u16 t;

  select_arm_if_clear();
  select_reset_all(arg0, arg1);
  i = 1;
  gSelectState[0x2BD] = 1;
  header = *(u8 **)(stream_state + 0x32F2);
  if (*(u16 *)(header + 0x2C) & 0x800) {
    *(s16 *)(header + 0x1E) = 8;
    v = header[0x23] & 3;
    D_800C7FA1[0].b = v;
    if (v == 0) { D_800C81FC = i; } else { D_800C81FC = 0; }
    v &= 0xFF;
    do {
      if (i == v) {
        D_800C7FA1[i].b = 0;
        i++;
      } else {
        D_800C7FA1[i].b = i;
        i++;
      }
    } while (i < 4);
    header2 = *(u8 **)(stream_state + 0x32F2);
    t = *(u16 *)(header2 + 0x20);
    *(u16 *)(header2 + 0x20) = 0;
    *(u16 *)(header2 + 0x22) = t;
  }
  gStreamPhase = 1;
  select_request_reset(0, 0);
  return 0;
}
