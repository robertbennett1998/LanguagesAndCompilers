#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Test()
{
	int spl_a = 1;

	while (scanf("%d", &spl_a) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("%d", spl_a);
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
