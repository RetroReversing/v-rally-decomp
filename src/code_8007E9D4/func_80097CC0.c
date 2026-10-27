#include "common.h"

void *func_80097CC0(void *arg0, u8 *src, u32 n) {
    u8 *dst = (u8 *)arg0 + n;
    u32 count;
    src += n;
    if (((u32)(src-dst)&3) != 0) {
        while(n-- != 0) *--dst = *--src;
    } else if(n != 0) {
        if ((u32)dst & 1) { *--dst = *--src; n--; }
        if(n >= 2 && ((u32)dst & 2)) { src-=2; dst-=2; n-=2; *(u16 *)dst=*(u16 *)src; }
        count = n >> 2;
        while(count-- != 0) { src-=4; dst-=4; *(u32 *)dst=*(u32 *)src; }
        if(n & 2) {src-=2;dst-=2;*(u16 *)dst=*(u16 *)src;}
        if(n & 1) dst[-1]=src[-1];
    }
    return arg0;
}
