void *func_80006008();
s32 func_80006014();
extern char D_8009C030[];
extern char D_8009C068[];
extern char D_8009C0A8[];
extern char D_8009C0E8[];

void func_80016910(s32 arg0, s32 arg1)
{
  s32 *temp;
  s32 *a1;
  s32 *v1;
  s32 cmd;

  temp = func_80006008();
  a1 = temp;
  cmd = 0xDE000000;
  temp[0] = cmd;
  temp[1] = (s32) D_8009C030;
  a1 += 2;
  if (arg1 == 1) goto case1;
  if (arg1 < 2) {
    if (arg1 == 0) goto case0;
    goto end;
  }
  if (arg1 == 2) goto case2;
  if (arg1 == 3) goto case3;
  goto end;
case0:
  v1 = a1;
  a1 += 2;
  temp = (s32 *) D_8009C068;
  goto store;
case1:
  v1 = a1;
  a1 += 2;
  temp = (s32 *) D_8009C0A8;
  goto store;
case2:
case3:
  v1 = a1;
  a1 += 2;
  temp = (s32 *) D_8009C0E8;
store:
  v1[0] = cmd;
  v1[1] = (s32) temp;
end:
  func_80006014(arg0, a1);
}
