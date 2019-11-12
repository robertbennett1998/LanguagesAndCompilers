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

void prg_ProgV()
{
	int spl_integer = 1, spl_i = 1;

	{
		char _spl_bDiscardedCharsFlag = 0;
		while (scanf("%d", &spl_integer) != 1)
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
	if ((((spl_integer <= 5)) || ((spl_integer >= 12))))
	{
		printf("%d", spl_integer);
	}
	printf("%d", (int)35);
	printf("\n");
	for (spl_integer = -1; -1 < 0 ? spl_integer >= -5 : spl_integer <= -5; spl_integer += -1)
	{
		printf("%d", spl_integer);
		printf("\n");
	}
	spl_i = -1;
	int _spl_integer_by = ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i);
	for (spl_integer = ((spl_i * spl_i) * spl_i); ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i) < 0 ? spl_integer >= ((spl_i * spl_i) * ((((spl_i + spl_i) + spl_i) + spl_i) + spl_i)) : spl_integer <= ((spl_i * spl_i) * ((((spl_i + spl_i) + spl_i) + spl_i) + spl_i)); spl_integer += _spl_integer_by)
	{
		printf("%d", spl_integer);
		printf("\n");
		_spl_integer_by = ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i);
	}
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_ProgV();
	return 0;
}
