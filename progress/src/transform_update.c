struct M { int m[16]; };
void mtx_concat(char *a, char *b, char *c);

/* Updates a transform node. If it has a parent, the parent is updated first and
 * the node's world matrix (at +0x48) becomes parent_world * local (at +8).
 * A root node with its dirty flag set just copies its local matrix to world. */
void transform_update(char *node) {
    if (*(char **)(node + 4) != 0) {
        transform_update(*(char **)(node + 4));
        mtx_concat(*(char **)(node + 4) + 0x48, node + 8, node + 0x48);
    } else if (*(int *)node != 0) {
        *(int *)node = 0;
        *(struct M *)(node + 0x48) = *(struct M *)(node + 8);
    }
}
