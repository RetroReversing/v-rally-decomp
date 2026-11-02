typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;
typedef short               s16;
typedef long                s32;
typedef	struct	{
  u16   imageX;		  
  u16	imageW;		 
  s16	frameX;		 
  u16	frameW;		 

  u16   imageY; 	  
  u16	imageH;		 
  s16	frameY;		 
  u16	frameH;		 

  u64  *imagePtr;	 
  u16	imageLoad;	 
  u8	imageFmt;	 
  u8	imageSiz;	 
  u16   imagePal; 	 
  u16	imageFlip;	 

   
  u16	tmemW;		 


  u16	tmemH;		 


  u16	tmemLoadSH;	 


  u16	tmemLoadTH;	 


  u16	tmemSizeW;	 


  u16	tmemSize;	 

} uObjBg_t;
typedef	struct	{
  u16   imageX;		  
  u16	imageW;		 
  s16	frameX;		 
  u16	frameW;		 

  u16   imageY; 	  
  u16	imageH;		 
  s16	frameY;		 
  u16	frameH;		 

  u64  *imagePtr;	 
  u16	imageLoad;	 
  u8	imageFmt;	 
  u8	imageSiz;	 
  u16   imagePal; 	 
  u16	imageFlip;	 

  u16	scaleW;		 
  u16	scaleH;		 
  s32	imageYorig;	 
  
  u8	padding[4];
  
} uObjScaleBg_t;
typedef union {
  uObjBg_t        b;
  uObjScaleBg_t   s;
  long long int   force_structure_alignment;
} uObjBg;