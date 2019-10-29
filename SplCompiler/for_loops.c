/*WARNING (8:24): spl_a is used before it has been assigned to, this will have unexpected consequences!*/
/*WARNING (13:24): spl_b is used before it has been assigned to, this will have unexpected consequences!*/
#include <stdio.h>

void spl_ForLoops()
{
	char spl_a;
	int spl_b;
	double spl_c;

	for (spl_a = 'a'; spl_a != 'Z'; spl_a += ('c' - 'a'))
	{
		printf("%c", spl_a);
		printf("\n");
	}
	printf("\n");
	for (spl_b = 0; spl_b != 10; spl_b += 2)
	{
		printf("%d", spl_b);
		printf("\n");
	}
}

int main()
{
	spl_ForLoops();
	return 0;
}
/*WARNING (17:1): spl_a is declared and is assigned to but never used!*/
/*WARNING (17:1): spl_b is declared and is assigned to but never used!*/
/*WARNING (17:1): spl_c is declared but is neither assigned to or used!*/
