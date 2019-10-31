#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test36()
{
	int spl_a, spl_b, spl_c;
	double spl_Test36, spl_e;
	char spl_f;

	spl_a = 1;
	printf("\n");
}

int main()
{
	spl_Test36();
	return 0;
}
/*WARNING (16:12): spl_a is declared and is assigned to but never used!*/
/*WARNING (16:12): spl_b is declared but is neither assigned to or used!*/
/*WARNING (16:12): spl_c is declared but is neither assigned to or used!*/
/*WARNING (16:12): spl_e is declared but is neither assigned to or used!*/
/*WARNING (16:12): spl_f is declared but is neither assigned to or used!*/
