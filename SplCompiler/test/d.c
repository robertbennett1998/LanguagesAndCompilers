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

void prg_Prog4D()
{
	double spl_r1 = 1, spl_r2 = 1, spl_r3 = 1;

	spl_r1 = -2.400000;
	spl_r2 = -34.989000;
	spl_r3 = ((spl_r1 * spl_r2) / 7.400000);
	printf("%lf", spl_r3);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%lf", &spl_r1) != 1)
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
	spl_r3 = (spl_r1 + spl_r3);
	printf("%lf", spl_r3);
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_Prog4D();
	return 0;
}
