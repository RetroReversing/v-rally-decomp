/* identical to TransformUpdate (matched), with its names changed by decompdecomp */

struct M { int m[16]; };
void mtx_concat(char *a, char *b, char *c);
void transform_update_parented_copy2(char *arg0) {
    if (*(char **)(arg0 + 4) != 0) {
        transform_update_parented_copy2(*(char **)(arg0 + 4));
        mtx_concat(*(char **)(arg0 + 4) + 0x48, arg0 + 8, arg0 + 0x48);
    } else if (*(int *)arg0 != 0) {
        *(int *)arg0 = 0;
        *(struct M *)(arg0 + 0x48) = *(struct M *)(arg0 + 8);
    }
}
