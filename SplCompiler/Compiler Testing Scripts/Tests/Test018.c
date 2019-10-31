#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test18()
{
	int spl_a, spl_b, spl_c;
	double spl_d, spl_e;
	char spl_f;

	spl_f = 'x';
	printf("\n");
}

int main()
{
	spl_Test18();
	return 0;
}
/*WARNING (17:2): spl_a is declared but is neither assigned to or used!*/
/*WARNING (17:2): spl_b is declared but is neither assigned to or used!*/
/*WARNING (17:2): spl_c is declared but is neither assigned to or used!*/
/*WARNING (17:2): spl_d is declared but is neither assigned to or used!*/
/*WARNING (17:2): spl_e is declared but is neither assigned to or used!*/
/*WARNING (17:2): spl_f is declared and is assigned to but never used!*/
