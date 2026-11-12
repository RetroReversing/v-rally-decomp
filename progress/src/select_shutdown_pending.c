extern s32 D_800C8374,D_800B5B44,D_800AFA64;
extern u8 gStreamPhase,gStreamReady;
extern s8 D_8009BBBC;
extern s16 D_800A0370,D_800A0372;
extern u16 D_800A0374,D_800A0376;
extern u8 *gSceneSlot0,*gSelectState;
extern u8 gGameState[];
void func_8001BAF4();void func_80015C74();void streamFreeObject();

/* Shuts down the pending work for the current state code (1 or 2), clears the
   related flags, then copies two timing words from gSceneSlot0 into D_800A0374/76
   and marks the select state as idle (-1). */
void select_shutdown_pending(void){
s32 state=gStreamPhase;
if(state==1)goto state1_cleanup;
if(state<2)goto copy_timing;
if(state!=2)goto copy_timing;
func_8001BAF4(D_800C8374);
func_80015C74(gGameState+0x6BD0,0);
D_8009BBBC=0;
if(gStreamReady)streamFreeObject(D_800B5B44);
gStreamPhase=0;
gStreamReady=0;
goto clear_pending;
state1_cleanup:
func_8001BAF4(D_800C8374);
func_80015C74(gGameState+0x6BD0,0);
if(gStreamReady)streamFreeObject(D_800B5B44);
gStreamReady=0;
D_8009BBBC=0;
clear_pending:
D_800AFA64=0;
copy_timing:
D_800A0370=0;
D_800A0372=0;
D_800A0374=*(u16 *)(gSceneSlot0+4);
D_800A0376=*(u16 *)(gSceneSlot0+6);
((s8 *)gSelectState)[0x2BD]=-1;
}
