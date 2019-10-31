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
	int spl_a, spl_b, spl_c;
	double spl_d, spl_e;
	char spl_f, spl_g;

	spl_d = 1.000000;
	spl_e = spl_d;
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (17:10): spl_a is declared but is neither assigned to or used!*/
/*WARNING (17:10): spl_b is declared but is neither assigned to or used!*/
/*WARNING (17:10): spl_c is declared but is neither assigned to or used!*/
/*WARNING (17:10): spl_e is declared and is assigned to but never used!*/
/*WARNING (17:10): spl_f is declared but is neither assigned to or used!*/
/*WARNING (17:10): spl_g is declared but is neither assigned to or used!*/
