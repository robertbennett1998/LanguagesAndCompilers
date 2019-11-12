#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
	do
	{
		c = getchar();
		if (c != EOF)
		{
			fprintf(stderr,"%c", c);
		}
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_QuadraticSolver()
{
	char spl_space = 1, spl_period = 1, spl_bra = 1, spl_ket = 1, spl_carot = 1, spl_plus = 1;
	double spl_rA = 1, spl_rB = 1, spl_rC = 1, spl_rDiscriminent = 1, spl_rSqrtDiscriminent = 1, spl_rAlpha = 1, spl_rBeta = 1, spl_rValue = 1, spl_rStep = 1, spl_rPrescision = 1, spl_rAlphaImaginary = 1, spl_rBetaImaginary = 1;

	spl_space = 32;
	spl_period = 46;
	spl_bra = 40;
	spl_ket = 41;
	spl_carot = 94;
	spl_plus = 43;
	spl_rPrescision = 0.000000;
	printf("Welcome%cto%cthe%cquadratic%csolver%cimplemented%cin%cspl%c%cNote%cthis%cwill%cnot%chandle%cquadratics%cwith%cimaginary%croots%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	printf("Quadratics%care%cin%cthe%cform%ca%c2x%c%c%cbx%c%c%cc%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_carot, spl_space, spl_plus, spl_space, spl_space, spl_plus, spl_space, spl_period);
	printf("\n");
	printf("\n");
	printf("Please%center%cthe%cfirst%ccoefficient%c%ca%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%lf", &spl_rA) != 1)
		{
			char c = getchar();
			if (c == '\n' || c == ' ' || c == EOF)
			{
				break;
			}
			if (_spl_bDiscardedCharsFlag == 0)
			{
				fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
				_spl_bDiscardedCharsFlag = 1;
			}
			fprintf(stderr,"%c", c);
		};
		_spl_flush_stdin();
	}
	printf("Please%center%cthe%csecond%ccoefficient%c%cb%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%lf", &spl_rB) != 1)
		{
			char c = getchar();
			if (c == '\n' || c == ' ' || c == EOF)
			{
				break;
			}
			if (_spl_bDiscardedCharsFlag == 0)
			{
				fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
				_spl_bDiscardedCharsFlag = 1;
			}
			fprintf(stderr,"%c", c);
		};
		_spl_flush_stdin();
	}
	printf("Please%center%cthe%cthird%ccoefficient%c%cc%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%lf", &spl_rC) != 1)
		{
			char c = getchar();
			if (c == '\n' || c == ' ' || c == EOF)
			{
				break;
			}
			if (_spl_bDiscardedCharsFlag == 0)
			{
				fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
				_spl_bDiscardedCharsFlag = 1;
			}
			fprintf(stderr,"%c", c);
		};
		_spl_flush_stdin();
	}
	spl_rDiscriminent = ((spl_rB * spl_rB) - ((4 * spl_rA) * spl_rC));
	if ((spl_rDiscriminent == 0))
	{
		spl_rAlpha = ((0 - spl_rB) / (2 * spl_rA));
		printf("Alpha%cis%c%lf", spl_space, spl_space, spl_rAlpha);
		printf("\n");
		printf("Beta%cis%c%lf", spl_space, spl_space, spl_rAlpha);
	}
	else
	{
		if ((spl_rDiscriminent < 0))
		{
			spl_rSqrtDiscriminent = (0 - spl_rDiscriminent);
			while (((spl_rSqrtDiscriminent - spl_rStep) > spl_rPrescision))
			{
				spl_rSqrtDiscriminent = ((spl_rSqrtDiscriminent + spl_rStep) / 2);
				spl_rStep = (spl_rDiscriminent / spl_rSqrtDiscriminent);
			};
			spl_rAlpha = ((0 - spl_rB) / (2 * spl_rA));
			spl_rAlphaImaginary = (spl_rSqrtDiscriminent / (2 * spl_rA));
			spl_rBetaImaginary = (spl_rSqrtDiscriminent / (2 * spl_rA));
			printf("Alpha%cis%c%lf%c%c%c%lfi", spl_space, spl_space, spl_rAlpha, spl_space, spl_plus, spl_space, spl_rAlphaImaginary);
			printf("\n");
			printf("Beta%cis%c%lf%c%c%c%lfi", spl_space, spl_space, spl_rAlpha, spl_space, spl_plus, spl_space, spl_rBetaImaginary);
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
			printf("Alpha%cis%c%lf", spl_space, spl_space, spl_rAlpha);
			printf("\n");
			printf("Beta%cis%c%lf", spl_space, spl_space, spl_rBeta);
		}
	}
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_QuadraticSolver();
	return 0;
}
