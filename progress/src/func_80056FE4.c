extern int D_800B55F0; void func_80056F8C(int a, int b);
/* Stores the first word of hdr in D_800B55F0, then runs func_80056F8C over entries 0 to the u16 count at +4, minus one. */
void func_80056FE4(int *hdr) { D_800B55F0 = hdr[0]; func_80056F8C(0, ((unsigned short *)hdr)[2] - 1); }
