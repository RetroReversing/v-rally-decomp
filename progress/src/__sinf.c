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

extern float	D_800A6E80;

static const du	sin_poly[] =
{
{0x3ff00000,	0x00000000},
{0xbfc55554,	0xbc83656d},
{0x3f8110ed,	0x3804c2a0},
{0xbf29f6ff,	0xeea56814},
{0x3ec5dbdf,	0x0e314bfe},
};

static const du	inv_pi =
{0x3fd45f30,	0x6dc9c883};

static const du	pi_hi =
{0x400921fb,	0x50000000};

static const du	pi_lo =
{0x3e6110b4,	0x611a6263};

static const fu	zero_f = {0x00000000};

/* Sine of a float angle in radians. Angles below 1 use the polynomial directly
   (tiny ones return the angle). Larger finite angles are reduced to the nearest
   multiple of pi, and odd multiples flip the sign. NaN returns D_800A6E80;
   infinity returns zero. */
float
__sinf ( float angle )
{
double	arg, arg_sq, poly;
double	quotient;
int	n;
double	result;
int	bits, exponent;


	bits = *(int *)&angle;
	exponent = (bits >> 22);
	exponent &= 0x1ff;

	if ( exponent < 0xff )
	{
		arg = angle;

		/* below about 2^-12 the sine rounds to the angle itself */
		if ( exponent >= 0xe6 )
		{
			/* sin(x) ~= x + x^3 * poly(x^2) */
			arg_sq = arg*arg;

			poly = ((sin_poly[4].d*arg_sq + sin_poly[3].d)*arg_sq + sin_poly[2].d)*arg_sq + sin_poly[1].d;

			result = arg + (arg*arg_sq)*poly;

			return ( (float)result );
		}

		return ( angle );
	}

	/* larger finite angles: reduce to the nearest multiple of pi */
	if ( exponent < 0x136 )
	{
		arg = angle;

		/* quotient = round(angle / pi) */
		quotient = arg*inv_pi.d;

		n = (int)((( quotient ) >= 0.0) ? (( quotient ) + 0.5) : (( quotient ) - 0.5)) ;
		quotient = n;

		/* subtract n*pi in two parts for extra precision */
		arg = arg - quotient*pi_hi.d;
		arg = arg - quotient*pi_lo.d;

		arg_sq = arg*arg;

		poly = ((sin_poly[4].d*arg_sq + sin_poly[3].d)*arg_sq + sin_poly[2].d)*arg_sq + sin_poly[1].d;

		result = arg + (arg*arg_sq)*poly;

		/* odd multiples of pi flip the sign */
		if ( (n & 1) == 0 )
			return ( (float)result );

		return ( -(float)result );
	}

	/* NaN input */
	if ( angle != angle )
	{
		return ( D_800A6E80 );
	}

	/* infinity: return zero */
	return ( zero_f.f );
}
