typedef unsigned char			u8;
typedef unsigned long			u32;
typedef struct
{
      u32 ramarray[15];
      u32 pifstatus;
} OSPifRam;
typedef struct
{
      u8 dummy;
      u8 txsize;
      u8 rxsize;
      u8 cmd;
      u8 typeh;
      u8 typel;
      u8 status;
      u8 dummy1;
} __OSContRequesFormat;
extern u8 __osContLastCmd;
extern OSPifRam __osPfsPifRam;
extern u8 __osMaxControllers;
OSPifRam __osPfsPifRam __attribute__((aligned( 16 ))) ;