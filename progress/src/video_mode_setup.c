extern u8 D_800A2590[],gOrderState[],stream_state[];

typedef struct {s32 w0,w1,w2,w3;
} S16Bytes;

s32 func_8000E2F0(s32);
void osViBlack(s32);
void osViSetMode(void*);
void osViSetSpecialFeatures(s32);
void osViSetYScale(f32);

/* Sets up the video mode: finds the mode table entry (80 bytes each) for the value at config+24, copies its
 * five 16-byte words into the mode buffer at gOrderState+0x1298, then applies the mode and the display settings. */
void video_mode_setup(u8 *config){
s32 modeIndex,temp_a1;
u8 *base;
S16Bytes *src,*dst,*end;

base=D_800A2590;
modeIndex=func_8000E2F0(*(s32*)(config+24));
dst=(S16Bytes*)(gOrderState+0x1298);
src=(S16Bytes*)(base+modeIndex*80);
end=src+5;

do {
*dst=*src;
temp_a1=src->w3;
src++;
dst++;
}
while(src!=end);

osViSetMode(gOrderState+0x1298);
osViBlack(1);

stream_state[0x5BA6]=4;
osViSetYScale(1.0f);
osViSetSpecialFeatures(0x4A);

}
