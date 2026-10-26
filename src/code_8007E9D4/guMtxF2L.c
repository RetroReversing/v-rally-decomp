#include "common.h"

/* identical to guMtxF2L in V-RALLY (matched), with its names changed by decompdecomp */
 











 














 











 







 








 





















 





 










 














 












 













 















typedef volatile unsigned long long vu64;    

typedef volatile signed char        vs8;     
typedef volatile short              vs16;    

typedef volatile long long          vs64;    



typedef unsigned int    size_t;





















 











 





 
















































 











 





















 





 




 





























 
















 












 





 















 



 








 







 



 



 









 











 


























 


















 


 








 







































 


 






















 











 
































 



 



 



 




 





 










 











 







 

















 



 





 



 




 



 




 




 




 



 









 





 




 



 




























































































































 









































































































 









 






 



 




 
































 


typedef struct {
	short		ob[3];	 
	unsigned short	flag;
	short		tc[2];	 
	unsigned char	cn[4];	 
} Vtx_t;

 


typedef struct {
	short		ob[3];	 
	unsigned short	flag;
	short		tc[2];	 
	signed char	n[3];	 
	unsigned char   a;       
} Vtx_tn;

typedef union {
    Vtx_t		v;   
    Vtx_tn              n;   
    long long int	force_structure_alignment;
} Vtx;

 



typedef struct {
  void *SourceImagePointer;
  void *TlutPointer;
  short Stride;
  short SubImageWidth;
  short SubImageHeight;
  char  SourceImageType;
  char  SourceImageBitSize;
  short SourceImageOffsetS;
  short SourceImageOffsetT;
   

   
  char dummy[4];

} uSprite_t;

typedef union {
  uSprite_t  s;

   
  long long int         force_structure_allignment[3];
} uSprite;

 


typedef struct {
	unsigned char	flag;
	unsigned char	v[3];
} Tri;

 




typedef long	Mtx_t[4][4];

typedef union {
    Mtx_t		m;
    long long int	force_structure_alignment;
} Mtx;

 



 


















 










typedef struct {
	short	vscale[4];   
	short	vtrans[4];   
	 
} Vp_t;

typedef union {
    Vp_t		vp;
    long long int	force_structure_alignment;
} Vp;

 


























 


















 































































 









typedef struct {
  unsigned char	col[3];		 
  char 		pad1;
  unsigned char	colc[3];	 
  char 		pad2;
  signed char	dir[3];		 
  char 		pad3;
} Light_t;

typedef struct {
  unsigned char	col[3];		 
  char 		pad1;
  unsigned char	colc[3];	 
  char 		pad2;
} Ambient_t;

typedef struct {
  int		x1,y1,x2,y2;	 
} Hilite_t;

typedef union {
    Light_t	l;
    long long int	force_structure_alignment[2];
} Light;

typedef union {
    Ambient_t	l;
    long long int	force_structure_alignment[1];
} Ambient;

typedef struct {
    Ambient	a;
    Light	l[7];
} Lightsn;

typedef struct {
    Ambient	a;
    Light	l[1];
} Lights0;

typedef struct {
    Ambient	a;
    Light	l[1];
} Lights1;

typedef struct {
    Ambient	a;
    Light	l[2];
} Lights2;

typedef struct {
    Ambient	a;
    Light	l[3];
} Lights3;

typedef struct {
    Ambient	a;
    Light	l[4];
} Lights4;

typedef struct {
    Ambient	a;
    Light	l[5];
} Lights5;

typedef struct {
    Ambient	a;
    Light	l[6];
} Lights6;

typedef struct {
    Ambient	a;
    Light	l[7];
} Lights7;

typedef struct {
    Light	l[2];
} LookAt;

typedef union {
    Hilite_t	h;
    long int	force_structure_alignment[4];
} Hilite;

















 


typedef struct {
	int		cmd:8;
	unsigned int	par:8;
	unsigned int	len:16;
	unsigned int	addr;
} Gdma;

 


typedef struct {
		int		cmd:8;
		int		pad:24;
		Tri		tri;
} Gtri;

