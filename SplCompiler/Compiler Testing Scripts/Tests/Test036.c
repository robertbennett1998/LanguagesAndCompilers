#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Test36()
{
	int spl_a = 1, spl_b = 1, spl_c = 1;
	double prg_Test36 = 1, spl_e = 1;
	char spl_f = 1;

	spl_a = 1;
	printf("\n");
}

int main()
{
	prg_Test36();
	return 0;
}
