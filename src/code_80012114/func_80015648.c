#include "snapshot29_0433f7af8f6d.h"

/* r180b */
extern f32 D_8009CEC0[];
void func_80015508();
void func_80015648(void *arg0, void *arg1)
{
char __repair_stack_padding[8];
  char *var_v1;
  s32 var_a0;
  f32 *var_a1;
  char *var_s0;
  s32 temp_v0;
  int new_var;
  func_80015508();
  var_s0 = ((char *) arg1) + (((*((u16 *) (((char *) arg1) + 0x22))) * 0x38) + 0x3C);
  *((void **) (var_s0 + 0x18)) = arg0;
  var_v1 = *((char **) arg0);
  var_a0 = 0;
  new_var = 0;
  temp_v0 = *((u16 *) (((char *) arg0) + 4));
  if (temp_v0 <= 0)
  {
  }
  else
  {
    var_a1 = D_8009CEC0;
loop_top:
    *((s32 *) (var_v1 + 0xC)) = (s32) (((f32) (*((s32 *) (var_v1 + 0xC)))) * var_a1[0]);
    *((s32 *) (var_v1 + 0x10)) = (s32) (((f32) (*((s32 *) (var_v1 + 0x10)))) * var_a1[1]);
    *((s32 *) (var_v1 + 0x14)) = (s32) (((f32) (*((s32 *) (var_v1 + 0x14)))) * var_a1[2]);
    *((s32 *) (var_v1 + 0x18)) = (s32) (((f32) (*((s32 *) (var_v1 + 0x18)))) * var_a1[0]);
    *((s32 *) (var_v1 + 0x1C)) = (s32) (((f32) (*((s32 *) (var_v1 + 0x1C)))) * var_a1[1]);
    *((s32 *) (var_v1 + 0x20)) = (s32) (((f32) (*((s32 *) (var_v1 + 0x20)))) * var_a1[2]);
    temp_v0 = *((u16 *) (((char *) arg0) + 4));
    var_a0 += 1;
    if (var_a0 >= temp_v0) {
      var_v1 += 0x34;
      goto loop_done;
    }
    var_v1 += 0x34;
    goto loop_top;
loop_done:;
  }
}
