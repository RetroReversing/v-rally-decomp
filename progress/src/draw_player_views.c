void *view_get_ctx_id();
s32 view_gfx_setup();
s32 view_set_rect();
s32 view_write_fog_cmds();
s32 draw_object_parts();
void *find_object_by_id();
extern char gGameState[];
extern char stream_state[];

/* Draws the split-screen views for every player in the list. Each player owns
 * two view ids (odd and even); each view gets its rectangle, fog and object
 * parts written into its display list. */
void draw_player_views(void **players)
{
  char *car;
  char *player;
  char *race_state;
  char *phys;
  char *car_pos;
  s32 id_a;
  s32 id_b;
  void *ctx;
  char *ctx_b;
  s32 view;
  player = *players;
  race_state = *((char **) (stream_state + 0x32F2));
  id_b = 0;
  if (player != NULL)
  {
    id_a = -1;
    do
    {
 do { id_a += 2; car = find_object_by_id(id_a); view = *((s32 *) (car + 0x178)); *((char **) (stream_state + 0x7CD6)) = car; } while (0);
      view_gfx_setup(view);
      id_b += 2;
      view_set_rect(*((s32 *) (car + 0x178)), (*((s32 *) (car + 0x178))) + 8);
      car_pos = car + 0x38;
      ctx = view_get_ctx_id(*((s32 *) (car + 0x178)));
      do
      {
        u16 mode;
        volatile u16 *mode_reg;
        mode_reg = (volatile u16 *) (race_state + 0x1E);
        mode = *mode_reg;
        phys = *((char **) (car + 0x24));
        /* Fog start scales with the car's speed, except in race modes 7 and 8 where it is 0. */
        if (((u32) (mode - 7)) >= 2U)
        {
          *((s16 *) (gGameState + 0x6BE0)) = (*((s32 *) ((*((char **) (phys + 0x5C))) + 0x58))) / 48;
        }
        else
        {
          *((s16 *) (gGameState + 0x6BE0)) = 0;
        }
        view_write_fog_cmds(view_get_ctx_id(*((s32 *) (car + 0x178))));
        car = find_object_by_id(id_b);
        view_gfx_setup(*((s32 *) (car + 0x178)));
        view_set_rect(*((s32 *) (car + 0x178)), (*((s32 *) (car + 0x178))) + 8);
        ctx_b = view_get_ctx_id(*((s32 *) (car + 0x178)));
        view_write_fog_cmds(view_get_ctx_id(*((s32 *) (car + 0x178))));
        car = (char *) ctx_b;
        if ((*((u16 *) (player + 0x1A))) != 2)
        {
          draw_object_parts(gGameState + 0x6BD0, player, ctx, car, car_pos);
        }
      }
      while (0);
      player = *((char **) (player + 4));
    }
    while (player != NULL);
  }
}
