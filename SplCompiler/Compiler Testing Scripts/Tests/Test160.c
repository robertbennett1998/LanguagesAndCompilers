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
	char spl_a = 1;

	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf(" %c", &spl_a) != 1)
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
	printf("%c", spl_a);
	printf("\n");
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_Test();
	return 0;
}
