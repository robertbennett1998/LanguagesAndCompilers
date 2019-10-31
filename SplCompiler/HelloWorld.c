#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void spl_HelloWorld()
{
	char spl_H, spl_e, spl_l, spl_o, spl_W, spl_r, spl_d, spl_a, spl_q, spl_break;

	spl_H = 'H';
	spl_e = 'e';
	spl_l = 'l';
	spl_o = 'o';
	spl_W = 'W';
	spl_r = 'r';
	spl_d = 'd';
	spl_a = 'a';
	spl_q = 'q';
	spl_break = ((spl_q - spl_a) + (spl_q - spl_a));
	printf("%c%c%c%c%c%c%c%c%c%c%c", spl_H, spl_e, spl_l, spl_l, spl_o, spl_break, spl_W, spl_o, spl_r, spl_l, spl_d);
	printf("\n");
}

int main()
{
	spl_HelloWorld();
	return 0;
}
