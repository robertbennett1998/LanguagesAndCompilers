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

void prg_AssignmentOptimisation()
{
	int spl_a = 1;
	char spl_b = 1;
	double spl_c = 1;

	spl_a = 2;
	printf("%d", spl_a);
	printf("\n");
	spl_a = 3;
	spl_a = (spl_a + 1);
	printf("%d", spl_a);
	printf("\n");
	spl_a = 5;
	printf("%d", spl_a);
	printf("\n");
	spl_a = 7;
	printf("%d", spl_a);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%d", &spl_a) != 1)
		{
			char c = getchar();
			if (c == '\n' || c == ' ' || c == EOF)
			{
				break;
			}
			if (_spl_bDiscardedCharsFlag == 0)
			{
				fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
				_spl_bDiscardedCharsFlag = 1;
			}
			fprintf(stderr,"%c", c);
		};
		_spl_flush_stdin();
	}
	spl_a = (spl_a + 1);
	spl_a = (spl_a + 1);
	printf("%d", spl_a);
	printf("\n");
	spl_b = (87 + spl_a);
	printf("%c", spl_b);
	printf("\n");
	spl_b = 'b';
	printf("%c", spl_b);
	printf("\n");
	spl_c = 4.560000;
	printf("%lf", spl_c);
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_AssignmentOptimisation();
	return 0;
}
