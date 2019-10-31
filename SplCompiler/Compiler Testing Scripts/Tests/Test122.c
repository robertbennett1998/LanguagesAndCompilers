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
	int spl_b;

	spl_a = 1;
	spl_b = 2;
	if ((spl_a > spl_b))
	{
		printf("a");
		printf("\n");
	}
	else
	{
		printf("b");
		printf("\n");
	}
}

int main()
{
	spl_Test();
	return 0;
}
