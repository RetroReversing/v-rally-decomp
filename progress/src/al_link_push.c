typedef struct AlLink
{
  struct AlLink *next;
  struct AlLink **prev;
} AlLink;

/* Pushes 'node' onto the front of the doubly linked list whose head pointer is *head. */
void al_link_push(AlLink *node, AlLink **head)
{
  node->next = *head;
  node->prev = head;
  if (*head)
  {
    (*head)->prev = (AlLink **) node;
  }

  *head = node;
}
