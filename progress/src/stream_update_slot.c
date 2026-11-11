extern signed char gStreamLastValue;
extern char gStreamState[];

typedef struct VRStreamSrc { u16 value; u8 pad02[2]; s32 active; } VRStreamSrc;

/* Copies a stream source's 16-bit reading into its slot in the object at arg2.
 * When the slot changes and the source is active and the stream state is below 4,
 * the new value is also kept in gStreamLastValue. */
void stream_update_slot(VRStreamSrc *src, s32 unused, void *obj)
{
  u16 temp_a1;
  void *temp_v1;
  unsigned int new_var;
  temp_v1 = *((void **) (((char *) obj) + 0x70));
  temp_a1 = *((u16 *) (((char *) src) + 0));
  if ((*((s32 *) (((char *) temp_v1) + 0xC))) != (new_var = temp_a1))
  {
    *((s32 *) (((char *) temp_v1) + 0xC)) = (s32) new_var;
    if (((*(*((s32 **) (((char *) obj) + 0x48)))) < 4) && ((*((s32 *) (((char *) src) + 4))) == 1))
    {
      gStreamLastValue = (s8) new_var;
    }
  }
}
