#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	do
	{
		c = getchar();
	} while (c != '\n' && c != ' ' && c != EOF);
}

void Read()
{
	int spl_int = 1;
	char spl_char = 1, spl_char2 = 1;

	while (scanf("%d", &spl_int) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	while (scanf(" %c", &spl_char) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	while (scanf(" %c", &spl_char2) != 1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ' || c == EOF)
		{
			break;
		}
	};
	_spl_flush_stdin();
	printf("\n");
	printf("%d", spl_int);
	printf("\n");
	printf("%c", spl_char);
	printf("\n");
	printf("%c", spl_char2);
}

int main()
{
	Read();
	return 0;
}
