typedef struct { u8 pad0[4]; s32 count; u8 pad8[0x394]; u8 flags; } VRPadState;
typedef struct { u8 pad0[0xC]; u16 status; u8 type; u8 padF; } VRCont;
typedef struct { u8 pad[0x330]; s32 a; s32 b; } QQ;
extern VRPadState *gContCtx;
extern u8 gOrderState[];
extern u8 gContPort0Found[];
extern u8 D_800B4288[];
#define DUMMY_UNUSED 0
s32 taskOpen(s32,s32,s32); s32 func_8007F634(s32); s32 taskRecvMsg(s32); s32 func_8007F73C(s32,s32); s32 motor_pak_reset(s32,s32); s32 osContStartQuery(void *); s32 osContGetQuery(void *); s32 osMotorInit(void *,void *,s32);

/* If the pad system is enabled, polls the controllers and sets up a rumble pak on each
 * connected pad that has one. Each pad gets a 0x18-byte record in the pad state (a = 1 when a
 * rumble pak was started, 0 otherwise). Clears the pad-state busy bit while it works. */
void func_80085AE8(void) {
 s32 i, recOff, motorOff, query, one, zero;
 VRCont *cont;
 QQ *rec;
 VRPadState *state;
 if (gContPort0Found[0]) {
  gContCtx->flags &= 0xFE;
  query = taskOpen(4,0,8); taskRecvMsg(query);
  osContStartQuery(gOrderState+0x5A38);
  i=0; func_8007F73C(0,3);
  osContGetQuery((u8*)gContCtx+0xC);
  zero = 0;
  state=gContCtx;
  if (state->count>zero) {
   one=1; recOff=0; motorOff=0x18C;
   do {
    cont=(VRCont*)((u8*)state+i*4);
    if ((cont->status&4) && (cont->type&1) && osMotorInit(gOrderState+0x5A38,(u8*)state+motorOff,i)==0) {
     motor_pak_reset(i,0);
     rec=(QQ*)((u8*)gContCtx+recOff); rec->a=one;
    } else { rec=(QQ*)((u8*)gContCtx+recOff); rec->a=0; }
    *(volatile s32 *)&rec->b = 0;
    recOff+=0x18; i++; motorOff+=0x68;
    state=gContCtx;
   } while(i<state->count);
  }
  func_8007F634(query); gContCtx->flags |= 1;
 }
}
