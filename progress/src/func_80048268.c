extern char gStreamState[];
/* Tests whether the quad with corners c0..c3 (x,y pairs) overlaps the clip rectangle stored at +0x178 of the current scene object. Returns 1 if it does, 0 if not. */
s32 func_80048268(s16 *c0, s16 *c1, s16 *c2, s16 *c3) {
 s16 *rect = *(s16 **)(*(char **)(gStreamState + 0x7CD6) + 0x178);
 s32 left=rect[4], top=rect[5], right=left+rect[6], bottom=top+rect[7];
 if ((left<c0[0] || left<c1[0] || left<c2[0] || left<c3[0]) && (c0[0]<right || c1[0]<right || c2[0]<right || c3[0]<right) && (top<c0[1] || top<c1[1] || top<c2[1] || top<c3[1])) { goto inside; }
 return 0;
 inside: {
 if (c0[1]>=bottom && c1[1]>=bottom && c2[1]>=bottom && c3[1]>=bottom) return 0;
 return 1;
 }
 return 0;
}
