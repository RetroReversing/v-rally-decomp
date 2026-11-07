f64 func_8009A430(u32 a,u32 b) {
 u32 hi,lo,sign; s32 exp; u32 words[2];
 hi=a; lo=b;
 if((a|b)==0) { words[0]=a; words[1]=b; return *(f64*)words; }
 sign=0;
 if(hi&0x80000000) { lo=(lo^0xFFFFFFFF)+1; hi=(hi^0xFFFFFFFF)+(lo==0); sign=0x80000000; }
 exp=0;
 if(hi&0xFFE00000) { do { lo=(lo>>1)|(hi<<31); hi>>=1; exp++; } while(hi&0xFFE00000); }
 else { while(!(hi&0x100000)) { lo=(hi<<31)|(lo>>1); hi>>=1; exp--; } }
 words[0]=(hi&0xFFFFF)|sign|((exp+0x433)<<20); words[1]=lo;
 return *(f64*)words;
}
