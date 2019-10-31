#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_ProgB()
{
	int spl_a, spl_b;
	char spl_c;
	double spl_d, spl_e;

	scanf("%d", &spl_a);
	_spl_flush_stdin();
	scanf("%d", &spl_b);
	_spl_flush_stdin();
	if (spl_a > spl_b)
	{
		printf("A");
	}
	else
	{
		printf("B");
	}
	printf("\n");
	scanf("%lf", &spl_d);
	_spl_flush_stdin();
	spl_e = (spl_d * 2.300000);
	printf("%lf", spl_e);
	printf("\n");
	scanf("%c", &spl_c);
	_spl_flush_stdin();
	printf("%c", spl_c);
	printf("\n");
}

int main()
{
	spl_ProgB();
	return 0;
}
