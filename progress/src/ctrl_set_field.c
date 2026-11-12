typedef struct {s32 f[14];} Controls;
typedef struct {s32 f[5];} Small;
typedef union {struct {u8 pad[0xAC];Controls ctrl[4];} big; struct {u8 pad[0x68];Small ctrl[4];} small;} Sys;
extern Sys *gControllerInputContext;

/* Stores value into one word of a player's control record. The bit argument
 * (a button/field mask) picks the word index; masks 0x20000 and 0x10000 select
 * the two words of the small record layout. */
void ctrl_set_field(u8 player, u32 bit, s32 value){
switch(bit){
case 1: gControllerInputContext->big.ctrl[player].f[0]=value;break;
case 2: gControllerInputContext->big.ctrl[player].f[1]=value;break;
case 4: gControllerInputContext->big.ctrl[player].f[2]=value;break;
case 8: gControllerInputContext->big.ctrl[player].f[3]=value;break;
case 16: gControllerInputContext->big.ctrl[player].f[4]=value;break;
case 32: gControllerInputContext->big.ctrl[player].f[5]=value;break;
case 256: gControllerInputContext->big.ctrl[player].f[6]=value;break;
case 512: gControllerInputContext->big.ctrl[player].f[7]=value;break;
case 1024: gControllerInputContext->big.ctrl[player].f[8]=value;break;
case 2048: gControllerInputContext->big.ctrl[player].f[9]=value;break;
case 4096: gControllerInputContext->big.ctrl[player].f[10]=value;break;
case 8192: gControllerInputContext->big.ctrl[player].f[11]=value;break;
case 16384: gControllerInputContext->big.ctrl[player].f[12]=value;break;
case 32768: gControllerInputContext->big.ctrl[player].f[13]=value;break;
case 0x20000: gControllerInputContext->small.ctrl[player].f[0]=value;break;
case 0x10000: gControllerInputContext->small.ctrl[player].f[1]=value;break;
}}
