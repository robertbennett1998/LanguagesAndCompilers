#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test()
{
	double spl_a;

	spl_a = (3.200000 - 1.300000);
	printf("%lf", spl_a);
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
