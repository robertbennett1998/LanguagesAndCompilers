Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: CHARACTER New Type: INTEGER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: CHARACTER New Type: INTEGER
Expression is const - Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: CHARACTER New Type: INTEGER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
char char (b) CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
int
Value: 0
Expression is const - Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: CHARACTER New Type: INTEGER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: CHARACTER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
Current Type: Unknown type New Type: INTEGER
int
Value: 0
#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_ConstantFolding()
{
	int spl_int = 1;
	double spl_real = 1;
	char spl_char = 1;

	spl_char = ' ';
	spl_char = ' ';
}

int main()
{
	prg_ConstantFolding();
	return 0;
}
