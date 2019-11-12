#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
	do
	{
		c = getchar();
		if (c != EOF)
		{
			fprintf(stderr,"%c", c);
		}
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Test()
{
	int spl_a = 1;
	int spl_b = 1;

	spl_a = 1;
	spl_b = 2;
	if ((spl_b < spl_a))
	{
		printf("y");
	}
	else
	{
		printf("n");
	}
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
