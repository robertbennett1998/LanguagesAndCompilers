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

	spl_a = 1;
	spl_d = 3.141590;
	spl_f = 'x';
	printf("1%d", spl_a);
	printf("\n");
	printf("%lf", spl_d);
	printf("\n");
	printf("1%c", spl_f);
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (22:10): spl_b is declared but is neither assigned to or used!*/
/*WARNING (22:10): spl_c is declared but is neither assigned to or used!*/
/*WARNING (22:10): spl_e is declared but is neither assigned to or used!*/
/*WARNING (22:10): spl_g is declared but is neither assigned to or used!*/
