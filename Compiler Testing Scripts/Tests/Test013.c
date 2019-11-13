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

void prg_Test13()
{
	int spl_a = 1;
	double spl_b = 1;
	char spl_c = 1;

	printf("\n");
}

int main()
{
	prg_Test13();
	return 0;
}
