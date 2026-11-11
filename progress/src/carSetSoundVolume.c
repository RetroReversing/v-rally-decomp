/* Sets the 8 left/right channel volumes of a car's sound state. car->0x84 holds the
 * balance (0..100) that splits the master volume between the two channel pairs. */
void carSetSoundVolume(u8 *car, s32 volume) {
    *(s32 *)(*(u8 **)(car + 0x80) + 0x388) = volume;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x330) = (u32)(*(s32 *)(*(u8 **)(car + 0x84) + 0x48) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x334) = (u32)(*(s32 *)(*(u8 **)(car + 0x84) + 0x48) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x338) = (u32)((100 - *(s32 *)(*(u8 **)(car + 0x84) + 0x48)) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x33C) = (u32)((100 - *(s32 *)(*(u8 **)(car + 0x84) + 0x48)) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x340) = (u32)(*(s32 *)(*(u8 **)(car + 0x84) + 0x48) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x344) = (u32)(*(s32 *)(*(u8 **)(car + 0x84) + 0x48) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x348) = (u32)((100 - *(s32 *)(*(u8 **)(car + 0x84) + 0x48)) * volume) / 100;
    *(s32 *)(*(u8 **)(car + 0x80) + 0x34C) = (u32)((100 - *(s32 *)(*(u8 **)(car + 0x84) + 0x48)) * volume) / 100;
}
