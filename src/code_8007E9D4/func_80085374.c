#include "common.h"

s32 func_80084BF0(s32);extern s32 D_800A1B70;
s32 func_80085374(s32 arg0){s32 idx,buttons,result;result=0;idx=arg0&255;buttons=func_80084BF0(idx);
if(buttons&1){s32 base=D_800A1B70;base+=idx*56;result=*(s32*)(base+172);}
if(buttons&2){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+176);}
if(buttons&4){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+180);}
if(buttons&8){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+184);}
if(buttons&16){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+188);}
if(buttons&32){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+192);}
if(buttons&256){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+196);}
if(buttons&512){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+200);}
if(buttons&1024){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+204);}
if(buttons&2048){s32 base=D_800A1B70;base+=idx*56;result|=*(s32*)(base+208);}
if(buttons&4096){s32 base=D_800A1B70;base+=(arg0&255)*56;result|=*(s32*)(base+212);}
if(buttons&8192){s32 base=D_800A1B70;base+=(arg0&255)*56;result|=*(s32*)(base+216);}
if(buttons&16384){s32 base=D_800A1B70;base+=(arg0&255)*56;result|=*(s32*)(base+220);}
if(buttons&32768){s32 base=D_800A1B70;base+=(arg0&255)*56;result|=*(s32*)(base+224);}
return result;}
