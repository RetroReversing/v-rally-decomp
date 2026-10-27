#include "common.h"

extern u8 *D_800A1468;void func_8007A688();void func_8007A6D0();void func_8005946C(s32,u8);
s32 func_8007AC68(s32 a){u8 v;v=D_800A1468[0x239];if(!v)v=(D_800A1468+D_800A1468[0x238])[0x23d];D_800A1468[0x239]=--v;{u8 *p=D_800A1468; p[0x2bd]=(v-v)+1;}func_8007A688();func_8007A6D0();func_8005946C(a,D_800A1468[0x239]);return 0;}
