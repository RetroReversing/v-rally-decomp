s32 func_800316C4(void *);
s32 func_800317D4(void *);
extern s32 gSnapIndex;
extern char D_8009F32C[];

/* For each object in the circular list starting at arg0 (linked via +0x5C), looks up
 * the object's id (+0x8C) among the 12 rows of the current table at D_8009F32C. A match
 * runs func_800316C4 on the object; no match runs func_800317D4. */
void func_8003310C(void *arg0)
{
    void *obj;
    void *head;
    s16 entry;
    s32 tblOffset;

    obj = arg0;
    head = arg0;
    do
    {
        entry = 0;
        do
        {
            tblOffset = (((s32)(entry << 16)) >> 13) + (gSnapIndex << 5);
            if (*(u16 *)(D_8009F32C + tblOffset) == *(u16 *)((char *)obj + 0x8C))
            {
                func_800316C4(obj);
                break;
            }
            entry++;
        } while (entry < 12);
        if (entry == 12)
        {
            func_800317D4(obj);
        }
        obj = *(void **)((char *)obj + 0x5C);
    } while (obj != head && obj != NULL);
}
