#include "common.h"

s32 func_80034FF0();
void func_8002FA8C(void *arg0, void *arg1, s32 arg2)
{
  s32 var_s3;
  s32 temp_s0;
  void *var_s0;
  void *var_s1;
  void *var_s2;
  s32 temp_v0;
  var_s1 = arg0;
  var_s2 = arg1;
  if (var_s2 != NULL)
  {
    var_s3 = (arg2 & 0xFF) * 4;
    do
    {
      temp_s0 = (s32) *(*((void ***) (((char *) var_s2) + 0x38)));
      temp_v0 = func_80034FF0(arg0 + 0x98, 0);
      var_s0 = (void *) (var_s3 + temp_s0);
      *((s32 *) (((char *) var_s0) + 0x1C)) = temp_v0;
      *((s16 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 0)) = (s16) (*((s32 *) (((char *) arg0) + 0x128)));
      *((s16 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 2)) = (s16) (*((s32 *) (((char *) arg0) + 0x174)));
      *((s8 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 4)) = (s8) (*((s32 *) (((char *) arg0) + 0x1C0)));
      *((s8 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 5)) = (s8) (*((s32 *) (((char *) arg0) + 0x20C)));
      *((s8 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 6)) = (s8) (*((s32 *) (((char *) arg0) + 0x258)));
      *((s16 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 8)) = (s16) (*((s32 *) (((char *) arg0) + 0x2A4)));
      *((s16 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 0xA)) = (s16) (*((s32 *) (((char *) arg0) + 0x2F0)));
      *((s16 *) (((char *) (*((void **) (((char *) var_s0) + 0x38)))) + 0xC)) = (s16) (*((s32 *) (((char *) arg0) + 0x33C)));
      var_s2 = *((void **) (((char *) var_s2) + 4));
    }
    while (var_s2 != NULL);
  }
}
