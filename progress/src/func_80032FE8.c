/* Walks a ring of linked objects (next at +0x5C). For each object with a partner at +0x58, computes a weighted average of the two endpoints' bytes and writes it back to both. */
void func_80032FE8(void *arg0)
{
    s32 sum;
    s32 wa;
    s32 wb;
    char *cur;
    char *head;
    s32 ta;
    s32 tb;
    s32 pa;
    s32 pb_ign;
    char *pa_obj;
    char *partner;
    s32 ptag;
    char *pt;

    cur = arg0;
    head = arg0;
    do
    {
        partner = *((char **) (cur + 0x58));
        if (partner != NULL)
        {
            pa_obj = *((char **) (cur + 0x78));
            partner = *((char **) (partner + 0x78));
            ta = *((u8 *) (pa_obj + 0xF));
            tb = *((u8 *) (pa_obj + 0xE));
            pa = *((u8 *) (pa_obj + 0x14));
            ptag = *((u8 *) (partner + 0x17));
            wa = 1;
            if (ta < tb)
            {
                wa = *((s16 *) (pa_obj + 4)) + 1;
            }
            else if (tb != 0)
            {
                wa = *((s16 *) (pa_obj + 6)) + 1;
            }
            pa_obj = *((char **) (*((char **) (cur + 0x58)) + 0x78));
            ta = *((u8 *) (pa_obj + 0xF));
            tb = *((u8 *) (pa_obj + 0xE));
            wb = 1;
            if (ta < tb)
            {
                wb = *((s16 *) (pa_obj + 6)) + 1;
            }
            else if (tb != 0)
            {
                wb = *((s16 *) (pa_obj + 4)) + 1;
            }
            pa = pa * wa;
            ptag = ptag * wb;
            sum = (pa + ptag) / (wa + wb);
            *((u8 *) (*((char **) (cur + 0x78)) + 0x14)) = (u8) sum;
            *((s8 *) (*((char **) (*((char **) (cur + 0x58)) + 0x78)) + 0x17)) = (s8) sum;
        }
        cur = *((char **) (cur + 0x5C));
    } while ((cur != head) && (cur != NULL));
}
