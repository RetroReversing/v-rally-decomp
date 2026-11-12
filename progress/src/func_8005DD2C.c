typedef struct TextObj
{
    struct TextObj *next;
    u8 pad04[2];
    s16 x;
    s16 y;
    u8 pad0A;
    u8 r, g, b, a;
    u8 pad0F[0x1A - 0x0F];
    s8 flag1A;
} TextObj;

typedef struct
{
    u8 pad00[0xC];
    void *listHead;
    u8 pad10[0x220 - 0x10];
    u16 countdown;
    u8 pad222[0x248 - 0x222];
    u8 blink;
} MenuRoot;

typedef struct
{
    u8 pad00[0x2C];
    u16 flags2C;
} RecordsHdr;

void *textObjGet(u32);
s32 group_set_color(void *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
void *list_advance(u32, void *);
s32 input_get_buttons(s32);
s32 record_set_byte9(void *, s32, u8);
s32 format_to_buffer(char *, char *, ...);
extern MenuRoot *gSelectState;
extern f32 D_800A14CC;
extern s8 D_800A14D4;
extern char D_800A5488[];
extern char D_800A5490[];
extern VRMenuManager *gLeague;
extern RecordsHdr *gRecords;

/* Refreshes the league HUD: marks the menu dirty when the selected item's
 * value changes, blinks the 0x248 toggle, sets the three highlight entries
 * while the countdown runs, and redraws the value text from D_800A14CC. */
void func_8005DD2C(void)
{
    VRMenuItem *item;
    char text[5];
    TextObj *node;
    s32 i;
    s32 whole;
    u32 tenths;
    s32 frac;

    item = &gLeague->items[gLeague->count];
    if (item->value != ((u8 *)item)[0xD])
    {
        D_800A14D4 = 1;
    }
    if ((gRecords->flags2C & 0x2000) && (input_get_buttons(0) == 0x2020))
    {
        gSelectState->blink = (u8)~gSelectState->blink;
        record_set_byte9(gLeague, 9, gSelectState->blink);
        ((s8 *)list_advance(5, gSelectState->listHead))[0x41] = gSelectState->blink;
    }
    if (gSelectState->countdown != 0)
    {
        node = textObjGet(0);
        i = 0;
        do
        {
            node->flag1A = 1;
            node = node->next;
            i += 1;
        }
        while ((u32)(i & 0xFF) < 3U);
        gSelectState->countdown = (u16)(gSelectState->countdown - 1);
    }
    else
    {
        node = textObjGet(0);
        i = 0;
        do
        {
            node->flag1A = 0;
            node = node->next;
            i += 1;
        }
        while ((u32)(i & 0xFF) < 3U);
    }
    node = textObjGet(4);
    group_set_color(node, node->r, node->g, node->b, (s32)node->a);
    text[4] = 0;
    whole = (u32)D_800A14CC;
    tenths = (u16)(u32)(D_800A14CC * 10.0f);
    frac = (tenths % 10) & 0xFFFF;
    if (frac != 0)
    {
        format_to_buffer(text, D_800A5488, whole & 0xFF, frac);
    }
    else
    {
        format_to_buffer(text, D_800A5490, whole & 0xFF);
    }
    draw_palette_sprite((void *)(node), node->x, node->y, (void *)(text));
}
