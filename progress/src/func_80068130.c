typedef struct Obj Obj;

struct Obj { void *next;
 u8 pad0[0xB];
 u8 f;
 u8 g;
 u8 h;
 u8 pad12[8];
 u8 enabled;
 };

struct Item { u8 pad[14];
 u8 value;
 u8 tail[5];
 };

typedef struct { u8 pad0[2];
 s16 count;
 u8 pad4[0xC];
 struct Item *items;
 } Manager;

typedef struct { u8 pad0[0x228];
 u8 cur;
 u8 prev;
 u8 pad22A[0x1B];
 u8 flag;
 } State;

extern Manager *gLeague;
 extern u8 *gRecords;
 extern State *gSelectState;

void func_80057D5C(s32,s32,s32,s32);void *select_get_entry(u32);void *textObjGet(u32);
 void record_set_byte9(Manager *,s32,s32);

/* Refreshes the league menu from the four record slots in gRecords. Slots whose
   byte at +0x44 (stride 0x28) is 0x5B or more count as qualified. Sets up the menu
   for the qualified or unqualified case, updates the saved cursor in gSelectState, and
   returns the chosen menu value (12 or 13). */
s32 func_80068130(void) {
 s8 qualified=0, first_open=-1, idx=0;
 union { s32 ret;
 Obj *obj;
 } res;
 Obj *item;
 u8 *rec=gRecords+0x44;

 do { if (rec[(s8)idx*0x28]>=0x5b) qualified++;
 else if(first_open<0) first_open=idx;
 idx++;
 } while(idx<4);

 res.obj=select_get_entry(1);

 if(!qualified){record_set_byte9(gLeague,13,0);
res.obj->f=0x50;
res.obj->g=0x50;
res.obj->h=0x50;
 gLeague->items[gLeague->count].value=12;
 item=textObjGet(7);
item->enabled=1;
item=item->next;
res.ret=12;
item->enabled=1;
}
 else {item=textObjGet(7);
item->enabled=0;
item=item->next;
item->enabled=0;
record_set_byte9(gLeague,13,1);
res.obj->f=0xc8;
res.obj->g=0xc8;
res.obj->h=0xc8;
record_set_byte9(gLeague,12,1);
if(qualified==4){record_set_byte9(gLeague,12,0);
res.obj=select_get_entry(0);
res.obj->f=0x50;
res.obj->g=0x50;
res.obj->h=0x50;
res.ret=13;
 gLeague->items[gLeague->count].value=13;
}else {res.ret=12;
 gLeague->items[gLeague->count].value=12;
}
}
 if(!gSelectState->flag){func_80057D5C(15,16,2,5);
gSelectState->flag=1;
 } idx=gSelectState->cur;
if((u8)idx<4&&rec[(s8)idx*0x28]<0x5b)gSelectState->prev=idx;
else {gSelectState->cur=first_open;
gSelectState->prev=first_open;
};
return res.ret;

}
