void stream_fill_envelope(int a, int b);

/* Fills envelope row 0 of stream_state from the given track; channel index is 0. */ void stream_fill_envelope_ch0(int track) {
    stream_fill_envelope(track, 0);
}
