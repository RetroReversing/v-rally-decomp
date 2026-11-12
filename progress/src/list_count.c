struct L { struct L *x; struct L *next; };
/* Counts the nodes in a singly linked list (next pointer at +4), starting from *head_ref. */ int list_count(struct L **head_ref) { struct L *node = *head_ref; int count = 0; while (node) { node = node->next; count++; } return count; }
