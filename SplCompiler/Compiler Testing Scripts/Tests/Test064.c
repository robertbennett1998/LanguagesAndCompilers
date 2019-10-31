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

	printf("1");
	printf("\n");
	printf("3.141590");
	printf("\n");
	printf("x");
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (19:10): spl_a is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_b is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_c is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_d is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_e is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_f is declared but is neither assigned to or used!*/
/*WARNING (19:10): spl_g is declared but is neither assigned to or used!*/
