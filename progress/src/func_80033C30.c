/* Updates the two fade counters at obj->state (+0x174, +0x178) from the sum of the two
 * words at obj->src (+0x10, +0x14). A large sum raises the counter towards 250 and
 * subtracts it from the matching byte of out (+4, +5), floored at zero; a small sum
 * lets the counter decay by 1 down to 6. */
void func_80033C30(void *obj, void *out)
{
  s32 sum;
  s32 counter5;
  s32 counter4;
  s32 newVal4;
  s32 newVal5;
  void *src;
  void *state;

  src = *((void **) (((char *) obj) + 0x54));
  state = *((void **) (((char *) obj) + 0x60));
  counter5 = *((s32 *) (((char *) state) + 0x178));
  counter4 = *((s32 *) (((char *) state) + 0x174));
  sum = *((s32 *) (((char *) src) + 0x10)) + *((s32 *) (((char *) src) + 0x14));
  if (sum >= 0x5DD)
  {
    counter4 += (counter4 < 0xFA);
    newVal4 = *((u8 *) (((char *) out) + 4)) - counter4;
    *((u8 *) (((char *) out) + 4)) = (u8) (newVal4 & (~newVal4 >> 0x1F));
  }
  else
  {
    counter4 -= (counter4 >= 6);
  }
  if (sum < (-0x5DC))
  {
    counter5 += (counter5 < 0xFA);
    newVal5 = *((u8 *) (((char *) out) + 5)) - counter5;
    *((u8 *) (((char *) out) + 5)) = (u8) (newVal5 & (~newVal5 >> 0x1F));
  }
  else
  {
    counter5 -= (counter5 >= 6);
  }
  *((s32 *) (((char *) (*((void **) (((char *) obj) + 0x60)))) + 0x178)) = counter5;
  *((s32 *) (((char *) (*((void **) (((char *) obj) + 0x60)))) + 0x174)) = counter4;
}
