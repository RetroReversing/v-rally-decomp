struct M { int m[16]; };
void mtx_concat(char *a, char *b, char *c);

/* Refreshes a transform's world matrix. If it has a parent, updates the parent first and
 * multiplies the parent's world matrix by the local matrix. Otherwise, when the dirty flag
 * is set, clears it and copies the local matrix to the world matrix. */
void transform_update_parented_copy11(char *transform) {
    if (*(char **)(transform + 4) != 0) {
        transform_update_parented_copy11(*(char **)(transform + 4));
        mtx_concat(*(char **)(transform + 4) + 0x48, transform + 8, transform + 0x48);
    } else if (*(int *)transform != 0) {
        *(int *)transform = 0;
        *(struct M *)(transform + 0x48) = *(struct M *)(transform + 8);
    }
}
