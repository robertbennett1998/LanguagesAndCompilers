#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_Limits()
{
	int spl_int = 1;
	char spl_char = 1;
	double spl_real = 1;

	while (scanf("%d", &spl_int) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("\n");
	while (scanf(" %c", &spl_char) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("\n");
	while (scanf("%lf", &spl_real) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("\n");
	printf("\n");
	printf("%c", (char)((spl_int + spl_int) + spl_char));
	printf("\n");
	printf("%c", (char)(spl_int + spl_char));
	printf("\n");
	printf("%c", (char)(spl_char + spl_int));
	printf("\n");
	printf("%lf", (double)(spl_real + spl_int));
	printf("\n");
	printf("%lf", (double)(spl_int + spl_real));
	printf("\n");
	printf("%lf", (double)(spl_char + spl_real));
	printf("\n");
	printf("%lf", (double)(spl_real + spl_char));
	printf("\n");
	printf("%lf", (double)((spl_int + spl_char) + spl_real));
	printf("\n");
	printf("%lf", (double)((spl_char + spl_int) + spl_real));
	printf("\n");
	printf("%lf", (double)((spl_int + spl_real) + spl_char));
	printf("\n");
	printf("%lf", (double)((spl_real + spl_char) + spl_int));
}

int main()
{
	prg_Limits();
	return 0;
}
