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
	char spl_a = 1;

	_spl_read(" %c", &spl_a);
	printf("%c", spl_a);
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
