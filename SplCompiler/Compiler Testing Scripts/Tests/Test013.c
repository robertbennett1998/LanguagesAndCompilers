#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test13()
{
	int spl_a;
	double spl_b;
	char spl_c;

	printf("\n");
}

int main()
{
	spl_Test13();
	return 0;
}
/*WARNING (15:2): spl_a is declared but is neither assigned to or used!*/
/*WARNING (15:2): spl_b is declared but is neither assigned to or used!*/
/*WARNING (15:2): spl_c is declared but is neither assigned to or used!*/
