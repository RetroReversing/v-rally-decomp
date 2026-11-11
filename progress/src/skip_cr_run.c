/* Skips bytes up to and past the next CR (13), then steps over any run of CRs that follows,
 * stopping at end. Returns the position reached. */
s8 *skip_cr_run(s8 *p, s8 *end)
{
    s32 cr_char = 13;

    do {
        if ((*(p++)) != cr_char) {
            s32 scan_char = 13;
scan:
            if (p >= end) {
                goto tail;
            }
            if ((*(p++)) != scan_char) {
                goto scan;
            }
        }
tail:
        if (p == end) {
            goto done;
        }
    } while (0);

    do {
        p++;
        if ((*p) != cr_char) {
            break;
        }
        p++;
    } while ((short) (p != end));

done:
    return p;
}
