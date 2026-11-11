typedef struct {s32 a,b,c,d;} W55;
typedef struct {s32 a,b,c,d;} __attribute__((packed)) P55;
typedef struct {u8 *data;u16 count;} SrcBlock;
extern u8 gOrderState[],D_800A1300[],D_800A1308[];
s32 strCmp(void *,void *);

/* Copies rows of 16 bytes from a source block into the output, 34 bytes of
 * output per row, and writes an all-0xFF pattern into the row when its record
 * fails either check. Advances the output pointer past each row. */
void func_80055B1C(u8 **out,SrcBlock *blk){
u8 *rec;u8 *sp;u8 *src,*dst,*end;u16 *row_idx;u16 count;s32 row;s32 pad[2];
count=blk->count;src=blk->data;row=0;
if(count){u8 blank=255;row_idx=(u16 *)(src+32);do {
dst=*out;
sp=src;if(((u32)src|(u32)dst)&3){end=(u8 *)row_idx;do{*(P55 *)dst=*(P55 *)sp;sp+=16;dst+=16;}while(sp!=end);}
else {end=(u8 *)row_idx;do{*(W55 *)dst=*(W55 *)sp;sp+=16;dst+=16;}while(sp!=end);}
{ s32 head=*(s16 *)sp; *(s16 *)dst=head; }
(*out)[3]=10;
rec=*(u8 **)(gOrderState+0x237c)+*row_idx*20;
if(strCmp(rec,D_800A1300)==0 || strCmp(rec,D_800A1308)==0){
(*out)[0]=blank;(*out)[1]=blank;(*out)[2]=blank;
(*out)[4]=blank;(*out)[5]=blank;(*out)[6]=blank;(*out)[7]=blank;
(*out)[8]=blank;(*out)[9]=blank;(*out)[10]=blank;(*out)[11]=blank;
(*out)[12]=blank;(*out)[13]=blank;(*out)[14]=blank;(*out)[15]=blank;}
row_idx+=17;row++;*out+=34;src+=34;
}while(row<count);}}
