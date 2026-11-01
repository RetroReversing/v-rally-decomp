#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct MItem { void (*draw)(s32, s32, s32); s32 action; u8 type; u8 pad9; u8 visible; u8 padB; } MItem;
typedef struct MPage { void (*draw)(void); s32 def; MItem *items; u8 count; u8 first; u8 sel; u8 back; s32 timeout; } MPage;
typedef struct Menu { s16 pad0; s16 cur; u16 timer; s16 pad6; s32 (*get)(void); void (*cb)(s32); MPage *pages; } Menu;

extern s16 func_80089C48(MPage *, s32, s32, u8, s16 *, u8 *, Menu *, s32);
extern u8 D_800A1C70;

void func_8008A31C(Menu *m) {
    MPage *page;
    s32 in;
    u8 flag;
    u8 i;
    MItem *it;
    s16 r;
    s16 newcur;
    u8 done;

    page = &m->pages[m->cur];
    in = m->get();
    flag = 0;
    if (m->cb != NULL) {
        m->cb(in);
    }
    if (m->timer == page->timeout) {
        if (m->timer != 0) {
            in = 0x10000;
            m->timer = 0;
        }
    } else if (in != 0) {
        flag = 1;
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
    newcur = r = -1;
    if (page->count != 0) {
        r = func_80089C48(page, page->items[page->sel - page->first].action, in, page->items[page->sel - page->first].type, &newcur, &done, m, page->sel);
        if (r != -1) {
            page->sel = r;
        }
        if (newcur != -1) {
            m->cur = newcur;
        }
    }
    if (done == 0 && page->back != 0) {
        r = func_80089C48(page, page->def, in, page->back, &newcur, &done, m, 0);
        if (r != -1) {
            page->sel = r;
        } else if (newcur != r) {
            m->cur = newcur;
            m->pages[newcur].sel = m->pages[newcur].first;
        }
    }
    if (flag && done) {
        m->timer = 0;
    }
    m->timer++;
}

