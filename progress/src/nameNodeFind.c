s32 str_icmp_eq();

/* Returns the node itself if its name matches `name`, otherwise the last child
 * (scanning backwards from the end of the child table) whose name matches. Returns NULL if none. */
void *nameNodeFind(void *node, void *name)
{
    u32 off;
    s32 count;
    void **child;

    if (str_icmp_eq(name, node) != 0)
    {
        return node;
    }
    count = *((s32 *) (((char *) node) + 0x10));
    if (count > 0)
    {
        off = count << 2;
        child = (void **) (off + (u32) node);
        do
        {
            if (str_icmp_eq(name, child[5]) != 0)
            {
                return child[5];
            }
            count -= 1;
            child -= 1;
        }
        while (count > 0);
    }
    return NULL;
}
