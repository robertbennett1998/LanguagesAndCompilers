#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_ProgV()
{
	int spl_integer = 1, spl_i = 1;

	while (scanf("%d", &spl_integer) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
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
	prg_ProgV();
	return 0;
}
