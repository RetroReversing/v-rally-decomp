typedef struct MenuState {
  u8 pad0[0x1E];
  u16 screen;   /* 0x1E: current screen id */
  u16 sub0;     /* 0x20 */
  u16 sub1;     /* 0x22 */
  u8 pad24[8];
  u16 flags;    /* 0x2C: bit 0x10 set while a transition is pending */
} MenuState;

extern u8 gStreamState[];
extern u8 *gSlotTableB[];
extern s32 D_8009FFE4;
extern u8 D_800A17F0;
extern unsigned char D_800A4CB4[];
extern u8 D_800A4CBC[];
extern u8 D_800A4CC4[];
extern u8 D_800A4CCC[];
extern u8 D_800A4CD4[];
extern u8 D_800A4CDC[];
extern u8 D_800A4CE4[];
extern u8 D_800A4CEC[];
extern u8 D_800A4CF4[];
extern u8 D_800A4CFC[];
extern u8 D_800A4D04[];

/* Per-frame update for the menu screen: starts a new transition when the
 * screen is 7 and no transition is pending, cycling through the six layouts;
 * then redraws the current screen's panel and any background panel. */
void func_800416EC(void)
{
  u8 *obj;
  u8 *a1;
  u8 s3;
  s32 mode;
  u16 s0;
  u16 s1;
  u16 s2;
  s3 = 0;
  ;
  switch (((MenuState *)(*(u8**)(gStreamState+0x32F2)))->screen) {
  case 7: s3=1; break;
  case 8: if (D_800A17F0==0) func_80077280(); break;
  }
  if ((!((((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->flags) & 0x10)) && (((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->screen == 7))
  {
    mode = D_8009FFE4;
    ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->screen = 0;
    switch (mode)
    {
      case 0:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 5;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 4;
        break;

      case 1:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 7;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 4;
        break;

      case 2:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 3;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 1;
        break;

      case 3:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 2;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 5;
        break;

      case 4:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 1;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 3;
        break;

      case 5:
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub0 = 6;
        ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->sub1 = 2;
        break;

    }

    D_8009FFE4++;
    if (D_8009FFE4 >= 6)
    {
      D_8009FFE4 = 0;
    }
  }
  obj = *((u8 **) (gStreamState + 0x32F2));
  s1 = *((u16 *) (obj + 0x1E));
  s2 = *((u16 *) (obj + 0x20));
  s0 = *((u16 *) (obj + 0x22));
  text_load_and_parse(gSlotTableB[s1] + (708 * s2), D_800A4CB4);
  if (s0 < 9)
  {
    switch (s0)
    {
      case 0:
        a1 = D_800A4CBC;
        break;

      case 1:
        a1 = D_800A4CC4;
        break;

      case 2:
        a1 = D_800A4CCC;
        break;

      case 3:
        a1 = D_800A4CD4;
        break;

      case 4:
        a1 = D_800A4CDC;
        break;

      case 5:
        a1 = D_800A4CE4;
        break;

      case 6:
        a1 = D_800A4CEC;
        break;

      case 7:
        a1 = D_800A4CF4;
        break;

      case 8:
        a1 = D_800A4CFC;
        break;

    }

    text_load_and_parse(gSlotTableB[s1] + (708 * s2), a1);
  }
  if (s3 != 0)
  {
    ;
    ((MenuState *)(*(u8 **)(gStreamState + 0x32F2)))->screen = 7;
  }
  text_load_and_parse(gSlotTableB[s1] + (708 * s2), D_800A4D04);
}
