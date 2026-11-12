extern char gStreamList[];
s32 poolAllocHeadNode(void);
extern char D_8009A552[];

/* Allocates the stream head node and stores its pointer at ((char *)&gStreamList) (the stream state). */
void func_8004C794(void)
{
    *(s32 *)(((char *)&gStreamList)) = poolAllocHeadNode();
}
