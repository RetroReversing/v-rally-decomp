typedef struct Root Root; void draw_object_list(Root *root);
/* Forwards the root to draw_object_list. */
void draw_object_list_stub(Root *root) { draw_object_list(root); }
