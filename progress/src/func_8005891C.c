typedef struct {void *fn;void *data;void *subs;u8 count,start,cur,extra;s32 zero;} LeaguePage;
typedef struct {void *fn;void *items;u8 count,visible,enabled,pad;} LeagueSub;
typedef struct {s32 id;u8 kind;u8 pad[3];s32 value;} LeagueItem;
typedef struct {u16 pageCount,pageIndex,subIndex,pad;s32 hold,anim;LeaguePage *pages;u8 active;u8 padding[3];} League;
extern u8 D_800A5254[],stream_state[];
void resolve_path(void *);s32 *func_80081664(s32,void *);void order_lookup_info(void *,void *,void *);void *poolAlloc(s32,s32);void heap_free_stub(s32 *);void func_80059A60(void);void func_8005A764(void);

/* Builds the league menu tree from the data block at src+0x4c: a list of
 * pages, each with sub-menus and item records, all allocated with
 * poolAlloc. The result is stored in gLeague (stream_state+0x325a). */
void func_8005891C(u8 *src){
s32 entryValue,entryFlag; s32 *block,*cursor;u32 pageCount; League *league;LeaguePage *page;LeagueSub *sub;LeagueItem *item;s32 subCount,itemCount; s8 runningIndex;
resolve_path(D_800A5254);block=func_80081664(1,src+0x4c);order_lookup_info(src+0x4c,&entryValue,&entryFlag);
league=poolAlloc(1,24);pageCount=*block;cursor=block+1;
league->pageCount=pageCount;league->pageIndex=0;league->subIndex=0;league->hold=0;league->anim=0;league->pages=0;league->active=0;
page=poolAlloc(1,league->pageCount*20);league->pages=page;runningIndex=0;
if(pageCount)do{
subCount=*cursor++;page->start=runningIndex;page->cur=runningIndex;page->zero=0;runningIndex+=subCount;page->count=subCount;page->fn=func_80059A60;page->subs=0;page->data=0;
if(subCount){sub=poolAlloc(1,subCount*12);page->subs=sub;do{
itemCount=*cursor++;sub->count=itemCount;sub->fn=func_8005A764;sub->visible=1;sub->enabled=1;
if(itemCount){item=poolAlloc(1,itemCount*12);sub->items=item;do{item->id=*cursor++;itemCount--;item->kind=*cursor++;item->value=*cursor++;item++;}while(itemCount);}
subCount--;sub++;
}while(subCount);}
itemCount=*cursor++;page->extra=itemCount;
if(itemCount){item=poolAlloc(1,itemCount*12);page->data=item;do{item->id=*cursor++;itemCount--;item->kind=*cursor++;item->value=*cursor++;item++;}while(itemCount);}
page++;pageCount--;
}while(pageCount);
heap_free_stub(block);*(League **)(stream_state+0x325a)=league;
}
