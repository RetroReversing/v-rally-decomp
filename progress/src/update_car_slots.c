typedef struct { s32 val; s32 pad[3]; } BeEnt;
extern BeEnt g_car_slot_val[]; extern u8 D_800AFB38[];
s32 getCounterValue(void *); void func_8002C044(void *); void func_8002FBD4(void *,s32,s32); void memset(void *,s32,s32);
/* Car slot index, read from car->0x48. Slots 0..3 are tracked. */
#define OBJ_IDX(o) (*(s32 *)*(u8 **)((o)+0x48))
/* Runs once per frame over the car list (linked through +4). For each tracked car it
   updates the car's track state, compares its value with the last stored one, plays a
   sound when the value has changed enough, and keeps a per-slot flag. */
void update_car_slots(void **head){u8 *car; s32 v,d; u16 cnt; u8 *a1; u32 p;
car=head[0]; if(*(s32*)0x800b6b00==0)memset(D_800AFB38,0,4); if(!car)return;
do{func_8002C044(car); if(OBJ_IDX(car)<4){v=getCounterValue(car); d=g_car_slot_val[OBJ_IDX(car)].val; d-=v; if(d<0)d=-d;
d = d < 4; if(!d){p=*(u16 *)(*(u8 **)(car+0x8c)+0x336); if(p>=4)func_8002FBD4(car,255,3); else if(p)func_8002FBD4(car,220,2);}
g_car_slot_val[OBJ_IDX(car)].val=v; a1=*(u8 **)(car+0x80); cnt=(~*(u32 *)(a1+0x310))>>31; if(*(s32 *)(a1+0x314)>=0)cnt++; if(*(s32 *)(a1+0x318)>=0)cnt++; if(*(s32 *)(a1+0x31c)>=0)cnt++;
if(cnt>=3)D_800AFB38[OBJ_IDX(car)]=1; else if(D_800AFB38[OBJ_IDX(car)]==1){D_800AFB38[OBJ_IDX(car)]=0;func_8002FBD4(car,255,2);}} car=*(u8 **)(car+4);}while(car);}
