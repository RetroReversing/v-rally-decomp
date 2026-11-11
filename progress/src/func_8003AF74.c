void *orderFindNeighbor();

/* Looks up the object's pending sub-item (at +0xA8 -> +0x24) and, if it resolves,
   flags the object at +0x80 and sets its state at +0x7A. When the item's header
   at +0x20 is zero, it also fills the four colour bytes at +0x90 with white. The
   +0x80 flag is cleared again at the end. */
void func_8003AF74(void *obj)
{
    void *item;

    item = *((s32 *) (*((s32 *) (((char *) obj) + 0xA8)) + 0x24));
    if (item != 0)
    {
        item = orderFindNeighbor(obj, item);
        if (item != NULL)
        {
            *((s32 *) (((char *) obj) + 0x80)) = (*((s32 *) (((char *) obj) + 0x80))) | 4;
            if ((*((s32 *) (((char *) (*((void **) (((char *) item) + 0x6C)))) + 0xC))) != 0)
            {
                *((s16 *) (((char *) obj) + 0x7A)) = 0xB;
                if ((*((s32 *) (((char *) (*((void **) (((char *) item) + 0x6C)))) + 0x20))) == 0)
                {
                    *((u8 *) (((char *) obj) + 0x90)) = 0xFF;
                    *((u8 *) (((char *) obj) + 0x91)) = 0xFF;
                    *((u8 *) (((char *) obj) + 0x92)) = 0xFF;
                    *((u8 *) (((char *) obj) + 0x93)) = 0xFF;
                }
                *((s32 *) (((char *) obj) + 0x80)) &= ~4;
            }
        }
    }
}
