typedef struct Mtx4 { s32 m[16]; } Mtx4;

typedef struct Transform {
    s32 dirty;
    struct Transform *parent;
    Mtx4 local;
    Mtx4 world;
} Transform;

void mtx_concat(char *a, char *b, char *c);

/* Recomputes a node's world matrix. A node with a parent first updates the parent,
 * then multiplies the parent's world matrix by its own local matrix. A root node
 * copies its local matrix into the world matrix when its dirty flag is set. */
void func_80052650(Transform *node) {
    if (node->parent != NULL) {
        func_80052650(node->parent);
        mtx_concat((char *)&node->parent->world, (char *)&node->local, (char *)&node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
