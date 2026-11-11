/* Local layout of a transform node, as used by transform_update_hierarchy. */
typedef struct Mtx { s32 m[16]; } Mtx;
typedef struct Transform { s32 dirty; struct Transform *parent; Mtx local; Mtx world; } Transform;

void mtx_concat(Mtx *a, Mtx *b, Mtx *c);

/* Updates the world matrix of a node after its parents. A root that is dirty gets its world matrix from its local matrix. */
void transform_update_hierarchy_10(Transform *node) {
    if (node->parent != NULL) {
        transform_update_hierarchy_10(node->parent);
        mtx_concat(&node->parent->world, &node->local, &node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
