typedef struct SceneMtx { s32 m[16]; } SceneMtx;
typedef struct SceneNode { s32 dirty; struct SceneNode *parent; SceneMtx local; SceneMtx world; } SceneNode;
void mtx_concat(char *a, char *b, char *c);

/* Recomputes a node's world matrix: updates the parent chain first, then composes
 * parent world * local. A node with no parent just copies its local matrix when dirty. */
void scene_node_update(SceneNode *node) {
    if (node->parent != 0) {
        scene_node_update(node->parent);
        mtx_concat((char *)&node->parent->world, (char *)&node->local, (char *)&node->world);
    } else if (node->dirty != 0) {
        node->dirty = 0;
        node->world = node->local;
    }
}
