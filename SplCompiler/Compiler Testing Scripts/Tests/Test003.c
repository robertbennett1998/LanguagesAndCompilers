#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test3()
{
	printf("\n");
}

int main()
{
	spl_Test3();
	return 0;
}
