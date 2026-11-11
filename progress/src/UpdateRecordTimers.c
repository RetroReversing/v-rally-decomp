extern u8 *gRecords;
extern s32 D_8009F4F0,D_8009F4F4,D_8009F4F8,D_8009F4FC,D_8009F500,D_8009F504,D_8009F508,D_8009F50C,D_8009F514,D_8009F518,D_8009F51C;
/* Field accessor: F(4FC, off) is the s32 at D_8009F4FC + off. */
#define F(n,o) (*(s32*)((char*)&D_8009F##n+(o)))
/* Byte offset of the current record: its u16 index at +0x16, times 0x30. */
#define IDX(p) (*(u16*)((p)+0x16)*0x30)
/* Updates the per-record timing table (D_8009F4F0..D_8009F51C) for the current
 * record in gRecords: caps the two counters at 255, copies and differences the
 * samples, and stores the averaged values in the 0x508..0x51C slots. */
void UpdateRecordTimers(void){u8 *rec;s32 off;u32 o;char *base;
off=IDX(gRecords);if(F(4FC,off)>=256)F(4FC,off)=255;
off=IDX(gRecords);if(F(4F8,off)>=256)F(4F8,off)=255;
o=IDX((rec=gRecords));F(500,o)=F(4F0,o);
o=IDX(rec);F(504,o)=F(4FC,o);
base=(char*)&D_8009F4F0;
F(508,IDX(rec))=(F(4F4,IDX(rec))-*(s32*)(base+IDX(rec)))/3;
F(50C,IDX(rec))=(F(4F8,IDX(rec))-F(4FC,IDX(rec)))/3;
o=IDX(rec);F(518,o)=F(514,o)/3;
F(51C,IDX(rec))=F(514,IDX(rec))/2;
}
