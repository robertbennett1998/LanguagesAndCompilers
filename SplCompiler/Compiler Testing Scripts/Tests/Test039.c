/*WARNING (10:8): spl_b is used before it has been assigned to, this will have unexpected consequences!*/
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
	char spl_f;

	spl_a = spl_b;
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (16:10): spl_a is declared and is assigned to but never used!*/
/*WARNING (16:10): spl_b is declared and used but never assigned to, this may have unexpected consequences!*/
/*WARNING (16:10): spl_c is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_d is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_e is declared but is neither assigned to or used!*/
/*WARNING (16:10): spl_f is declared but is neither assigned to or used!*/
