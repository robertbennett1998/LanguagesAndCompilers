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
	double spl_a = 1;

	for (spl_a = 0.100000; 0.100000 < 0 ? spl_a >= 0.500000 : spl_a <= 0.500000; spl_a += 0.100000)
	{
		printf("%lf", spl_a);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
