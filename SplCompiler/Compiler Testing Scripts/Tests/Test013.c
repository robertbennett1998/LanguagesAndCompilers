#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test13()
{
	int spl_a = 1;
	double spl_b = 1;
	char spl_c = 1;

	printf("\n");
}

int main()
{
	spl_Test13();
	return 0;
}
