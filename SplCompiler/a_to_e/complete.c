#include <stdio.h>

void spl_ProgComplete()
{
	int spl_a, spl_b, spl_c;
	char spl_d, spl_e, spl_f;
	float spl_g, spl_h, spl_i;

	scanf("%i", &spl_a);
	spl_b = 2;
	spl_c = (spl_b + spl_a);
	spl_d = 'a';
	spl_e = 'b';
	spl_f = (spl_e + 1);
	spl_g = (spl_a / spl_c);
	spl_h = (spl_g * 2);
	spl_i = 2.300000f;
	printf("%d%d%d%c%c%c%f%f%f", spl_a, spl_b, spl_c, spl_d, spl_e, spl_f, spl_g, spl_h, spl_i);
	if (spl_a == 1)
	{
		printf("%d", spl_a);
		printf("\n");
	}
	if (spl_c == (spl_a + spl_b))
	{
		printf("%dEQUALS%dPLUS%d", spl_c, spl_a, spl_b);
		printf("\n");
	}
	else
	{
		printf("%dNOTEQUAL%dPLUS%d", spl_c, spl_a, spl_b);
		printf("\n");
	}
	printf("\n");
	for (spl_a = 1; spl_a <= 13; spl_a += 1)
	{
		printf("%d", spl_a);
		printf("\n");
	}
	printf("\n");
	spl_a = 1;
	while (((spl_a <= 13) && (!(spl_a > 14))))
	{
		printf("%d", spl_a);
		printf("\n");
		spl_a = (spl_a + 1);
	};
	printf("\n");
	spl_a = 1;
	do
	{
		printf("%d", spl_a);
		printf("\n");
		spl_a = (spl_a + 1);
	} while (!(spl_a > 13));
	printf("\n");
	printf("hello%d", spl_a);
	printf("\n");
}

int main()
{
	spl_ProgComplete();
	return 0;
}
