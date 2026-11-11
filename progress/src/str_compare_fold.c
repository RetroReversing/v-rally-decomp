s32 toLowerChar(u8);

/* Compares two strings through toLowerChar (a per-character fold). Returns 1 if str1 sorts after str2, 0 if
 * before, 2 if they are equal, and 1 if str1 is longer when one ends first. */
s32 str_compare_fold(u8 *str1, u8 *str2) {
s32 i;
for(i=0;str1[i] && str2[i];i++) {
if ((u8)toLowerChar(str1[i]) > (u8)toLowerChar(str2[i])) return 1;
if ((u8)toLowerChar(str1[i]) < (u8)toLowerChar(str2[i])) return 0;
}
if (!str1[i] && !str2[i]) return 2;
return str1[i]!=0;
}
