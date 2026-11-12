void obj_run_stages(void *obj);
void list_for_each(int head, void (*cb)(void));

/* Runs obj_run_stages on every node of the linked list at head (next pointer at offset 4). */
void obj_list_run_stages(int head)
{
    list_for_each(head, (void (*)(void))obj_run_stages);
}
