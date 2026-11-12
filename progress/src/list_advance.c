/* Follows the first-word link of a singly linked list 'steps' times and returns the node reached. */
void *list_advance(u32 steps, void *node)
{
    u32 before;
    goto check;
loop:
    node = *(void **)node;
check:
    before = steps;
    steps--;
    if (before)
    {
        goto loop;
    }
    return node;
}
