extern u8 *gRecords;
extern s32 gOrderState[];
void decodePacketSlots(void);
typedef struct { s32 w[40]; } Block160;

/* Copies the 160-byte block at gRecords+0x44 into the order state at +0x7F28,
 * then decodes the packet slots from it. */
void func_80052BB0(void)
{
    *(Block160 *)((u8 *)gOrderState + 0x7F28) = *(Block160 *)(gRecords + 0x44);
    decodePacketSlots();
}
