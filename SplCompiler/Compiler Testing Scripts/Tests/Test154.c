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
	int spl_a = 1;

	int _spl_integer_by = 1;
	for (spl_a = -5; _spl_integer_by < 0 ? spl_a >= 5 : spl_a <= 5; spl_a += _spl_integer_by)
	{
		printf("%d", spl_a);
		_spl_integer_by = 1;
	}
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
