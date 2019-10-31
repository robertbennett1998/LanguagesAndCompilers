#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test8()
{
	int spl_a = 1;

	printf("\n");
}

int main()
{
	spl_Test8();
	return 0;
}
