typedef struct { s16 unk0; u8 unk2,unk3; } S_func_8008FA20_arg1;
extern u8 gOrderState[],stream_state[];
extern s32 __osSiRawStartDma(); extern s32 osRecvMesg(s32,void*,s32);
/* Runs a joybus status request through the SI interface: waits for the reply on mq, decodes the
 * reply into status and returns the reply's error code (0 when the device answered). */
s32 pakQueryStatus(s32 mq,S_func_8008FA20_arg1 *status) {
u8 pkt[8]; u8 *p; s32 i,ret; u8 *resp; s32 *q;
for(i=15,q=(s32*)(gOrderState+0x869c);i>=0;i--) *q--=0;
q=(s32*)(gOrderState+0x869c); *q=1;
p=(u8*)q-0x3c; for(i=3;i>=0;i--) *p++=0;
pkt[0]=255;pkt[1]=1;pkt[2]=3;pkt[3]=0;pkt[4]=255;pkt[5]=255;pkt[6]=255;pkt[7]=255;
__builtin_memcpy(p,pkt,8); resp=gOrderState+0x8660;p[8]=254;
__osSiRawStartDma(1,resp); osRecvMesg(mq,0,1); stream_state[0x3272]=254;
ret=__osSiRawStartDma(0,resp);osRecvMesg(mq,0,1);
if(ret==0){p=resp;for(i=3;i>=0;i--)*p++=0;__builtin_memcpy(pkt,p,8);
status->unk3=(pkt[2]&0xc0)>>4;status->unk0=pkt[4]|(pkt[5]<<8);status->unk2=pkt[6];return status->unk3 ? status->unk3:0;}
return ret;
}
