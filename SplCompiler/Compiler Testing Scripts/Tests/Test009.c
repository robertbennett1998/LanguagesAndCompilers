#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test9()
{
	double spl_a;

	printf("\n");
}

int main()
{
	spl_Test9();
	return 0;
}
/*WARNING (12:11): spl_a is declared but is neither assigned to or used!*/
