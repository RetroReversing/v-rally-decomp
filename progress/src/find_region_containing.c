/* Walks the circular region list starting at head (next pointer at +0x5C) and returns the
 * first region whose x range (+0x34..+0x3C) and y range (+0x44..+0x48) contain the point
 * stored in point[0] (x) and point[8] (y). Returns NULL if no region contains it. */
void *find_region_containing(void *head, void *point)
{
    s32 px;
    s32 y_min;
    s32 py;
    void *region;

    region = head;
    px = *((s32 *) point);
    do {
        if (px >= *((s32 *) (((char *) region) + 0x34)) && *((s32 *) (((char *) region) + 0x3C)) >= px)
        {
            y_min = *((s32 *) (((char *) region) + 0x44));
            py = *((s32 *) (((char *) point) + 8));
            if (py >= y_min && *((s32 *) (((char *) region) + 0x48)) >= py)
            {
                return region;
            }
        }
        region = *((void **) (((char *) region) + 0x5C));
    } while (region != head && region != NULL);
    return NULL;
}
