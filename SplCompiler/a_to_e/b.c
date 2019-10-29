#include <stdio.h>

void spl_ProgB()
{
	int spl_a, spl_b;
	char spl_c;
	float spl_d, spl_e;

	scanf("%i", &spl_a);
	scanf("%i", &spl_b);
	if (spl_a > spl_b)
	{
		printf("A");
	}
	else
	{
		printf("B");
	}
	printf("\n");
	scanf("%f", &spl_d);
	spl_e = (spl_d * 2.300000f);
	printf("%f", spl_e);
	printf("\n");
	scanf("%c", &spl_c);
	printf("%c", spl_c);
	printf("\n");
}

int main()
{
	spl_ProgB();
	return 0;
}
