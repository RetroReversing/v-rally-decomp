typedef struct {u32 w[177];} Scene658;
extern u8 *gLeague,*gRecords,*gSelectState,*gSelectBuffer;
extern s32 *D_800A11B0; extern u8 D_800A1620[];extern Scene658 *gSlotTableB[];extern s32 D_800AFA58,D_800D05D8;extern f64 D_800A56D8;
void func_80061740(Scene658);void menu_draw_text_objs(Scene658,s32);void *select_get_entry(u32);void func_8005937C(u8,u16);void func_8005C198(void);void func_8006185C(s32,s32);void func_80064F98(void);
void func_8004D08C(s32,s32,s16,s16,f32,f32,s32,s32);
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
#define S(p,o) (*(s16*)((u8*)(p)+(o)))
#define P(p,o) (*(u8**)((u8*)(p)+(o)))

/* Per-frame update of the selected menu entry: resolves the entry's scene,
 * refreshes the scene's HUD icons, and draws them when the row is visible. */
void func_80065860(void){
Scene658 scene;

f64 offset;
s32 selected;
u8 idx;
u8 *entry;
u8 *icon_ptr;
s32 result;
entry=P(gLeague,16)+S(gLeague,2)*20;
if(gSelectState[0x245]==0){
selected=entry[14]-entry[13];
H(gRecords,32)=selected;
gSelectState[0x23C]=D_800A1620[(u16)selected];
func_8005937C(entry[14],H(gSlotTableB[gSelectState[0x23C]],20));
if(selected!=D_800AFA58){
if(*D_800A11B0)func_8005C198();
if(gSelectState[0x2BE]==0){
func_80061740(*gSlotTableB[D_800A1620[H(gRecords,32)]]);
D_800AFA58=selected;
}
H(gRecords,34)=0;
}
(s32)select_get_entry(selected);
scene=*gSlotTableB[gSelectState[0x23C]];
}else{
result=(s32)select_get_entry(H(gRecords,30)-1);
scene=*gSlotTableB[H(gRecords,30)];
func_8006185C(result,0);
}
menu_draw_text_objs(scene,0);
if(S(gLeague,2)==1)func_80064F98();
if(gSelectState[0x24D]==0 && gSelectState[0x2BE]==0){
idx=0;
if(idx<H(&scene,20)){
offset=D_800A56D8;
icon_ptr=(u8*)&scene+0x2BC;
do{
func_8004D08C(D_800D05D8,idx,S(gSelectBuffer,0),(s16)(H(gSelectBuffer,2)+idx*gSelectBuffer[8]),(f32)((f64)*(f32*)(gSelectBuffer+4)-offset),*(f32*)(gSelectBuffer+4),icon_ptr[idx],255);
idx++;
}while(idx<H(&scene,20));
}
}
}
