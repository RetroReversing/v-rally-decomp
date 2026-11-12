extern u8 stream_state[];
extern u8 gOrderState[];
extern u8 D_800A4B48[];
void *list_find_node(void **, u8 *);
void *find_object_by_id(s32);

/* Per-frame update of an object's state from the link it is attached to: it
 * sets the attached flag, picks a placement from the neighbouring entries,
 * and sets the vertical offset from the placed entry's height. */
void func_8003F11C(void *object) {
    u8 *car = object;
    u8 *target;
    s32 flags;
    s32 kind;
    u8 *node;
    u8 *buf;
    u8 *prev;
    u8 *info;
    s16 width;
    s16 height;

    target = *((u8 **) ((*((u8 **) (car + 0xA8))) + 0x24));
    if (target != NULL)
    {
        *((u32 *) (car + 0x80)) |= 4;
        flags = *((s32 *) (target + 0x14));
        if (flags & 0x80)
        {
            kind = *((s32 *) ((*((u8 **) (target + 0x6C))) + 8));
            if ((kind == 1) && (flags & 0x100))
            {
                *((s16 *) (car + 0x7A)) = 1;
                prev = *((u8 **) (stream_state + 0x32F2));
                *((u32 *) (car + 0x80)) &= ~4;
                if ((*((u16 *) (prev + 0xE))) == kind)
                {
                    if ((*((s16 *) (car + 0xE))) >= 0x47)
                    {
                        *((s16 *) (car + 0xE)) = 0x3C;
                    }
                }
            }
            else
                if (!(flags & 0x100))
            {
                kind = 0;
                for (node = *((u8 **) (*((u8 **) (gOrderState + 0x73F0)))); node != NULL; node = *((u8 **) (node + 4)))
                {
                    if (((*((s32 *) (*((u8 **) (node + 0x48))))) < 4) && (node != target))
                    {
                        if ((*((s32 *) (node + 0x14))) & 0x100)
                        {
                            kind = 1;
                        }
                    }
                }

                if (kind == 0)
                {
                    buf = find_object_by_id(((*((u16 *) ((*((u8 **) (stream_state + 0x32F2))) + 0xE))) * 2) + 2);
                    if (list_find_node((void **)(buf + 0x28), (u8 *)(D_800A4B48)) != 0)
                    {
                        *((u32 *) (car + 0x80)) |= 4;
                    }
                    else
                    {
                        *((s16 *) (car + 0x7A)) = 0;
                        info = *((u8 **) ((*((u8 **) (car + 0xA8))) + 0x178));
                        width = *((s16 *) (info + 0xE));
                        height = *((s16 *) (info + 0xA));
                        *((u32 *) (car + 0x80)) &= ~4;
                        *((s16 *) (car + 0xE)) = height + (width / 2);
                    }
                }
            }
            ;
            *((s16 *) (car + 0x70)) = -((*((u16 *) ((*((u8 **) ((*((u8 **) ((*((u8 **) (car + 0xA4))) + 4))) + ((*((s16 *) (car + 0x7A))) * 4)))) + 6))) >> 1);
        }
    }
}
