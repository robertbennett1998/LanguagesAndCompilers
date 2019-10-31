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

	scanf("%d", &spl_a);
	_spl_flush_stdin();
	printf("%d", spl_a);
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
