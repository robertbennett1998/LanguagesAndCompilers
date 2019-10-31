#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_ProgV()
{
	int spl_integer, spl_i;

	scanf("%d", &spl_integer);
	_spl_flush_stdin();
	if (((spl_integer <= 5) || (spl_integer >= 12)))
	{
		printf("%d", spl_integer);
	}
	printf("%d", (int)(36 - 1));
	printf("\n");
	int _spl_integer_by = -1;
	for (spl_integer = -1; _spl_integer_by < 0 ? spl_integer >= -5 : spl_integer <= -5; spl_integer += _spl_integer_by)
	{
		printf("%d", spl_integer);
		printf("\n");
		_spl_integer_by = -1;
	}
	spl_i = -1;
	_spl_integer_by = ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i);
	for (spl_integer = ((spl_i * spl_i) * spl_i); _spl_integer_by < 0 ? spl_integer >= ((spl_i * spl_i) * ((((spl_i + spl_i) + spl_i) + spl_i) + spl_i)) : spl_integer <= ((spl_i * spl_i) * ((((spl_i + spl_i) + spl_i) + spl_i) + spl_i)); spl_integer += _spl_integer_by)
	{
		printf("%d", spl_integer);
		printf("\n");
		_spl_integer_by = ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i);
	}
}

int main()
{
	spl_ProgV();
	return 0;
}
/*WARNING (29:1): spl_integer is declared and is assigned to but never used!*/
