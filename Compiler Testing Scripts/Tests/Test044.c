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

void prg_Test()
{
	int spl_a = 1, spl_b = 1, spl_c = 1;
	double spl_d = 1, spl_e = 1;
	char spl_f = 1, spl_g = 1;

	spl_d = 1.000000;
	spl_a = spl_d;
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
