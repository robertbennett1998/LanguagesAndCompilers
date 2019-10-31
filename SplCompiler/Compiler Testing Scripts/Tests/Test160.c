#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test()
{
	char spl_a = 1;

	scanf(" %c", &spl_a);
	_spl_flush_stdin();
	printf("%c", spl_a);
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
