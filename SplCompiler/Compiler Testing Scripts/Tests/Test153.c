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
	int spl_a = 1;

	int _spl_integer_by = 1;
	for (spl_a = 1; _spl_integer_by < 0 ? spl_a >= 0 : spl_a <= 0; spl_a += _spl_integer_by)
	{
		printf("%d", spl_a);
		_spl_integer_by = 1;
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