typedef struct {
		int		cmd:8;
		int		pad1:24;
		int             pad2:24;
		unsigned char	param:8;
} Gpopmtx;

 








typedef struct {
		int		cmd:8;
		int		pad0:8;
		int		mw_index:8;
		int		number:8;
		int		pad1:8;
		int		base:24;
} Gsegment;

typedef struct {
		int		cmd:8;
		int		pad0:8;
		int		sft:8;
		int		len:8;
		unsigned int	data:32;
} GsetothermodeL;

typedef struct {
		int		cmd:8;
		int		pad0:8;
		int		sft:8;
		int		len:8;
		unsigned int	data:32;
} GsetothermodeH;

typedef struct {
		unsigned char	cmd;
		unsigned char	lodscale;
		unsigned char	tile;
		unsigned char	on;
		unsigned short	s;
		unsigned short	t;
} Gtexture;

typedef struct {
		int		cmd:8;
		int		pad:24;
		Tri		line;
} Gline3D;

typedef struct {
		int		cmd:8;
		int		pad1:24;
		short int	pad2;
		short int       scale;
} Gperspnorm;


 


typedef struct {
                int             cmd:8;
                unsigned int    fmt:3;
                unsigned int    siz:2;
                unsigned int    pad:7;
                unsigned int    wd:12;	 
                unsigned int    dram;	 
} Gsetimg;

typedef struct {
		int		cmd:8;
		unsigned int	muxs0:24;
		unsigned int	muxs1:32;
} Gsetcombine;

typedef struct {
		int		cmd:8;
		unsigned char	pad;
		unsigned char	prim_min_level;
		unsigned char	prim_level;
		unsigned long	color;
} Gsetcolor;

typedef struct {
		int		cmd:8;
		int		x0:10;
		int		x0frac:2;
		int		y0:10;
		int		y0frac:2;
		unsigned int	pad:8;
		int		x1:10;
		int		x1frac:2;
		int		y1:10;
		int		y1frac:2;
} Gfillrect;

typedef struct {
		int		cmd:8;
		unsigned int	fmt:3;
		unsigned int	siz:2;
		unsigned int	pad0:1;
		unsigned int	line:9;
		unsigned int	tmem:9;
		unsigned int	pad1:5;
		unsigned int	tile:3;
		unsigned int	palette:4;
		unsigned int	ct:1;
		unsigned int	mt:1;
		unsigned int	maskt:4;
		unsigned int	shiftt:4;
		unsigned int	cs:1;
		unsigned int	ms:1;
		unsigned int	masks:4;
		unsigned int	shifts:4;
} Gsettile;

typedef struct {
		int		cmd:8;
		unsigned int	sl:12;
		unsigned int	tl:12;
		int		pad:5;
		unsigned int	tile:3;
		unsigned int	sh:12;
		unsigned int	th:12;
} Gloadtile;

typedef Gloadtile Gloadblock;

typedef Gloadtile Gsettilesize;

typedef Gloadtile Gloadtlut;

typedef struct {
		unsigned int	cmd:8;	 
		unsigned int	xl:12;	 
		unsigned int	yl:12;	 
		unsigned int	pad1:5;	 
		unsigned int	tile:3;	 
		unsigned int	xh:12;	 
		unsigned int	yh:12;	 
		unsigned int	s:16;	 
		unsigned int	t:16;	 
		unsigned int	dsdx:16; 
		unsigned int	dtdy:16; 
} Gtexrect;



 


typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
} TexRect;

 


typedef struct {
	unsigned int w0;
	unsigned int w1;
} Gwords;

 



typedef union {
	Gwords		words;
	Gdma		dma;
	Gtri		tri;
	Gline3D		line;
	Gpopmtx		popmtx;
	Gsegment	segment;
	GsetothermodeH	setothermodeH;
	GsetothermodeL	setothermodeL;
	Gtexture	texture;
	Gperspnorm	perspnorm;
	Gsetimg		setimg;
	Gsetcombine	setcombine;
	Gsetcolor	setcolor;
	Gfillrect	fillrect;	 
	Gsettile	settile;
	Gloadtile	loadtile;	 
	Gsettilesize	settilesize;
	Gloadtlut	loadtlut;
        long long int	force_structure_alignment;
} Gfx;

 



 






















 



























 



























 










 














 





 





 


 








 








 


















 














 






 











 









 












 
























 










 


















 













 















 












 







 




























 

















 





















 




 



































 







































 























 


 






 



















 



































 































 



 



















 









 
































 





















 
 



 








 




 




 






 
 




 





 





 





 













 
 



 




 












 






 






 










 








 







 







 





 










 









 







































 




 






















 
















 





























 








 











 







 








 


















 
















 




 



typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	gain:16;
	unsigned int	addr;
} Aadpcm;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	gain:16;
	unsigned int	addr;
} Apolef;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	pad1:16;
	unsigned int	addr;
} Aenvelope;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	pad1:8;
	unsigned int	dmem:16;
	unsigned int	pad2:16;
	unsigned int	count:16;
} Aclearbuff;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	pad1:8;
	unsigned int	pad2:16;
	unsigned int	inL:16;
        unsigned int    inR:16;
} Ainterleave;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	pad1:24;
	unsigned int	addr;
} Aloadbuff;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	pad1:16;
	unsigned int	addr;
} Aenvmixer;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	gain:16;
	unsigned int	dmemi:16;
	unsigned int	dmemo:16;
} Amixer;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	dmem2:16;
	unsigned int	addr;
} Apan;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	pitch:16;
	unsigned int	addr;
} Aresample;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	pad1:16;
	unsigned int	addr;
} Areverb;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	pad1:24;
	unsigned int	addr;
} Asavebuff;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	pad1:24;
	unsigned int    pad2:2;
	unsigned int    number:4;
	unsigned int	base:24;
} Asegment;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	dmemin:16;
	unsigned int	dmemout:16;
	unsigned int	count:16;
} Asetbuff;

typedef struct {
  	unsigned int	cmd:8;
	unsigned int	flags:8;
	unsigned int	vol:16;
	unsigned int	voltgt:16;
	unsigned int	volrate:16;
} Asetvol;

typedef struct {
    unsigned int        cmd:8;
    unsigned int        pad1:8;
    unsigned int        dmemin:16;
    unsigned int        dmemout:16;
    unsigned int        count:16;
} Admemmove;

typedef struct {
    unsigned int        cmd:8;
    unsigned int        pad1:8;
    unsigned int        count:16;
    unsigned int        addr;
} Aloadadpcm;

typedef struct {
    unsigned int        cmd:8;
    unsigned int        pad1:8;
    unsigned int        pad2:16;
    unsigned int        addr;
} Asetloop;

 



typedef struct {
	unsigned int w0;
	unsigned int w1;
} Awords;

typedef union {
	Awords		words;
	Aadpcm		adpcm;
        Apolef          polef;
	Aclearbuff	clearbuff;
	Aenvelope	envelope;
        Ainterleave     interleave;
	Aloadbuff	loadbuff;
        Aenvmixer       envmixer;
	Aresample	resample;
	Areverb		reverb;
	Asavebuff	savebuff;
	Asegment	segment;
	Asetbuff	setbuff;
	Asetvol		setvol;
        Admemmove       dmemmove;
        Aloadadpcm	loadadpcm;
        Amixer		mixer;
        Asetloop        setloop;
        long long int	force_union_align;	 
} Acmd;

 




typedef short ADPCM_STATE[16 ];

 


typedef short POLEF_STATE[4];

 


typedef short RESAMPLE_STATE[16];

 





 


typedef short ENVMIX_STATE[40];

 











































 











 

















 











 









 











 
















 





 



































typedef struct {
	u32	type;
	u32	flags;

	u64	*ucode_boot;
	u32	ucode_boot_size;

	u64	*ucode;
	u32	ucode_size;

	u64	*ucode_data;
	u32	ucode_data_size;

	u64	*dram_stack;
	u32	dram_stack_size;

	u64	*output_buff;
	u64	*output_buff_size;

	u64	*data_ptr;
	u32	data_size;

	u64	*yield_data_ptr;
	u32	yield_data_size;

} OSTask_t;

