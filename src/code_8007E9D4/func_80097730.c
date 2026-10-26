#include "common.h"

void alCopy(unsigned char *arg0, unsigned char *arg1, int arg2) { int i; for (i = 0; i < arg2; i++) { *arg1++ = *arg0++; } }
