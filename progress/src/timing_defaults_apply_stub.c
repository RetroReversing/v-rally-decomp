void timing_defaults_apply(void *settings);
/* Forwards the settings block to timing_defaults_apply in the other segment. */
void timing_defaults_apply_stub(void *settings) { timing_defaults_apply(settings); }
