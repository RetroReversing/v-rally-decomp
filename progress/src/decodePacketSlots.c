#define H(p) (*(u16*)(p))
typedef struct 
{
  u16 f15 : 1;
  u16 f14 : 1;
  u16 f13 : 1;
  u16 pad : 3;
  u16 f8 : 2;
  u16 f4 : 4;
  u16 f0 : 4;
  u16 g12 : 4;
  u16 g8 : 4;
  u8 b3;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  s16 sums[4];
  u8 pad12[0x1BA - 0x12];
  s8 code;
} SlotPacket;
typedef struct 
{
  u16 v;
  u8 pad[38];
} SlotEnt;
typedef struct 
{
  u8 pad0[0xe];
  u16 mode;
  u8 pad10[0x22];
  u8 slot[4];
  u8 pad36[0x18];
  SlotEnt ent[4];
} SlotState;
typedef struct 
{
  s32 cnt[4];
  u16 flag[12];
  u8 map[12][4];
} DecodeBlk;
extern u8 gOrderState[];
extern u8 gStreamState[];
extern DecodeBlk gDecodeBlk;
extern s32 D_800B6768[4];
extern void record_slot_init(s32, s32);
extern SlotState *gSlotState;
static __inline__ int bitSet(u32 word,u32 mask){do{do{do{do{do{return (word&mask)==mask;}while(0);}while(0);}while(0);}while(0);}while(0);}

/* Decodes the slot packet at gStreamState+0x6E64 into gSlotState: four slots
 * (slot[0..3] with their ent[].v values; each slot is recorded with
 * record_slot_init), the per-group flags in gDecodeBlk.flag, and two words
 * in D_800B6768. For each of the 4 entries it counts 2-bit codes from the
 * packet bits into gDecodeBlk.cnt. */
void decodePacketSlots(void)
{
  u8 slotUsed[4];
  u16 bits;
  SlotPacket *pkt;
  u8 j;
  u8 i;
  u8 count;
  u8 base;
  u8 *cntp;
  s16 v;
  u32 decoded;
  int b;
  u8 guardN;
  u32 cur;
  u32 slotOff;
  for (i = 0; i < 4; i++)
  {
    slotUsed[i] = 0;
  }

  pkt = (SlotPacket *) (gStreamState + 0x6e64);
  gOrderState[0x7FCA] = pkt->f14;
  if (gOrderState[0x7FCA])
  {
    gOrderState[0x7FC8] = pkt->f13;
    gOrderState[0x7FC9] = pkt->f15;
    gSlotState->mode = pkt->f8;
    gSlotState->slot[0] = pkt->f4;
    slotUsed[gSlotState->slot[0]] = 1;
    gSlotState->ent[gSlotState->slot[0]].v = gStreamState[0x701e] & 15;
    if (gSlotState->mode >= 2)
    {
      gSlotState->slot[1] = pkt->f0;
      slotUsed[gSlotState->slot[1]] = 1;
      gSlotState->ent[gSlotState->slot[1]].v = gStreamState[0x701e] >> 4;
    }
    else
    {
      for (i = 0; i < 4; i++)
      {
        if (!slotUsed[i])
        {
          slotUsed[i] = 1;
          break;
        }
      }

      gSlotState->slot[1] = i;
      gSlotState->ent[gSlotState->slot[1]].v = pkt->f0;
      record_slot_init(gSlotState->slot[1], pkt->f0);
    }
    for (i = 0; i < 4; i++)
    {
      if (!slotUsed[i])
      {
        slotUsed[i] = 1;
        break;
      }
    }

    gSlotState->slot[2] = i;
    gSlotState->ent[gSlotState->slot[2]].v = pkt->g12;
    record_slot_init(gSlotState->slot[2], pkt->g12);
    for (i = 0; i < 4; i++)
    {
      if (!slotUsed[i])
      {
        slotUsed[i] = 1;
        break;
      }
    }

    gSlotState->slot[3] = i;
    gSlotState->ent[gSlotState->slot[3]].v = pkt->g8;
    record_slot_init(gSlotState->slot[3], pkt->g8);
    if (gOrderState[0x7fc9])
    {
      count = 4;
      base = 8;
    }
    else
    {
      count = 8;
      base = 0;
    }
    bits = ((u8 *) pkt)[9];
    for (i = 0; i < count; i++)
    {
      b = i;
      do
      {
        do
        {
          if (bitSet(bits,(1<<b)))
          {
            gDecodeBlk.flag[base + b] = 1;
          }
          else
          {
            gDecodeBlk.flag[base + b] = 0;
          }
        }
        while (0);
      }
      while (0);
    }

    guardN=(u8)count;
    gDecodeBlk.cnt[0] = 0;
    gDecodeBlk.cnt[1] = 0;
    gDecodeBlk.cnt[2] = 0;
    gDecodeBlk.cnt[3] = 0;
    for (j = 0; j < 4;)
    {
do{do{do{do{cur=(u8)j;}while(0);}while(0);}while(0);}while(0);
      bits = H((((u8 *) pkt) + 10) + (cur * 2));
      i=0;
      if(guardN) { u8 boundN=(u8)count;slotOff=cur;cur=(u32)gDecodeBlk.cnt;cntp=(u8 *)((u32)cur+slotOff*4); do {

{u32 m1,scratch;int m0,b0,b1;m1=(u8)i;{u16 *row=&gDecodeBlk.flag[base+m1];b=row-gDecodeBlk.flag;}do{do{m1<<=1;do{do{do{do{m0=1<<m1;}while(0);}while(0);}while(0);}while(0);m1++;do{do{do{do{m1=1<<m1;}while(0);}while(0);}while(0);}while(0);do{do{do{b0=bits;b0^=0xffff;b0&=m0;b0=(b0==0);}while(0);}while(0);}while(0);scratch=bits;scratch^=0xffff;scratch&=m1;do{m1=b*4;m1+=(u32)gDecodeBlk.map;m1+=slotOff;}while(0);b1=(scratch==0);decoded=(b1<<1)|b0;}while(0);}while(0);*(u8 *)m1=decoded;}v=(u8)decoded;

        if(v==1)goto add_two;if(v<2){if(v==0)goto add_four;goto counted;}do{do{do{if(v==2)goto add_one;}while(0);}while(0);}while(0);goto counted;add_four:*((s32 *)cntp)+=4;goto counted;add_two:*((s32 *)cntp)+=2;goto counted;add_one:*((s32 *)cntp)+=1;counted:;

      ++i;
      } while(i<boundN); }

    do{do{++j;}while(0);}while(0);}

    for (i = 0; i < 4; i++)
    {
      D_800B6768[i] = 0;
    }

    D_800B6768[0] = (((u8 *) pkt)[3] + (((u8 *) pkt)[4] << 8)) + (((u8 *) pkt)[5] << 16);
    D_800B6768[1] = (((u8 *) pkt)[6] + (((u8 *) pkt)[7] << 8)) + (((u8 *) pkt)[8] << 16);
  }
}
