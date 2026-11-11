/* Transform node: 0x00 dirty flag, 0x04 parent, 0x08 local matrix, 0x48 world matrix.
 * Refreshes the world matrix: a child is re-concatenated with its parent's world matrix after the
 * parent is updated; a root copies local to world when its dirty flag is set. */
typedef struct Mtx4 { s32 m[16]; } Mtx4;
typedef struct Transform {
    s32 dirty;
    struct Transform *parent;
    Mtx4 local;
    Mtx4 world;
} Transform;

void mtx_concat(void *a, void *b, void *c);

void func_80064600(Transform *node) {
    if (node->parent != NULL) {
        func_80064600(node->parent);
        mtx_concat(&node->parent->world, &node->local, &node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
