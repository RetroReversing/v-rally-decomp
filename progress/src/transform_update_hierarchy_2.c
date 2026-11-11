typedef struct Mtx { s32 m[16]; } Mtx;

/* Transform node: dirty flag, parent link, local matrix at +0x08, world matrix at +0x48. */
typedef struct Transform { s32 dirty; struct Transform *parent; Mtx local; Mtx world; } Transform;

/* Multiplies two matrices (the third argument is not used by the callee). */
void mtx_concat(Mtx *a, Mtx *b, Mtx *c);

/* Updates the world matrix of a node after its parents. A root that is dirty gets its world matrix from its local matrix. */
void transform_update_hierarchy_2(Transform *node) {
    if (node->parent != NULL) {
        transform_update_hierarchy_2(node->parent);
        mtx_concat(&node->parent->world, &node->local, &node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
