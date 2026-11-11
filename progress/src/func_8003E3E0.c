typedef void (*SpriteHook)(void *);
void add_label_sprites(s32,s32,s32,SpriteHook,u8*,u16,u8*);
extern char gStreamState[];
void update_time_display(void *);

/* Adds the label sprite for the current object, placing it by the object's position
 * (+8/+A/+C of its record at +0x178) and by the label mode (+0xE of the stream
 * block). Mode 1 and mode 2 use different offsets; mode 2 also depends on the
 * flag word at +0x12 and on the object type at +0xC of the current state. */
void func_8003E3E0(s32 arg0, s32 arg1)
{
  char *temp_t2;
  char *temp_v0;
  char *temp_a3;
  s32 temp_t3;
  s32 temp_a2;
  s32 var_a1;
  s32 var_t4;
  s16 temp_v1;
  s16 temp_t0;
  s32 mode;
  temp_t2 = *((char **) (gStreamState + 0x7CD6));
  temp_v0 = *((char **) (temp_t2 + 0x178));
  var_a1 = *((s16 *) (temp_v0 + 8));
  temp_v1 = *((s16 *) (temp_v0 + 0xA));
  temp_t0 = *((s16 *) (temp_v0 + 0xC));
  temp_a3 = *((char **) (gStreamState + 0x32F2));
  var_t4 = var_a1 + 0x14;
  temp_a2 = temp_v1 + 6;
  temp_t3 = temp_t0 - 0x10;
  mode = *((u16 *) (temp_a3 + 0xE));
  switch (mode)
  {
    case 1:
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
      {
        return;
      }
      var_a1 = temp_t0 - 0x4A;
      add_label_sprites((s32)(arg0), var_a1, temp_a2, &update_time_display, (u8 *)(arg1), 0, 0);
      return;
    case 2:
      if ((*((u16 *) (temp_a3 + 0x1E))) != 0)
      {
        return;
      }
      if ((*((u16 *) (temp_a3 + 0x12))) & 1)
      {
        var_a1 += 0x18;
        add_label_sprites((s32)(arg0), var_a1, temp_a2, &update_time_display, (u8 *)(arg1), 0, 0);
        return;
      }
      else if ((*((s32 *) (temp_t2 + 0xC))) == 3)
      {
        var_a1 = var_t4 + temp_t3;
        var_a1 = var_a1 - 0x48;
        add_label_sprites((s32)(arg0), var_a1, temp_a2, &update_time_display, (u8 *)(arg1), 0, 0);
        return;
      }
      else
      {
        var_a1 += 0x2C;
      }
      break;
    default:
      return;
  }
  add_label_sprites((s32)(arg0), var_a1, temp_a2, &update_time_display, (u8 *)(arg1), 0, 0);
}
