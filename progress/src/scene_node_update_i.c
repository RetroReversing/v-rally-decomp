struct SceneMatrix { int m[16]; };
void mtx_concat(char *a, char *b, char *c);

/* Refreshes a scene node's world matrix. If the node has a parent, the parent is refreshed first and the world matrix is the parent's world matrix times this node's local matrix. A root node with its dirty flag set copies its local matrix to the world matrix and clears the flag. */
void scene_node_update_i(char *node) {
    if (*(char **)(node + 4) != 0) {
        scene_node_update_i(*(char **)(node + 4));
        mtx_concat(*(char **)(node + 4) + 0x48, node + 8, node + 0x48);
    } else if (*(int *)node != 0) {
        *(int *)node = 0;
        *(struct SceneMatrix *)(node + 0x48) = *(struct SceneMatrix *)(node + 8);
    }
}
