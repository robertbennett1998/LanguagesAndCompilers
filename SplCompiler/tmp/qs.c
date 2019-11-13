#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void _spl_read(const char* pFormat, void* pValue)
{
	while (scanf(pFormat, pValue) != 1)
	{
		getchar();
	};
	_spl_flush_stdin();
}

void prg_QuadraticSolver()
{
	char spl_space = 1, spl_period = 1, spl_bra = 1, spl_ket = 1, spl_carot = 1, spl_plus = 1, spl_minus = 1;
	double spl_rA = 1, spl_rB = 1, spl_rC = 1, spl_rDiscriminent = 1, spl_rSqrtDiscriminent = 1, spl_rAlpha = 1, spl_rBeta = 1, spl_rValue = 1, spl_rStep = 1, spl_rPrescision = 1, spl_rAlphaImaginary = 1, spl_rBetaImaginary = 1;

	spl_space = 32;
	spl_period = 46;
	spl_bra = 40;
	spl_ket = 41;
	spl_carot = 94;
	spl_plus = 43;
	spl_minus = 45;
	spl_rPrescision = 0.000000;
	printf("Welcome%cto%cthe%cquadratic%csolver%cimplemented%cin%cspl%c%cNote%cthis%cwill%cnot%chandle%cquadratics%cwith%cimaginary%croots%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	printf("Quadratics%care%cin%cthe%cform%ca%c2x%c%c%cbx%c%c%cc%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_carot, spl_space, spl_plus, spl_space, spl_space, spl_plus, spl_space, spl_period);
	printf("\n");
	printf("\n");
	printf("Please%center%cthe%cfirst%ccoefficient%c%ca%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	_spl_read(" %lf", &spl_rA);
	printf("Please%center%cthe%csecond%ccoefficient%c%cb%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	_spl_read(" %lf", &spl_rB);
	printf("Please%center%cthe%cthird%ccoefficient%c%cc%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	_spl_read(" %lf", &spl_rC);
	spl_rDiscriminent = ((spl_rB * spl_rB) - ((4 * spl_rA) * spl_rC));
	if ((spl_rDiscriminent == 0))
	{
		spl_rAlpha = ((0 - spl_rB) / (2 * spl_rA));
		printf("Alpha%cis%c%f", spl_space, spl_space, spl_rAlpha);
		printf("\n");
		printf("Beta%cis%c%f", spl_space, spl_space, spl_rAlpha);
	}
	else
	{
		if ((spl_rDiscriminent < 0))
		{
			spl_rDiscriminent = (-1 * spl_rDiscriminent);
			spl_rSqrtDiscriminent = spl_rDiscriminent;
			while (((spl_rSqrtDiscriminent - spl_rStep) > spl_rPrescision))
			{
				spl_rSqrtDiscriminent = ((spl_rSqrtDiscriminent + spl_rStep) / 2);
				spl_rStep = (spl_rDiscriminent / spl_rSqrtDiscriminent);
			};
			spl_rAlpha = ((0 - spl_rB) / (2 * spl_rA));
			spl_rAlphaImaginary = (spl_rSqrtDiscriminent / (2 * spl_rA));
			spl_rBetaImaginary = (spl_rSqrtDiscriminent / (2 * spl_rA));
			printf("Alpha%cis%c%f%c%c%c%fi", spl_space, spl_space, spl_rAlpha, spl_space, spl_plus, spl_space, spl_rAlphaImaginary);
			printf("\n");
			printf("Beta%cis%c%f%c%c%c%fi", spl_space, spl_space, spl_rAlpha, spl_space, spl_minus, spl_space, spl_rBetaImaginary);
		}
		else
		{
			spl_rSqrtDiscriminent = spl_rDiscriminent;
			while (((spl_rSqrtDiscriminent - spl_rStep) > spl_rPrescision))
			{
				spl_rSqrtDiscriminent = ((spl_rSqrtDiscriminent + spl_rStep) / 2);
				spl_rStep = (spl_rDiscriminent / spl_rSqrtDiscriminent);
			};
			spl_rAlpha = (((0 - spl_rB) + spl_rSqrtDiscriminent) / (2 * spl_rA));
			spl_rBeta = (((0 - spl_rB) - spl_rSqrtDiscriminent) / (2 * spl_rA));
			printf("Alpha%cis%c%f", spl_space, spl_space, spl_rAlpha);
			printf("\n");
			printf("Beta%cis%c%f", spl_space, spl_space, spl_rBeta);
		}
	}
}

int main()
{
	prg_QuadraticSolver();
	return 0;
}
