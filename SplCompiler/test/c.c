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

void prg_Prog3()
{
	int spl_a = 1;

	for (spl_a = 1; 1 < 0 ? spl_a >= 13 : spl_a <= 13; spl_a += 1)
	{
		if (!((spl_a == 7)))
		{
			printf("%d", spl_a);
			printf("\n");
		}
	}
	spl_a = 0;
	do
	{
		spl_a = (spl_a + 1);
		if (((!((spl_a == 6))) && ((spl_a != 8))))
		{
			printf("%d", spl_a);
			printf("\n");
		}
	} while ((spl_a < 14));
	spl_a = 0;
	while ((spl_a < 12))
	{
		printf("%d", spl_a);
		spl_a = (spl_a + 1);
	};
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_Prog3();
	return 0;
}
