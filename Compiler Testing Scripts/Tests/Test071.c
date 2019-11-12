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
	int spl_a = 1, spl_b = 1, spl_c = 1;
	double spl_d = 1, spl_e = 1;
	char spl_f = 1, spl_g = 1;

	printf("%d", spl_a);
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
