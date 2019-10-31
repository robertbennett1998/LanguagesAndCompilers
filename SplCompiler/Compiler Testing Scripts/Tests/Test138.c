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
	int spl_a = 1;
	int spl_b = 1;

	spl_a = 1;
	spl_b = 2;
	if ((spl_a <= spl_a))
	{
		printf("y");
	}
	else
	{
		printf("n");
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
