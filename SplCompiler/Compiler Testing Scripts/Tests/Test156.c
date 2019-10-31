/*WARNING (9:17): spl_a is used before it has been assigned to, this will have unexpected consequences!*/
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
	double spl_a;

	int _spl_real_by = 0.100000;
	for (spl_a = 0.100000; _spl_real_by < 0 ? spl_a >= 0.500000 : spl_a <= 0.500000; spl_a += _spl_real_by)
	{
		printf("%lf", spl_a);
		printf("\n");
		_spl_real_by = 0.100000;
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (16:10): spl_a is declared and is assigned to but never used!*/
