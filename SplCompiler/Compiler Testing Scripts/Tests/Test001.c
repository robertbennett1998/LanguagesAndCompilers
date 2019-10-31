#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test1()
{
	printf("\n");
}

int main()
{
	spl_Test1();
	return 0;
}
