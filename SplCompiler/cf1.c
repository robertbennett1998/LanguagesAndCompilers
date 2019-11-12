#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_ConstantFolding()
{
	int spl_int = 1;
	double spl_real = 1;
	char spl_char = 1;

	int _spl_integer_by = ((1 + 1) - 1);
	for (spl_int = ((1 + 2) + 3); ((1 + 1) - 1) < 0 ? spl_int >= 10 : spl_int <= 10; spl_int += _spl_integer_by)
	{
		printf("%d", spl_int);
		printf("\n");
		_spl_integer_by = ((1 + 1) - 1);
	}
	printf("%c", (char)('a' + 1));
	printf("\n");
	printf("%c", (char)(1 + 'a'));
	spl_int = (((2 + 2) - ((4 * 2) / 2)) + 2);
	spl_int = (2 * 2);
	spl_int = (2 + 2);
	spl_int = (2 - 2);
	spl_int = (2 / 2);
	spl_int = (spl_int + (2 * 2));
	spl_real = (0.500000 * 5);
	spl_real = (2.500000 + 2.500000);
	spl_real = (2.500000 - 2.500000);
	spl_real = (1.250000 / 1.250000);
	spl_real = (2.500000 * 2);
	spl_real = (2.500000 - 2);
	spl_real = (2.500000 / 2);
	spl_real = (2.500000 + 2);
	spl_real = (2 * 2.500000);
	spl_real = (2 - 2.500000);
	spl_real = (2 / 0.500000);
	spl_real = (2 + 2.500000);
	spl_char = ('a' + 1);
	spl_char = ('c' - 1);
}

int main()
{
	prg_ConstantFolding();
	return 0;
}
