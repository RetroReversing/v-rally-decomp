#include "common.h"

void func_8003C698(void *arg0)
{
    u32 temp_v1;
    void *temp_v0;

    temp_v0 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
    if (temp_v0 != NULL)
    {
        temp_v1 = *(*((u32 **) (((char *) temp_v0) + 0x50)));
        if (temp_v1 < 2U)
        {
            if (temp_v1 == 0)
            {
                *((s16 *) (((char *) arg0) + 0x7A)) = 0;
            }
            else
            {
                *((s16 *) (((char *) arg0) + 0x7A)) = 1;
            }
        }
        else
        {
            *((s16 *) (((char *) arg0) + 0x7A)) = (s16) temp_v1;
        }
    }
}
