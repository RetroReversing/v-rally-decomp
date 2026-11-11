typedef union
{
	struct
	{
		unsigned int hi;
		unsigned int lo;
	} word;

	double	d;
} du;

typedef union
{
	unsigned int	i;
	float		f;
} fu;

extern float D_800A6E80;

/* Polynomial coefficients for cos on [-pi/4, pi/4] and pi split into hi and lo parts. */
static const du P[] =
{
{0x3ff00000,	0x00000000},
{0xbfc55554,	0xbc83656d},
{0x3f8110ed,	0x3804c2a0},
{0xbf29f6ff,	0xeea56814},
{0x3ec5dbdf,	0x0e314bfe},
};

static const du rpi =
{0x3fd45f30,	0x6dc9c883};

static const du pihi =
{0x400921fb,	0x50000000};

static const du pilo =
{0x3e6110b4,	0x611a6263};

static const fu zero = {0x00000000};

/* Single-precision cosine: reduces x to [-pi/4, pi/4] and evaluates a polynomial.
   NaN returns D_800A6E80; large |x| returns zero. */
float __cosf(float x)
{
    float abs_x;
    double reduced, x_sq, poly;
    double quadrant_f;
    int quadrant;
    double result;
    int bits, exponent;

    bits = *(int *)&x;
    exponent = (bits >> 22);
    exponent &= 0x1ff;

    if (exponent < 0x136)
    {
        abs_x = ((x) > 0) ? (x) : -(x);

        reduced = abs_x;

        quadrant_f = reduced * rpi.d + 0.5;
        quadrant = (int)(((quadrant_f) >= 0.0) ? ((quadrant_f) + 0.5) : ((quadrant_f) - 0.5));
        quadrant_f = quadrant;

        quadrant_f -= 0.5;

        reduced = reduced - quadrant_f * pihi.d;
        reduced = reduced - quadrant_f * pilo.d;

        x_sq = reduced * reduced;

        poly = ((P[4].d * x_sq + P[3].d) * x_sq + P[2].d) * x_sq + P[1].d;

        result = reduced + (reduced * x_sq) * poly;

        if ((quadrant & 1) == 0)
            return ((float)result);

        return (-(float)result);
    }

    if (x != x)
    {
        return (D_800A6E80);
    }

    return (zero.f);
}
