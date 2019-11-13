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

void prg_Prog4D()
{
	double spl_r1 = 1, spl_r2 = 1, spl_r3 = 1;

	spl_r1 = -2.400000;
	spl_r2 = -34.989000;
	spl_r3 = ((spl_r1 * spl_r2) / 7.400000);
	printf("%lf", spl_r3);
	printf("\n");
	_spl_read(" %lf", &spl_r1);
	spl_r3 = (spl_r1 + spl_r3);
	printf("%lf", spl_r3);
	printf("\n");
}

int main()
{
	prg_Prog4D();
	return 0;
}
