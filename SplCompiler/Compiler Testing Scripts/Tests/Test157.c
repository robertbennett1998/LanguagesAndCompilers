/*WARNING (9:17): spl_a is used before it has been assigned to, this will have unexpected consequences!*/
#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_Test()
{
	char spl_a;

	int _spl_character_by = 1;
	for (spl_a = 'a'; _spl_character_by < 0 ? spl_a >= 'g' : spl_a <= 'g'; spl_a += _spl_character_by)
	{
		printf("%c", spl_a);
		_spl_character_by = 1;
	}
	printf("\n");
}

int main()
{
	spl_Test();
	return 0;
}
/*WARNING (15:10): spl_a is declared and is assigned to but never used!*/
