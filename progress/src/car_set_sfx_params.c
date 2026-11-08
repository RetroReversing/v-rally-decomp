typedef struct TabA {
    u16 id;
    u8 v[6];
} TabA;
typedef struct TabB {
    u16 id;
    u8 v[16];
} TabB;
typedef struct Sfx {
    u8 pad00[0xE];
    u8 bE;
    u8 bF;
    u8 pad10[4];
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 pad18[2];
    u8 b1A;
    u8 b1B;
} Sfx;
typedef struct Car {
    u8 pad00[0xA];
    u16 flags;
    u8 pad0C[0x78 - 0xC];
    Sfx *sfx;
    u8 pad7C[0x8C - 0x7C];
    u16 model;
} Car;
extern s32 D_8009EB80;
extern u8 D_8009EC44[][5];
extern TabB D_8009EC6C[][12];
extern TabA D_8009F32C[][4];

/* Fills the engine sound parameters of a car from the per-class tables, looked
 * up by the car's model id. Special models and the alternate (0x100 flag)
 * variants use their own rows. Returns 0 if the model has no sound entry. */
s32 car_set_sfx_params(Car *car)
{
    s32 p;
    s32 end;
    s32 i;

    car->sfx->b1B = 0;
    for (p = 0; p < 5; p++) {
        if (D_8009EC44[D_8009EB80][p] == car->model) {
            goto special;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_8009F32C[D_8009EB80][i].id == car->model) {
            if (car->flags & 0x100) {
                goto alt;
            }
            car->sfx->bE = 0;
            car->sfx->bF = 0;
            car->sfx->b14 = D_8009F32C[D_8009EB80][i].v[0];
            car->sfx->b16 = 0;
            car->sfx->b15 = 0;
            car->sfx->b17 = D_8009F32C[D_8009EB80][i].v[1];
            car->sfx->b1B = D_8009F32C[D_8009EB80][i].v[2];
            return 1;
        }
    }
    for (i = 0; i < 12; i++) {
        if (D_8009EC6C[D_8009EB80][i].id == 0) {
            return 0;
        }
        if (D_8009EC6C[D_8009EB80][i].id == car->model) {
            break;
        }
    }
    if (!(car->flags & 0x100)) {
        goto normal;
    }
    car->sfx->bE = D_8009EC6C[D_8009EB80][i].v[8];
    car->sfx->bF = D_8009EC6C[D_8009EB80][i].v[9];
    car->sfx->b14 = D_8009EC6C[D_8009EB80][i].v[10];
    car->sfx->b16 = D_8009EC6C[D_8009EB80][i].v[11];
    car->sfx->b15 = D_8009EC6C[D_8009EB80][i].v[12];
    car->sfx->b17 = D_8009EC6C[D_8009EB80][i].v[13];
    car->sfx->b1B = D_8009EC6C[D_8009EB80][i].v[15];
    car->sfx->b1A = D_8009EC6C[D_8009EB80][i].v[14];
    goto done;
special:
    car->flags |= 0x800;
    car->sfx->bE = 0;
    car->sfx->bF = 0;
    car->sfx->b14 = 0x32;
    car->sfx->b16 = 0;
    car->sfx->b15 = 0;
    car->sfx->b17 = 0x32;
    car->sfx->b1B = 0;
    return 1;
alt:
    car->sfx->bE = 0;
    car->sfx->bF = 0;
    car->sfx->b14 = D_8009F32C[D_8009EB80][i].v[3];
    car->sfx->b16 = 0;
    car->sfx->b15 = 0;
    car->sfx->b17 = D_8009F32C[D_8009EB80][i].v[4];
    car->sfx->b1B = D_8009F32C[D_8009EB80][i].v[5];
    return 1;
normal:
    car->sfx->bE = D_8009EC6C[D_8009EB80][i].v[0];
    car->sfx->bF = D_8009EC6C[D_8009EB80][i].v[1];
    car->sfx->b14 = D_8009EC6C[D_8009EB80][i].v[2];
    car->sfx->b16 = D_8009EC6C[D_8009EB80][i].v[3];
    car->sfx->b15 = D_8009EC6C[D_8009EB80][i].v[4];
    car->sfx->b17 = D_8009EC6C[D_8009EB80][i].v[5];
    car->sfx->b1B = D_8009EC6C[D_8009EB80][i].v[7];
    car->sfx->b1A = D_8009EC6C[D_8009EB80][i].v[6];
done:
    return 1;
}
