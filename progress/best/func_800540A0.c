extern unsigned char D_800AE850[];
extern unsigned char D_800C02AE[];
s32 func_80098180(s32, void *);

#define RUN(cnt, base) do { \
  u32 oi=0; unsigned char *q=(unsigned char *)(base); \
  if (*(u16 *)(D_800C02AE+(cnt))) do { \
    u32 ri=0; u16 n=*(u16 *)(q+0x14); \
    if (n) do { \
      u32 off=(ri&255)<<6; unsigned char *e=q+off; u32 k=0; \
      if (e[0x38]==1) { \
        do { u32 ix=k&255; if (func_80098180(*(s32 *)(D_800C02AE+0x32F2)+(((ix*5)<<3)+0x44),q+(off+0x2c)+6)==0 || ix>=4) break; k++; } while(1); \
        { u32 ix=k&255, z=ix*5; D_800AE850[0x2530+z]+=4; D_800AE850[0x2544]+=4; } \
      } \
      ri++; \
    } while ((ri&255)<*(u16 *)(q+0x14)); \
    oi++; \
  } while ((oi&255)<*(u16 *)(D_800C02AE+(cnt))); \
} while(0)

void func_800540A0(void) {
  RUN(0x10372, *(unsigned char **)(D_800C02AE+0x1038A));
  RUN(0x10374, *(unsigned char **)(D_800C02AE+0x1038E));
  RUN(0x10376, *(unsigned char **)(D_800C02AE+0x10392));
  RUN(0x10378, *(unsigned char **)(D_800C02AE+0x10396));
}
