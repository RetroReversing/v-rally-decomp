extern u8 *gSelectState;extern u8 gOrderState[],stream_state[];extern u8 *gRecords;
typedef struct VRTextObj{struct VRTextObj *next;u16 id;u8 pad[20];u8 active;}VRTextObj;
void *textObjGet(u32);extern u8 *pool_get_item(void*,int);extern int str_len(u8*);

/* Works out the finishing order from the per-driver points table, stores the
 * result in the standings block at gSelectState+0x24f, and sets the result HUD text. */
void func_800724A4(void){
s8 i;VRTextObj *node,*src;u8 *st=gSelectState+0x24f;u8 count,base,j,pos,rank;u8 *text;
if(gOrderState[0x7fc9]){count=4;base=8;}else{count=8;base=0;}
for(i=0;i<4;i++){(st+i)[1]=0;for(j=0;j<count;j++){
#ifdef PORT
u8 *q=st+j*4;
#else
u8 *q=(u8 *)((s32)(j*4)+(s32)st);
#endif
q+=9;q[i]=0;}}
for(i=0;i<4;i++){pos=(u8)((u32*)(gOrderState+0x7db0))[i];for(j=0;j<4;j++)if(pos<((u32*)(gOrderState+0x7db0))[j])(st+i)[1]++;}
for(j=0;j<count;j++)for(i=0;i<4;i++){u8 *q; s32 offset; pos=gOrderState[0x7dd8+(base+j)*4+i];
#ifdef PORT
q=st+j*4+9;
#else
offset=(s32)(j*4)+(s32)st;q=(u8 *)(offset+9);
#endif
if(pos!=3)q[i]=1<<(2-pos);else q[i]=0;}
for(i=0;i<4;i++){pos=(u8)((u32*)(gOrderState+0x7db0))[i];for(j=0;j<4;j++){if(i!=j&&(st+i)[1]==(st+j)[1]){if(pos>=((u32*)(gOrderState+0x7db0))[j])(st+j)[1]++;else (st+i)[1]++;i=-1;break;}}}
i=0;textObjGet(0);node=textObjGet(7);
for(j=0;j<count;j++){if(((u16*)(gOrderState+0x7dc0))[j+base])(st+i)[0x29]=j,i++;else node->active=0;node=node->next;}st[0]=i;
if((u8)i==count){if(*(u16*)(gRecords+14)>=2&&(st+gRecords[0x32])[1]>(st+gRecords[0x33])[1]) {
rank=st[2];
} else {
rank=st[1];
}
node=textObjGet(5);if(rank==0){node->id=0x10d;node=textObjGet(6);if(base)node->id=0x119;else node->id=0x118;}else{node->id=0x91;if(base)node->id=0x6c;node=textObjGet(6);node->id=rank+0x119;}}
else{node=textObjGet(5);node->id=base?0x6c:0x91;node=node->next;if(st[0]==1)node->id=0x93;else{text=pool_get_item(*(void**)(stream_state+0x807a),0x92);i=str_len(text)-1;while((u32)(text[i]-'0')>=10)i--;text[i]=st[0]+'0';}}
if(base){node=textObjGet(7);src=textObjGet(15);for(i=0;i<8;i++){if(i>=4)node->active=0;else{node->id=src->id;src=src->next;}node=node->next;}}
}