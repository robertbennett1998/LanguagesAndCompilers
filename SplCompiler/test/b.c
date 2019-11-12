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

void prg_ProgB()
{
	int spl_a = 1, spl_b = 1;
	char spl_c = 1;
	double spl_d = 1, spl_e = 1;

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
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%d", &spl_b) != 1)
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
	if ((spl_a > spl_b))
	{
		printf("A");
	}
	else
	{
		printf("B");
	}
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%lf", &spl_d) != 1)
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
	spl_e = (spl_d * 2.300000);
	printf("%lf", spl_e);
	printf("\n");
	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf(" %c", &spl_c) != 1)
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
	printf("%c", spl_c);
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_ProgB();
	return 0;
}
