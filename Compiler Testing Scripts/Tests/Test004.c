#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Test4()
{
	printf("\n");
}

int main()
{
	prg_Test4();
	return 0;
}
