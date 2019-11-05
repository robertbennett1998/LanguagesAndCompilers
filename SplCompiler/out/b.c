#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_ProgB()
{
	int spl_a = 1, spl_b = 1;
	char spl_c = 1;
	double spl_d = 1, spl_e = 1;

	while (scanf("%d", &spl_a) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	while (scanf("%d", &spl_b) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	if ((spl_a > spl_b))
	{
		printf("A");
	}
	else
	{
		printf("B");
	}
	printf("\n");
	while (scanf("%lf", &spl_d) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	spl_e = (spl_d * 2.300000);
	printf("%lf", spl_e);
	printf("\n");
	while (scanf(" %c", &spl_c) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("%c", spl_c);
	printf("\n");
}

int main()
{
	prg_ProgB();
	return 0;
}
