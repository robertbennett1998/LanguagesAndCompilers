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
	int spl_a;

	spl_a = 1;
	if ((spl_a < 0))
	{
		printf("%d", spl_a);
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
