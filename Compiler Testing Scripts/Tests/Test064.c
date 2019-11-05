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
	int spl_a = 1, spl_b = 1, spl_c = 1;
	double spl_d = 1, spl_e = 1;
	char spl_f = 1, spl_g = 1;

	printf("1");
	printf("\n");
	printf("3.141590");
	printf("\n");
	printf("x");
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_Test();
	return 0;
}
