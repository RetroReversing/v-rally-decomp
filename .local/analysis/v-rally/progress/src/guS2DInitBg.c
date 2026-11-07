/* Same-name source lead: guS2DInitBg in puzzleleague64; header boundary BUILD_VERSION=7. Destination verification required. */
void	guS2DInitBg(uObjBg *bg)
{
  u16	tmemUse;
  u16	shift;

  u32	tsize;

  
   



  tmemUse = (bg->b.imageFmt == 2 ) ? 256 : 512;
  
   


  shift = 6 - bg->b.imageSiz;
  
   


  if (bg->b.imageLoad == 0x0033 ){
    bg->b.tmemW      = bg->b.imageW >> shift;
    bg->b.tmemH      = (tmemUse / bg->b.tmemW) << 2;
    bg->b.tmemSizeW  = bg->b.tmemW << 1;
    bg->b.tmemSize   = bg->b.tmemH * bg->b.tmemSizeW;
    bg->b.tmemLoadSH = (bg->b.tmemSize>>1) - 1;
    bg->b.tmemLoadTH = (((1<< 11 )-1)/( bg->b.tmemW )+1) ;
  } else {

    bg->b.tmemW      = (bg->b.frameW >> shift) + 3;
    bg->b.tmemH      = (tmemUse / bg->b.tmemW) << 2;
    bg->b.tmemSizeW  = (bg->b.imageW >> shift) * 2;
    tsize = bg->b.tmemH * bg->b.tmemSizeW;
    bg->b.tmemSize   = tsize >> 16;
    bg->b.tmemLoadSH = tsize & 0xffff;
    bg->b.tmemLoadTH = bg->b.tmemH - 1;








  }
}
