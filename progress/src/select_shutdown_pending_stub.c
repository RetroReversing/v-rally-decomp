void select_shutdown_pending(void);
/* Select-stage exit hook: shuts down pending stream work. */
void select_shutdown_pending_stub(void) { select_shutdown_pending(); }
