extern void record_put_glyphs(s32,s32,s32,s32);
extern u8 D_800A73E0[];
extern u8 gStreamState[];

/* Builds the six results rows from the table at gStreamState+28278. Each row's
 * packed 16-bit entry selects a name record; rows 0-2 and 3-5 are written to
 * two glyph blocks, with the three letters (5 bits each, +'A') and a score
 * taken from D_800A73E0 +27540 / +27544. */
void func_8006C780(void) {
    s32 slot; u32 idx; u32 code; u8 *src; u8 *tbl; s32 offset;
    tbl=gStreamState+28278; slot=0; idx=slot&255;
    do {
        idx=slot&255;
        code=*(u16 *)(tbl+idx*2+334);
        if(code!=0xFFFF) {
            src=gStreamState+28198+(code>>14)*14;
            if(idx<3) {
                record_put_glyphs(idx,25,0,0); offset=idx*16;
                gStreamState[14312+offset]=((*(u16*)src>>10)&31)+65;
                gStreamState[14313+offset]=((*(u16*)src>>5)&31)+65;
                gStreamState[14314+offset]=(src[1]&31)+65;
                {u8 flag=*(u8 *)((s32)tbl+idx+331); code=code&0x3fff; gStreamState[14318+offset]=1;
                gStreamState[14310+offset]=flag&15;}
                if(code&1)code=-code;
                code=*(s32 *)(D_800A73E0+27540)-code; *(s32 *)(gStreamState+14306+offset)=code;
                slot++; goto tail;
            } else {
                record_put_glyphs((slot-3)&255,26,0,0); offset=(idx-3)*16;
                gStreamState[14376+offset]=((*(u16*)src>>10)&31)+65;
                gStreamState[14377+offset]=((*(u16*)src>>5)&31)+65;
                gStreamState[14378+offset]=(src[1]&31)+65;
                {u8 flag=*(u8 *)((s32)tbl+idx+328); code=code&0x3fff; gStreamState[14382+offset]=1;
                gStreamState[14374+offset]=flag>>4;}
                if(code&1)code=-code;
                code=*(s32 *)(D_800A73E0+27544)-code; *(s32 *)(gStreamState+14370+offset)=code;
            }
        }
        slot++; tail: ;
    } while((u32)(slot&255)<6);
}
