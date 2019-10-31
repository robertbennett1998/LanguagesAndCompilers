#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test2()
{
	printf("\n");
}

int main()
{
	spl_Test2();
	return 0;
}
