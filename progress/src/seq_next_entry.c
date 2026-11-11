extern u8 gStreamState[],gOrderState[],D_800C8214[],D_800C8324[];
extern u8 D_800C8120[]; extern u32 gPadFlags; extern u8 gCarEntries[]; extern void *func_80051404(void *); extern void func_8004F89C(void *);
typedef struct {u8 pad0[8];u16 flags,state,index,count;u8 rest[0x104];} EntryBase;

/* Steps the sequence object seq to its next entry (68-byte entries, cursor at
 * 0x114, count at 0x110) and returns the value read from the current entry's
 * list. Also updates the entry state and the per-mode flags. */
s32 seq_next_entry(EntryBase *seq) {

 u8 cur=((u8*)seq)[0x114]; EntryBase *ent=(EntryBase*)((u8*)seq+cur*68); s32 ret; u16 n,state;
 if(ent->state!=4){u8*game=*(u8**)(gStreamState+0x32F2);if(!*(u16*)(game+0x1E)){if(*(u16*)(game+0x1A)){((u8*)seq)[0x114]=cur+1;if((u8)(cur+1)==*(u16*)((u8*)seq+0x110))((u8*)seq)[0x114]=0;}}return 0;}
 if(ent->flags&8){u8*game=*(u8**)(gStreamState+0x32F2);if(!*(u16*)(game+0x1E)&&!*(u16*)(game+0x1A)){for(cur=0;cur<*(u16*)((u8*)seq+0x110);cur++){EntryBase*ent2=(EntryBase*)((u8*)seq+cur*68);ent2->state=4;ent2->flags&=0xFFF7;}}else{for(cur=0;cur<4;cur++){EntryBase*ent2=(EntryBase*)((u8*)seq+cur*68);ent2->state=4;ent2->flags&=0xFFF7;}}}
 n=ent->index;if(n==0&&!(ent->flags&0x400))func_8004F89C(seq);
 { s32 *values=*(s32**)((u8*)ent+4); unsigned int offset=ent->index * 4; n=ent->index; ret=*(s32*)((u8*)values+offset); ent->index=n+1; }if(ent->index<ent->count)goto advance;
 if(ent->flags&0x10){u8*obj=func_80051404(seq);*(u32*)(*(u32*)(obj+0x5C)+0x6C)=0;*(u32*)(*(u32*)(obj+0x30)+0x6C)=0;}
 ent->state=5;{u8*game=*(u8**)(gStreamState+0x32F2);state=*(u16*)(game+0x1E);if(state==7){u32*s=(u32*)D_800C8214,*d=(u32*)game;u32*end=s+60;do{struct Copy4 {u32 a,b,c,d;}; *(struct Copy4 *)d=*(struct Copy4 *)s;s+=4;d+=4;}while(s!=end);d[0]=s[0];{u8*game=*(u8**)(gStreamState+0x32F2);u32 f=gPadFlags;s32 players;*(u16*)(game+0x12)=*(u8*)(gStreamState+0x38F2);players=*(u8*)(gStreamState+0x38F0);do {*D_800C8120=0;}while(0);*(u32*)(gOrderState+0x8030)=5;*(u16*)(game+0x1E)=0;gPadFlags=f&0xFFFFFFFE;*(u16*)(game+0xE)=players;}}else{

if((u8*)seq == *(u8**)gCarEntries){if(state!=0&&state<5&&*(u32*)(gOrderState+0x8030)==2)gPadFlags&=0xFFFFFFFE;if(((u8*)seq)[0x114]==0)*(u8*)D_800C8324=(u8)1;else if(((u8*)seq)[0x114]==1 && *(u16*)(*(u8**)(gStreamState+0x32F2)+0xE)==2)*(u8*)(gStreamState+0x8076)|=2;}else{ent->index=0;}}}
 advance: ((u8*)seq)[0x114]++; if(((u8*)seq)[0x114]==*(u16*)((u8*)seq+0x110))((u8*)seq)[0x114]=0;return ret;}
