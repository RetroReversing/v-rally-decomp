#include "common.h"

extern short D_8009E2AC[];
short func_8002E828(short arg0) { return D_8009E2AC[(0x100 - arg0) & 0x3FF]; }
