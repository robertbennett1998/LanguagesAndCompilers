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

void prg_read()
{
	int spl_int = 1;
	double spl_real = 1;
	char spl_char = 1, spl_char2 = 1;
	char spl_space = 1, spl_period = 1;

	spl_space = 32;
	spl_period = 46;
	printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	_spl_read("%d", &spl_int);
	printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	_spl_read("%lf", &spl_real);
	printf("Please%center%ca%ccharacter%c", spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	_spl_read(" %c", &spl_char);
	printf("Please%center%ca%ccharacter%c", spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	_spl_read(" %c", &spl_char2);
	printf("\n");
	printf("%d", spl_int);
	printf("\n");
	printf("%lf", spl_real);
	printf("\n");
	printf("%c", spl_char);
	printf("\n");
	printf("%c", spl_char2);
}

int main()
{
	prg_read();
	return 0;
}
