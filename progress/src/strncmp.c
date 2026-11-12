/* strncmp: compares at most n bytes of s1 and s2. Uses a byte loop until both pointers
   are word-aligned, then compares whole words and falls back to bytes for the tail.
   Returns the difference of the first differing bytes, or 0. */
s32 strncmp(u8 *s1, u8 *s2, u32 n) {
 s32 diff;
 register u32 words;
 register u32 w1, w2;
 #ifdef PORT
 if (((uintptr_t)(s1 - s2) & 3) == 0) goto aligned;
#else
 if (((u32)(s1 - s2) & 3) == 0) goto aligned;
#endif
bytes:
 while (--n != (u32)-1) { w1 = *s1++; diff = w1 - *s2++; if ((diff != 0) | (w1 == 0)) return diff; }
 return 0;
aligned:
 #ifdef PORT
 while ((uintptr_t)s1 & 3) {
#else
 while ((u32)s1 & 3) {
#endif
 if (--n == (u32)-1) return 0; w1 = *s1++; diff = w1 - *s2++; if ((diff != 0) | (w1 == 0)) return diff; }
 words = n;
 words >>= 2;
 words -= 1;
 if (words != (u32)-1) do {
  w1 = *(u32 *)s1; w2 = *(u32 *)s2; s1 += 4; s2 += 4; diff = w1 - w2;
  if (diff) {
   if (!(w1 & 0xff000000)) diff = 0xff000000;
   else if (!(w1 & 0xff0000)) diff = 0xffff0000;
   else if (!(w1 & 0xff00)) diff = 0xffffff00;
   else return diff;
   return (w1 & diff) - (w2 & diff);
  }
  if (!(w1 << 24) || !(w1 & 0xff00) || !(w1 & 0xff0000) || !(w1 & 0xff000000)) return diff;
 } while (--words != -1);
 n &= 3;
 goto bytes;
}
