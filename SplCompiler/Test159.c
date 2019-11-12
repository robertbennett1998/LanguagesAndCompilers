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

	{
		while (scanf("%lf", &spl_a) != 1)
		{
			char c = getchar();
			if (c == '\n' || c == ' ' || c == EOF)
			{
				break;
			}
			_spl_flush_stdin();
		}
		printf("%lf", spl_a);
		printf("\n");
}

int main()
{
	prg_Test();
	return 0;
}
