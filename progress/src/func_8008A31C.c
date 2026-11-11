typedef struct MItem { void (*draw)(s32, s32, s32); s32 action; u8 type; u8 pad9; u8 visible; u8 padB; } MItem;
typedef struct MPage { void (*draw)(void); s32 def; MItem *items; u8 count; u8 first; u8 sel; u8 back; s32 timeout; } MPage;
typedef struct Menu { s16 pad0; s16 cur; u16 timer; s16 pad6; s32 (*get)(void); void (*cb)(s32); MPage *pages; } Menu;

extern s16 func_80089C48(MPage *, s32, s32, u8, s16 *, u8 *, Menu *, s32);
extern u8 D_800A1C70;

/* Runs one frame of a menu: reads input, draws the visible items and the page
 * overlay (unless D_800A1C70 is set), then sends the input to the item and the back
 * action. The selection and current page change when the handler asks for it. */
void func_8008A31C(Menu *menu) {
    MPage *page;
    s32 input;
    u8 pressed;
    u8 i;
    MItem *item;
    s16 result;
    s16 new_cur;
    u8 done;

    page = &menu->pages[menu->cur];
    input = menu->get();
    pressed = 0;
    if (menu->cb != NULL) {
        menu->cb(input);
    }
    if (menu->timer == page->timeout) {
        if (menu->timer != 0) {
            input = 0x10000;
            menu->timer = 0;
        }
    } else if (input != 0) {
        pressed = 1;
    }
    if (D_800A1C70 == 0) {
        for (i = 0; i < page->count; i++) {
            if (page->items[i].draw != NULL && page->items[i].visible != 0) {
                page->items[i].draw(i + page->first == page->sel, i + page->first, i);
            }
        }
        if (page->draw != NULL) {
            page->draw();
        }
    }
    done = 0;
    new_cur = result = -1;
    if (page->count != 0) {
        result = func_80089C48(page, page->items[page->sel - page->first].action, input, page->items[page->sel - page->first].type, &new_cur, &done, menu, page->sel);
        if (result != -1) {
            page->sel = result;
        }
        if (new_cur != -1) {
            menu->cur = new_cur;
        }
    }
    if (done == 0 && page->back != 0) {
        result = func_80089C48(page, page->def, input, page->back, &new_cur, &done, menu, 0);
        if (result != -1) {
            page->sel = result;
        } else if (new_cur != result) {
            menu->cur = new_cur;
            menu->pages[new_cur].sel = menu->pages[new_cur].first;
        }
    }
    if (pressed && done) {
        menu->timer = 0;
    }
    menu->timer++;
}
