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

void prg_ProgB()
{
	int spl_a = 1, spl_b = 1;
	char spl_c = 1;
	double spl_d = 1, spl_e = 1;

	_spl_read(" %d", &spl_a);
	_spl_read(" %d", &spl_b);
	if ((spl_a > spl_b))
	{
		printf("A");
	}
	else
	{
		printf("B");
	}
	printf("\n");
	_spl_read(" %lf", &spl_d);
	spl_e = (spl_d * 2.300000);
	printf("%lf", spl_e);
	printf("\n");
	_spl_read(" %c", &spl_c);
	printf("%c", spl_c);
	printf("\n");
}

int main()
{
	prg_ProgB();
	return 0;
}
