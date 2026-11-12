void alUnlink(void *node);
void al_link_push(void *node, void **head);

/* Unlinks a voice from its current list and pushes it onto the free list at pool+0x14. */
void _freePVoice(void *pool, void *voice) {
    alUnlink(voice);
    al_link_push(voice, (void **)((s8 *)pool + 0x14));
}
