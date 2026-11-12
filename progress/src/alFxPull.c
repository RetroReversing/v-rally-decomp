extern char D_800A71C0[];
extern char D_800A71C4[];
#line 4 "reference.c"
Acmd *alFxPull(void *filter, s16 *outBuf, s32 sampleCount, s32 sampleOffset,
                     Acmd *p)
{
    Acmd        *cmd = p;
    ALFx	*fx = (ALFx *)filter;
    ALFilter    *srcFilter = fx->filter.source;
    s16	i, buffA, buffB, auxLDmem, auxRDmem;
    s16		*inPtr, *outPtr, gain, *prevOutPtr = 0;
    ALDelay	*delay, *prevDelay;

    if (!srcFilter) func_800914E0(D_800A71C0, D_800A71C4, 75);
    /*
     * pull channels going into this effect first
     */
    cmd = (*srcFilter->handler)(srcFilter, outBuf, sampleCount, sampleOffset, p);

    auxLDmem  = AL_AUX_L_OUT;
    auxRDmem  = AL_AUX_R_OUT;
    buffA  = AL_TEMP_0;
    buffB  = AL_TEMP_1;

    aSetBuffer(cmd++, 0, 0, 0, sampleCount<<1);  /* set the buffer size */
    aMix(cmd++, 0, 0xda83, AL_AUX_L_OUT, auxLDmem); /* .707L = L - .293L */
    aMix(cmd++, 0, 0x5a82, AL_AUX_R_OUT, auxLDmem); /* mix the AuxL and AuxR into the AuxL */
    /* and write the mixed value to the delay line at fx->input */
    cmd = _saveBuffer(fx, fx->input, auxLDmem, sampleCount, cmd);

    aClearBuffer(cmd++, auxRDmem, sampleCount<<1); /* clear the AL_AUX_R_OUT */

    for (i = 0; i < fx->section_count; i++) {
	delay  = &fx->delay[i];  /* get the ALDelay structure */
	inPtr  = &fx->input[-delay->input];
	outPtr = &fx->input[-delay->output];

	if (inPtr == prevOutPtr) {
	    SWAP(buffA, buffB);
	} else {  /* load data at inPtr into buffA */
	    cmd = _loadBuffer(fx, inPtr, buffA, sampleCount, cmd);
	}
	cmd = _loadOutputBuffer(fx, delay, buffB, sampleCount, cmd);

	if (delay->ffcoef) {
	    aMix(cmd++, 0, (u16)delay->ffcoef, buffA, buffB);
	    if (!delay->rs && !delay->lp) {
		cmd = _saveBuffer(fx, outPtr, buffB, sampleCount, cmd);
	    }
	}

	if (delay->fbcoef) {
	    aMix(cmd++, 0, (u16)delay->fbcoef, buffB, buffA);
	    cmd = _saveBuffer(fx, inPtr, buffA, sampleCount, cmd);
	}

	if (delay->lp)
	    cmd = _filterBuffer(delay->lp, buffB, sampleCount, cmd);

	if (!delay->rs)
	    cmd = _saveBuffer(fx, outPtr, buffB, sampleCount, cmd);

	if (delay->gain)
	    aMix(cmd++, 0, (u16)delay->gain, buffB, auxRDmem);

	prevOutPtr = &fx->input[delay->output];
    }

    /*
     * bump the master delay line input pointer
     * modulo the length
     */
    fx->input += sampleCount;
    if (fx->input > &fx->base[fx->length])
	fx->input -= fx->length;

    /*
     * output already in AL_AUX_R_OUT
     *      just copy to AL_AUX_L_OUT
     */
    aDMEMMove(cmd++, auxRDmem, AL_AUX_L_OUT, sampleCount<<1);

    return cmd;
}
