#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Test()
{
	double spl_a = 1;

	spl_a = (3.200000 * 1.300000);
	printf("%lf", spl_a);
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
