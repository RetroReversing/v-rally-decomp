typedef struct {u8 pad[0x54];s32 *state; s32 *stateB; s16 *cfg;u32 pad60;s32 *fx;} Obj24;
extern u8 gOrderState[];
u16 angle_atan2_thunk(s16,s16);s32 car_heading_error(Obj24 *);void mat3x3_from_euler(s16 *,void *);

/* Resets the object's state words, seeds the three-angle array from cfg,
 * and copies the cfg fields into the state table (scaled by <<2 and <<4). */
void func_80024B28(Obj24 *obj){
s16 angles[3];s32 *p;u32 i;s32 off;
{s32 *q=obj->stateB;q[23]=0;q[24]=0;q[25]=0;}
{s32 *q=obj->stateB;q[28]=0;q[29]=0;q[30]=0;}
{s32 *q=obj->stateB;q[8]=0;q[9]=0;q[10]=0;}
{s32 *q=obj->stateB;q[13]=0;q[14]=0;q[15]=0;}
{s32 *q=obj->stateB;q[38]=0;q[39]=0;q[40]=0;}
{s32 *q=obj->stateB;q[33]=0;q[34]=0;q[35]=0;}
angles[0]=0; {extern s32 D_800B68F4; D_800B68F4++;}
angles[1]=angle_atan2_thunk(obj->cfg[0x44/2],obj->cfg[0x50/2]);angles[2]=0;
angles[1]+=car_heading_error(obj);mat3x3_from_euler(angles,(u8 *)obj->cfg+0x40);
obj->stateB[48]=obj->cfg[32]<<2;
obj->stateB[49]=obj->cfg[35]<<2;
obj->stateB[50]=obj->cfg[38]<<2;
obj->stateB[53]=obj->cfg[33]<<2;
obj->stateB[54]=obj->cfg[36]<<2;
obj->stateB[55]=obj->cfg[39]<<2;
obj->stateB[3]=((s32 *)obj->cfg)[21]<<0;
obj->stateB[4]=((s32 *)obj->cfg)[22]<<0;
obj->stateB[5]=((s32 *)obj->cfg)[23]<<0;
obj->stateB[58]=((s32 *)obj->cfg)[21]<<4;
obj->stateB[59]=((s32 *)obj->cfg)[22]<<4;
obj->stateB[60]=((s32 *)obj->cfg)[23]<<4;
p=obj->stateB;p[4]+=10;p=obj->stateB;p[59]=p[4]<<4;
obj->stateB[8]=0;obj->stateB[9]=0;obj->stateB[10]=0;
i=0;do{off=i*4;
#ifdef PORT
*(s32 *)((u8 *)obj->state+off)=0;*(s32 *)((u8 *)obj->state+off+16)=0;*(s32 *)((u8 *)obj->fx+off+0x1cc)=0;i++;*(s32 *)((u8 *)obj->fx+off+0x1dc)=0;
#else
*(s32 *)(off + (int)obj->state)=0;*(s32 *)(off+(int)obj->state+16)=0;*(s32 *)(off+(int)obj->fx+0x1cc)=0;i++;*(s32 *)(off+(int)obj->fx+0x1dc)=0;
#endif
}while(i<4);
}
