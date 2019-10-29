#include <stdio.h>

void spl_ProgV()
{
	int spl_integer, spl_i, spl_b;

	scanf("%i", &spl_integer);
	if (((spl_integer <= 5) || (spl_integer >= 12)))
	{
		printf("%d", spl_integer);
	}
	spl_b = (36 - 1);
	printf("[Evaluate_OutputList_Format_Expression: Expression]", [Evaluate_OutputList_Format: Expression]);
	printf("\n");
	for (spl_integer = -1; spl_integer <= -5; spl_integer += -1)
	{
		printf("%d", spl_integer);
		printf("\n");
	}
	spl_i = -1;
	for (spl_integer = ((spl_i * spl_i) * spl_i); spl_integer <= ((spl_i * spl_i) * ((((spl_i + spl_i) + spl_i) + spl_i) + spl_i)); spl_integer += ((((spl_i * spl_i) * spl_i) * spl_i) * spl_i))
	{
		printf("%d", spl_integer);
		printf("\n");
	}
}

int main()
{
	spl_ProgV();
	return 0;
}
/*WARNING (31:1): spl_integer is declared and is assigned to but never used!
*/
/*WARNING (31:1): spl_b is declared and is assigned to but never used!
*/
