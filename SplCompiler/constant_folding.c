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

	for (spl_int = 6; 1 < 0 ? spl_int >= 10 : spl_int <= 10; spl_int += 1)
	{
		printf("%d", spl_int);
		printf("\n");
	}
	printf("%c", (char)'b');
	printf("\n");
	printf("%c", (char)'b');
	spl_int = 1;
	spl_int = (spl_int + 4);
	spl_real = 4.500000;
	spl_char = 'b';
}

int main()
{
	prg_ConstantFolding();
	return 0;
}
