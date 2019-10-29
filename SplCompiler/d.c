#include <stdio.h>

void spl_Prog4D()
{
	float spl_r1, spl_r2, spl_r3;

	spl_r1 = -2.400000f;
	spl_r2 = -34.988998f;
	spl_r3 = ((spl_r1 * spl_r2) / 7.400000f);
	printf("%f", spl_r3);
	printf("\n");
	scanf("%f", &spl_r1);
	spl_r3 = (spl_r1 + spl_r3);
	printf("%f", spl_r3);
	printf("\n");
}

int main()
{
	spl_Prog4D();
	return 0;
}
