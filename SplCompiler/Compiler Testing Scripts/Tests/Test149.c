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
	int spl_a;

	spl_a = 1;
	while (spl_a <= 0)
	{
		printf("%d", spl_a);
		spl_a = (spl_a + 1);
	};
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (17:10): spl_a is declared and is assigned to but never used!*/
