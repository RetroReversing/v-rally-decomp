void *list_advance(u32 count, void *head) { u32 before; goto check; loop: head=*(void **)head; check: before=count; count--; if(before) goto loop; return head; }
