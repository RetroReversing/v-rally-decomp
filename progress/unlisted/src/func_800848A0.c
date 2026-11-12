typedef struct { s32 w[6]; } Pkt6;
void dmaCopyChunks(s32 arg0, s32 arg1, u32 arg2, Pkt6 arg3);
extern s32 gOrderState, gStreamState;

/* Stream cache state inside gStreamState, by byte offset. */
#define STATE_CACHED_BASE 0x30A6
#define STATE_LEFT        0x3092
#define STATE_BUF_RAM     0x308A
#define STATE_CUR_PTR     0x308E
#define CONFIG_ROM_BASE   0x8AB0
#define CONFIG_PKT        0x2358
#define G(o) (*(s32*)((u8*)&gStreamState+(o)))
#define H(o) (*(s32*)((u8*)&gOrderState+(o)))

/* Makes sure the 8 KB stream block that holds offset is loaded into the
 * buffer, and points the read pointer at offset inside it. If the block
 * is not the cached one, DMA it in and reset the bytes-left count. */
void func_800848A0(s32 offset) {
 s32 inBlock; s32 blockBase; s32 original=offset;
 inBlock=offset/8192;
 offset=original;
 inBlock=offset-(inBlock<<13); blockBase=offset-inBlock;
 if(blockBase!=G(STATE_CACHED_BASE)) {
  G(STATE_CACHED_BASE)=blockBase;
  G(STATE_LEFT)=8192;
  dmaCopyChunks(H(CONFIG_ROM_BASE)+blockBase,G(STATE_BUF_RAM),8192,*(Pkt6*)((u8*)&gOrderState+CONFIG_PKT));
  G(STATE_CUR_PTR)=G(STATE_BUF_RAM)+inBlock;
  G(STATE_LEFT)-=inBlock;
 } else {
  G(STATE_LEFT)+=(G(STATE_CUR_PTR)-G(STATE_BUF_RAM))-inBlock;
  G(STATE_CUR_PTR)=G(STATE_BUF_RAM)+inBlock;
 }
}
