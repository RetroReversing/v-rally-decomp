void select_draw_results_table(s8 selected);
extern void *gSelectState;

/* Redraws the results table for the row stored at gSelectState+0x22A. */
void select_redraw_results(void) {
    select_draw_results_table(*(s8 *)((s8 *)gSelectState + 0x22A));
}
