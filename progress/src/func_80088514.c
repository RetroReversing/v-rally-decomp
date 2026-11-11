/* Runs a volume ramp: each pass adds the step (0xCC) to the accumulator (0xD1),
 * carries whole 64-step units into the level at 0xB5 (rising or falling by
 * the direction flag at 0xD2, clamped to 0..0x7F), and stops once the time
 * counter at 0x8C reaches the end time at +8. */
void func_80088514(void *arg0)
{
    u32 accum;
    u32 carry;
    u32 level;
    do
    {
        accum = (*((u8 *) (((char *) arg0) + 0xD1))) + (*((u8 *) (((char *) arg0) + 0xCC)));
        *((u32 *) (((char *) arg0) + 0x8C)) += 0x100;
        if (accum < 0x40U)
        {
            *((u8 *) (((char *) arg0) + 0xD1)) = accum;
        }
        else
        {
            *((u8 *) (((char *) arg0) + 0xD1)) = accum & 0x3F;
            accum = accum >> 6;
            if ((*((u8 *) (((char *) arg0) + 0xD2))) == 0)
            {
                carry = (*((u8 *) (((char *) arg0) + 0xB5))) + accum;
                *((u8 *) (((char *) arg0) + 0xB5)) = carry;
                if (((carry & 0xFF)) >= 0x80U)
                {
                    *((u8 *) (((char *) arg0) + 0xB5)) = 0x7FU;
                    *((u8 *) (((char *) arg0) + 0xD2)) = 1U;
                }
            }
            else
            {
                level = (*((u8 *) (((char *) arg0) + 0xB5))) - accum;
                *((u8 *) (((char *) arg0) + 0xB5)) = level;
                level &= 0xFF;
                if ((level >= 0x80U) | (level == 0))
                {
                    *((u8 *) (((char *) arg0) + 0xB5)) = 0U;
                    *((u8 *) (((char *) arg0) + 0xD2)) = 0U;
                }
            }
        }
    }
    while (((*((u32 *) (((char *) arg0) + 0x8C)))) < ((u32) (*((u32 *) (((char *) arg0) + 8)))));
}
