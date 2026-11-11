/* Refreshes a transform node's world matrix. A node with a parent first refreshes the parent
 * chain, then concatenates its local matrix with the parent's world matrix. A root copies local
 * to world when its dirty flag is set. */
typedef struct VRMtx4 { s32 m[16]; } VRMtx4;
typedef struct VRTransform { s32 dirty; struct VRTransform *parent; VRMtx4 local; VRMtx4 world; } VRTransform;

void mtx_concat(void *a, void *b, void *c);

void transform_update_hierarchy_b(VRTransform *node) {
    if (node->parent != NULL) {
        transform_update_hierarchy_b(node->parent);
        mtx_concat(&node->parent->world, &node->local, &node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
