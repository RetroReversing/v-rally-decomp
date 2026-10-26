#include "common.h"

int alSaveParam(int *a, int b, int c) { switch (b) { case 1: a[0] = c; break; case 6: a[5] = c; break; } return 0; }
