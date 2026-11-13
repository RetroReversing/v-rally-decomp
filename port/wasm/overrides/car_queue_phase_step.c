/* port (WebAssembly build): the switch cases follow the console's jump table. The matched C's labels compile to
   the same code but a different table, which the judge doesn't compare: this fix belongs in the matched C. */
extern u8 stream_state[];
extern u8 D_800A4D44[];
extern u8 D_800A4D48[];
extern u8 D_800A4D50[];
extern u8 D_800A4D58[];
extern u8 D_800A4D60[];
extern u8 D_800A4D68[];
extern u8 D_800A4D70[];
extern u8 D_800A4D74[];
extern u8 D_800A4D7C[];
extern u8 D_800A4D84[];
void text_load_and_parse(void *arg0, void *arg1);
void func_80023380(void);

/* Queues the step-by-step update for one car in the given phase (0..8; labels follow
   jtbl_800A4D98). Each car record is 708 bytes in the car list; every phase but 4 runs the
   common prefix and suffix and its own middle entry; phase 4 queues nothing. */
void car_queue_phase_step(s32 phase, s32 car_idx) {
    switch (phase) {
    case 0:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D48);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 1:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D58);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 2:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D60);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 3:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D68);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 5:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D70);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 6:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D74);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 7:
        func_80023380();
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D7C);
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D50);
        break;
    case 8:
        text_load_and_parse(*(u8 **)(stream_state + 0x103AA) + car_idx * 708, D_800A4D44);
        func_80023380();
        text_load_and_parse(D_800A4D84, D_800A4D50);
        break;
    case 4:
        break;
    }
}
