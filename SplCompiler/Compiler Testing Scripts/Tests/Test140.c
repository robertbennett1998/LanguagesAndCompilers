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
	if (!((spl_a == spl_a)))
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
/*WARNING (20:10): spl_b is declared and is assigned to but never used!*/
