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
	double spl_a = 1;

	int _spl_real_by = 0.100000;
	for (spl_a = 0.100000; _spl_real_by < 0 ? spl_a >= 0.500000 : spl_a <= 0.500000; spl_a += _spl_real_by)
	{
		printf("%lf", spl_a);
		printf("\n");
		_spl_real_by = 0.100000;
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
