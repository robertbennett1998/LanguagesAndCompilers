#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test10()
{
	char spl_a;

	printf("\n");
}

int main()
{
	spl_Test10();
	return 0;
}
/*WARNING (12:12): spl_a is declared but is neither assigned to or used!*/