typedef union {
    OSTask_t		t;
    long long int	force_structure_alignment;
} OSTask;

typedef u32 OSYieldResult;





 











 











 









 





 





 






 





 


extern void		osSpTaskLoad(OSTask *tp);
extern void		osSpTaskStartGo(OSTask *tp);

extern void		func_800939D0(void);
extern OSYieldResult	osSpTaskYielded(OSTask *tp);








 









































 


typedef struct {
	unsigned char   *base;
	int             fmt, siz;
	int             xsize, ysize;
	int             lsize;
	 
	int             addr;
	int             w, h;
	int             s, t;
} Image;

typedef struct {
	float	col[3];
	float	pos[3];
	float	a1, a2;		 
} PositionalLight;


 



extern int guLoadTextureBlockMipMap(Gfx **glist, unsigned char *tbuf, Image *im,
		unsigned char startTile, unsigned char pal, unsigned char cms,
		unsigned char cmt, unsigned char masks, unsigned char maskt,
		unsigned char shifts, unsigned char shiftt, unsigned char cfs,
		unsigned char cft);

extern int 	guGetDPLoadTextureTileSz (int ult, int lrt);
extern void 	guDPLoadTextureTile (Gfx *glistp, void *timg,
			int texl_fmt, int texl_size,
			int img_width, int img_height,
			int uls, int ult, int lrs, int lrt,
			int palette,
			int cms, int cmt,
			int masks, int maskt,
			int shifts, int shiftt);


 






extern void guMtxIdent(Mtx *m);
extern void guMtxIdentF(float mf[4][4]);
extern void guOrtho(Mtx *m, float l, float r, float b, float t,
		    float n, float f, float scale);
extern void guOrthoF(float mf[4][4], float l, float r, float b, float t,
		     float n, float f, float scale);
extern void guFrustum(Mtx *m, float l, float r, float b, float t,
		      float n, float f, float scale);
extern void guFrustumF(float mf[4][4], float l, float r, float b, float t,
		       float n, float f, float scale);
extern void guPerspective(Mtx *m, u16 *perspNorm, float fovy,
			  float aspect, float near, float far, float scale);
extern void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy,
			   float aspect, float near, float far, float scale);
extern void guLookAt(Mtx *m,
			float xEye, float yEye, float zEye,
			float xAt,  float yAt,  float zAt,
			float xUp,  float yUp,  float zUp);
extern void guLookAtF(float mf[4][4], float xEye, float yEye, float zEye,
		      float xAt,  float yAt,  float zAt,
		      float xUp,  float yUp,  float zUp);
extern void guLookAtReflect(Mtx *m, LookAt *l,
			float xEye, float yEye, float zEye,
			float xAt,  float yAt,  float zAt,
			float xUp,  float yUp,  float zUp);
extern void guLookAtReflectF(float mf[4][4], LookAt *l,
		      float xEye, float yEye, float zEye,
		      float xAt,  float yAt,  float zAt,
		      float xUp,  float yUp,  float zUp);
extern void guLookAtHilite(Mtx *m, LookAt *l, Hilite *h,
                float xEye, float yEye, float zEye,
                float xAt,  float yAt,  float zAt,
                float xUp,  float yUp,  float zUp,
                float xl1,  float yl1,  float zl1,
                float xl2,  float yl2,  float zl2,
		int   twidth, int theight);
extern void guLookAtHiliteF(float mf[4][4], LookAt *l, Hilite *h,
		float xEye, float yEye, float zEye,
		float xAt,  float yAt,  float zAt,
		float xUp,  float yUp,  float zUp,
		float xl1,  float yl1,  float zl1,
		float xl2,  float yl2,  float zl2,
		int twidth, int theight);
extern void guLookAtStereo(Mtx *m,
			float xEye, float yEye, float zEye,
			float xAt,  float yAt,  float zAt,
			float xUp,  float yUp,  float zUp,
			float eyedist);
extern void guLookAtStereoF(float mf[4][4],
		      	float xEye, float yEye, float zEye,
		      	float xAt,  float yAt,  float zAt,
		      	float xUp,  float yUp,  float zUp,
			float eyedist);
