extern void * D_800B7334;
extern s32 D_800B7320;
extern s32 D_800B731C;
extern s32 D_800B0BA8;
extern s32 D_800B7300;
extern s32 D_800B7308;
typedef struct VRTransferArgs { s32 a,b,c,d,e; } VRTransferArgs;
extern VRTransferArgs D_800B0BAC;
s32 func_80081040(s32, s32, s32, s32, VRTransferArgs);
void *func_800817A0(s32, s32);
void func_80081C30(void);
void func_80081D50(s32);
extern u8 D_800AE850[];
typedef struct VRLoadState { s32 x0,x4,x8; u8 padC[0x10]; s32 x1C; u8 pad20[0x10]; u16 x30,x32; s32 x34,x38; u8 pad3C[0x24]; s32 x60; } VRLoadState;
extern VRLoadState D_800C3338;
#define FIELD(p,t,o) (*(t *)((u8 *)(p)+(o)))
s32 func_8008188C(s32 arg0, s32 arg1) {
    void *temp_v0;
    VRLoadState *temp_s0;
    temp_v0 = func_800817A0(D_800B7308,arg0);
    temp_s0 = &D_800C3338;
    func_80081040(D_800B7300+FIELD(temp_v0,s32,0x1C),temp_s0->x0,0x2000,D_800B0BA8,D_800B0BAC);
    temp_s0->x38=FIELD(temp_v0,s32,0x10);
    temp_s0->x34=FIELD(temp_v0,s32,0x14);
    temp_s0->x32=FIELD(temp_v0,u16,0x1A);
    temp_s0->x30=FIELD(temp_v0,u16,0x18);
    temp_s0->x4=FIELD(temp_v0,s32,0x28);
    temp_s0->x8=FIELD(temp_v0,s32,0x24);
    D_800B731C=FIELD(temp_v0,s32,0x14);
    FIELD(D_800B7334,s32,0)=FIELD(temp_v0,s32,0x20);
    FIELD(D_800B7334,s32,4)=FIELD(temp_v0,s32,0x14);
    D_800B7320=FIELD(temp_v0,s32,0x10);
    temp_s0->x1C=FIELD(temp_v0,s32,0x1C);
    func_80081D50(arg1);
    func_80081C30();
    return temp_s0->x60;
}
