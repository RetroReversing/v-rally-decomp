#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
extern s32 gStatRows;
typedef struct { u8 pad[0x44]; s32 v; u8 pad2[4]; } StatRecord;

/* Copies values 2..9 of the record array into stat row `rec[1].rowIndex` (10 s16 entries per row). */
void func_8001CB88(StatRecord *rec) {
 u16 i=2; s16 (*tbl)[10]=(s16 (*)[10])&gStatRows;
 s16 *dst = tbl[*(u16 *)((u8 *)rec+0x92)];
 do { dst[i]=rec[i].v; i++; } while(i<10);
}