extern void guRotate(Mtx *m, float a, float x, float y, float z);
extern void guRotateF(float mf[4][4], float a, float x, float y, float z);
extern void guRotateRPY(Mtx *m, float r, float p, float y);
extern void guRotateRPYF(float mf[4][4], float r, float p, float h);
extern void guAlign(Mtx *m, float a, float x, float y, float z);
extern void guAlignF(float mf[4][4], float a, float x, float y, float z);
extern void guScale(Mtx *m, float x, float y, float z);
extern void guScaleF(float mf[4][4], float x, float y, float z);
extern void guTranslate(Mtx *m, float x, float y, float z);
extern void guTranslateF(float mf[4][4], float x, float y, float z);
extern void guPosition(Mtx *m, float r, float p, float h, float s,
		       float x, float y, float z);
extern void guPositionF(float mf[4][4], float r, float p, float h, float s,
			float x, float y, float z);
extern void guMtxF2L(float mf[4][4], Mtx *m);
extern void guMtxL2F(float mf[4][4], Mtx *m);
extern void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
extern void guMtxCatL(Mtx *m, Mtx *n, Mtx *res);
extern void guMtxXFMF(float mf[4][4], float x, float y, float z,
		      float *ox, float *oy, float *oz);
extern void guMtxXFML(Mtx *m, float x, float y, float z,
		      float *ox, float *oy, float *oz);

 
extern void guNormalize(float *x, float *y, float *z);

 
void guPosLight(PositionalLight *pl, Light *l,
                float xOb, float yOb, float zOb);
void guPosLightHilite(PositionalLight *pl1, PositionalLight *pl2,
                Light *l1, Light *l2,
                LookAt *l, Hilite *h,
                float xEye, float yEye, float zEye,
                float xOb,  float yOb,  float zOb,
                float xUp,  float yUp,  float zUp,
                int twidth, int theight);
extern int guRandom(void);

 


extern float sinf(float angle);
extern float cosf(float angle);
extern signed short sins (unsigned short angle);
extern signed short coss (unsigned short angle);
extern float sqrtf(float value);


 


 




                                            
                                            

extern void guParseRdpDL(u64 *rdp_dl, u64 nbytes, u8 flags);
extern void guParseString(char *StringPointer, u64 nbytes);

 



 

 



extern void
guBlinkRdpDL(u64 *rdp_dl_in, u64 nbytes_in,
             u64 *rdp_dl_out, u64 *nbytes_out,
             u32 x, u32 y, u32 radius,
             u8  red, u8 green, u8 blue,
             u8 flags);

 






 



extern void guParseGbiDL(u64 *gbi_dl, u32 nbytes, u8 flags);
extern void guDumpGbiDL(OSTask *tp,u8 flags);








typedef struct {
    int    dataSize;
    int    dlType;
    int    flags;
    u32    paddr;
} guDLPrintCB;

void guSprite2DInit(uSprite *SpritePointer,
		    void *SourceImagePointer,
		    void *TlutPointer,
		    int Stride,
		    int SubImageWidth,
		    int SubImageHeight,
		    int SourceImageType,
		    int SourceImageBitSize,
		    int SourceImageOffsetS,
		    int SourceImageOffsetT);




typedef union
{
	struct
	{
		unsigned int hi;
		unsigned int lo;
	} word;

	double	d;
} du;

typedef union
{
	unsigned int	i;
	float		f;
} fu;



typedef	float	Matrix[4][4];






extern float	__libm_qnan_f;



void guMtxL2F(float mf[4][4], Mtx *m);
void guMtxIdentF(float mf[4][4]);
void guMtxIdent(Mtx *m);
void guMtxF2L(float mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1,e2;
	int	*ai,*af;


	ai=(int *) &m->m[0][0];
	af=(int *) &m->m[2][0];

	for (i=0; i<4; i++)
	for (j=0; j<2; j++) {
		e1= (long)(( mf[i][j*2] ) * (float)0x00010000) ;
		e2= (long)(( mf[i][j*2+1] ) * (float)0x00010000) ;
		*(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff);
		*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
	}
}
