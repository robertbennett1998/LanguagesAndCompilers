/*WARNING (9:17): spl_a is used before it has been assigned to, this will have unexpected consequences!*/
/*WARNING (10:18): spl_a is used before it has been assigned to, this will have unexpected consequences!*/
#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Prog3()
{
	int spl_a;

	int _spl_integer_by = 1;
	for (spl_a = 1; _spl_integer_by < 0 ? spl_a >= 13 : spl_a <= 13; spl_a += _spl_integer_by)
	{
		if (!(spl_a == 7))
		{
			printf("%d", spl_a);
			printf("\n");
		}
		_spl_integer_by = 1;
	}
	spl_a = 0;
	do
	{
		spl_a = (spl_a + 1);
		if (((!(spl_a == 6)) && (spl_a != 8)))
		{
			printf("%d", spl_a);
			printf("\n");
		}
	} while (spl_a < 14);
	spl_a = 0;
	while (spl_a < 12)
	{
		printf("%d", spl_a);
		spl_a = (spl_a + 1);
	};
	printf("\n");
}

int main()
{
	spl_Prog3();
	return 0;
}
/*WARNING (29:1): spl_a is declared and is assigned to but never used!*/
