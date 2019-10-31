#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Prog4D()
{
	double spl_r1, spl_r2, spl_r3;

	spl_r1 = -2.400000;
	spl_r2 = -34.989000;
	spl_r3 = ((spl_r1 * spl_r2) / 7.400000);
	printf("%lf", spl_r3);
	printf("\n");
	scanf("%lf", &spl_r1);
	_spl_flush_stdin();
	spl_r3 = (spl_r1 + spl_r3);
	printf("%lf", spl_r3);
	printf("\n");
}

int main()
{
	spl_Prog4D();
	return 0;
}
