s32 func_800231EC();
s32 StreamListClaimByType();

/* Given a 4-bit slot mask, finds the lowest bit (1, 2, 4 or 8) that is clear and claims it
 * with StreamListClaimByType(mask, bit, index), where index is 0..3 for that bit. Returns 0 when the
 * mask is 0 or when all four bits are set (no free slot). */
s32 claimLowestFreeSlot(s32 mask) {
    if (mask == 0) {
        goto block_9;
    }
    if (func_800231EC(mask, 1) == 0) {
        goto block_8;
    }
    if (func_800231EC(mask, 2) == 0) {
        goto block_7;
    }
    if (func_800231EC(mask, 4) == 0) {
        goto block_6;
    }
    if (func_800231EC(mask, 8) != 0) {
        goto block_10;
    }
    return StreamListClaimByType(mask, 8, 3);
block_6:
    return StreamListClaimByType(mask, 4, 2);
block_7:
    return StreamListClaimByType(mask, 2, 1);
block_8:
    return StreamListClaimByType(mask, 1, 0);
block_9:
block_10:
    return 0;
}
