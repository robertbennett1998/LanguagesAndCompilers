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

	spl_a = (1 + 1);
	printf("%d", spl_a);
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (16:10): spl_b is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_c is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_d is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_e is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_f is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_g is declared but is neither assigned to or used!*/
