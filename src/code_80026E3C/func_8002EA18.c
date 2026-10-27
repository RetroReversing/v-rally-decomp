#include "common.h"

s32 func_8002D2A0();
s32 func_8002EA18(s32 arg0)
{
 s32 temp_v0;
 temp_v0 = func_8002D2A0();
 if (temp_v0 == 0)
 {
 return 0;
 }
 if (temp_v0)
 {
 return temp_v0 + (arg0 - temp_v0 * temp_v0) / (temp_v0 * 2);
 }
 else
 {
 return temp_v0 + (arg0 - temp_v0 * temp_v0) / (temp_v0 * 2);
 }
}
