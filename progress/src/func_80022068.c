s32 carSetSoundVolume();

/* Sets a car's sound volume from a 0..100 percent: maps it into the car's min..max range,
 * stores it scaled by 32, copies it to the alternate block and sends it to the sound driver. */
void func_80022068(void *car, s32 percent)
{
    s32 maxVal;
    s32 minVal;
    void *cfg;
    void *vol;
    void *vol2;

    cfg = *((void **) (((char *) car) + 0x80));
    maxVal = *((s32 *) (((char *) cfg) + 0x18));
    minVal = *((s32 *) (((char *) cfg) + 0x40));
    vol = *((void **) (((char *) car) + 0x2C));
    *((s32 *) (((char *) vol) + 0x50)) = (s32) (((percent * (maxVal - minVal)) / 100) + minVal);
    vol2 = *((void **) (((char *) car) + 0x2C));
    *((s32 *) (((char *) vol2) + 0x50)) = (s32) ((*((s32 *) (((char *) vol2) + 0x50))) << 5);
    *((s32 *) (((char *) (*((void **) (((char *) car) + 0x58)))) + 0x50)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) car) + 0x2C)))) + 0x50)));
    *((s32 *) (((char *) (*((void **) (((char *) car) + 0x84)))) + 0x48)) = percent;
    carSetSoundVolume(car, *((s32 *) (((char *) (*((void **) (((char *) car) + 0x80)))) + 0x388)), vol, minVal);
}
