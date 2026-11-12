typedef struct Style
{
  struct Style *next;
  u16 id;
  s16 x;
  s16 y;
  u8 pad0A;
  u8 r;
  u8 g;
  u8 b;
  u8 a;
  u8 pad0F[0x1A - 0xF];
  u8 visible;
  u8 mode;
} Style;
typedef struct Widget
{
  struct Widget *next;
  u8 sub[0x24];
  Style *styles;
  u8 pad2C[0x41 - 0x2C];
  u8 active;
  u8 mode;
  u8 pad43[0x4D - 0x43];
  u8 nstyles;
  u8 useStyleMode;
} Widget;
typedef struct Group
{
  struct Group *next;
  u16 w0;
  u16 w1;
  u8 b8;
  s8 b9;
  u8 active;
} Group;
typedef struct Task
{
  u8 pad[0x10];
  void *arg;
  void (*fn)(void *);
} Task;
typedef struct Menu
{
  Style *styles;
  u8 pad4[4];
  s32 nstyles;
  Widget *widgets;
  u8 pad10[4];
  s32 nwidgets;
  Group *groups;
  u8 pad1C[4];
  s32 ngroups;
  Group *groups2;
  u8 pad28[4];
  s32 ngroups2;
  u8 pad30[0x222 - 0x30];
  s16 f222;
  u8 pad224[0x232 - 0x224];
  u8 f232;
  s8 f233;
  u8 pad234[0x249 - 0x234];
  u8 f249;
  u8 pad24A;
  s8 f24B;
  u8 pad24C;
  u8 f24D;
  u8 pad24E[0x28C - 0x24E];
  void (*callback)(void);
  u8 pad290[0x2BD - 0x290];
  s8 f2BD;
} Menu;
extern u8 *gSelectState;
#define MENU ((Menu *)gSelectState)
extern Task *D_800C5D20[];
extern void *g_camera;
extern u8 stream_state[];
struct N { int p0; struct N *next; int p8; int key; };
extern struct N *find_object_by_id(int);
extern void stream_draw_entry(void *, s32, s16, s16);
extern void func_8005BCD4(void);
extern void draw_select_entry(u8 *, s32);
extern void *textObjGet(u32);
extern void *select_get_entry(u32);
typedef struct { u8 pad0[0xA]; s8 group; } GroupOwner;
extern void group_set_color(GroupOwner *, u8, u8, u8, u8);
extern s32 pool_get_item(s32 *, s32);
typedef struct { u8 p[0xA]; s8 idx; u8 q; u8 t; u8 s; u8 r; u8 pad; f32 w10; f32 f14; u16 h18; } Arg;
void draw_palette_sprite(void *, s16, s16, void *);

/* Picks the current text context from the call slot: slots 0 and 1 use
 * `primary`, slot 4 uses `last`, anything else uses `other`. */
static __inline__ void set_group_ctx(u8 idx,s32 primary,s32 last,s32 other) {
if(idx==0) { g_camera=find_object_by_id(primary); }
else if(idx==1) { g_camera=find_object_by_id(primary); }
else if(idx==4) { g_camera=find_object_by_id(last); }
else { g_camera=find_object_by_id(other); }
}

/* Per-frame menu draw. Runs the five task slots (skipping slot 1 while
 * MENU->f24D is set), the menu callback, then draws the style sprites, the
 * widget and group text, and counts down the menu timers. */
void func_80059A60(void)
{
  u8 i;
  u8 j;
  u8 n;
  s32 which;
  Style *s;
  Widget *w;
  Group *g;
  u8 *flags;
  if (MENU->f232 && (MENU->f233 >= 0))
  {
    stream_draw_entry(find_object_by_id(0), (u16)MENU->f233, 0, 0);
  }
  if (MENU->f249)
  {
    for (i = 0; i < 5; i++)
    {
      if (D_800C5D20[i] == NULL)
      {
        continue;
      }
      set_group_ctx(i,2,1,1);
      if ((i != 1) || (!MENU->f24D))
      {
        D_800C5D20[(unsigned int) i]->fn(D_800C5D20[i]->arg);
      }
    }
  }
  if (MENU->callback)
  {
    MENU->callback();
  }
  if (MENU->f249 && (MENU->f222 >= 0))
  {
    func_8005BCD4();
  }
  if (MENU->nstyles && MENU->f249)
  {
    n = MENU->nstyles;
    s = MENU->styles;
    for (i = 0; i < n; i++, s = s->next) { if (s->visible) { draw_select_entry((u8 *)s, s->mode); } }
  }
  if (MENU->nwidgets)
  {
    n = MENU->nwidgets;
    w = MENU->widgets;
    for (i = 0; i < n; i++, w = w->next)
    {
      flags = (u8 *)w + 0x41;
      if (*flags)
      {
        draw_select_entry(w->sub, w->mode);
        if ((!w->useStyleMode) || w->mode)
        {
          s = w->styles;
          for (j = 0; j < w->nstyles; s = s->next, j++)
          {
            if (s->visible)
            {
              u8 hl;
              if (w->useStyleMode) { hl = s->mode; } else { hl = flags[1]; }
              if (hl)
              {
                group_set_color((GroupOwner *)s, 220, 220, 14, 255);
              }
              else
              {
                group_set_color((GroupOwner *)s, s->r, s->g, s->b, s->a);
              }
              #ifdef PORT
              draw_palette_sprite((void *)((Arg *)s), (s16)(s->x), (s16)((u16)((u16)s->y)), (void *)(uintptr_t)(pool_get_item((s32 *)(uintptr_t)*((s32 *) (stream_state + 0x807A)), s->id)));
#else
              draw_palette_sprite((void *)((Arg *)s), (s16)(s->x), (s16)((u16)((u16)s->y)), (void *)(pool_get_item((s32 *)*((s32 *) (stream_state + 0x807A)), s->id)));
#endif
            }
          }
        }
      }
    }
  }
  if (MENU->ngroups)
  {
    n = MENU->ngroups;
    g = MENU->groups;
    for (i = 0; i < n; i++)
    {
      if (g->active)
      {
        MENU->f24D = 0;
        s = textObjGet(g->b9);
        for (j = 0; j < g->b8; j++, s = s->next)
        {
          draw_select_entry((u8 *)s, s->mode);
        }
        w = select_get_entry(g->w0);
        draw_select_entry(w->sub, w->mode);
        which = g->w1;
        w = select_get_entry((u16)which);
        draw_select_entry(w->sub, w->mode);
        MENU->f24D = 1;
      }
    }
  }
  if (MENU->ngroups2)
  {
    n = MENU->ngroups2;
    g = MENU->groups2;
    for (i = 0; i < n; i++)
    {
      if (g->active)
      {
        MENU->f24D = 0;
        if (g->b9)
        {
          s = textObjGet(g->b8);
          for (j = 0; j < g->b9; j++, s = s->next)
          {
            draw_select_entry((u8 *)s, s->mode);
          }
        }
        w = select_get_entry(g->w0);
        for (j = 0; j < g->w1; j++, w = w->next)
        {
          draw_select_entry(w->sub, w->mode);
        }
        MENU->f24D = 1;
      }
    }
  }
  if (MENU->f24B >= 0)
  {
    MENU->f24B--;
  }
  if ((MENU->f2BD >= 0) && MENU->f249)
  {
    MENU->f249--;
  }
}