#include <stdio.h>

void _spl_flush_stdin()
{
	char c = -1;
	fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
	do
	{
		c = getchar();
		if (c != EOF)
		{
			fprintf(stderr,"%c", c);
		}
	} while (c != '\n' && c != ' ' && c != EOF);
}

void prg_DeadCode()
{
	int spl_a = 1;

	spl_a = 7;
	printf("LIVE1");
	printf("\n");
	printf("LIVE2");
	printf("\n");
	printf("LIVE3");
	printf("\n");
	printf("LIVE4");
	printf("\n");
	printf("LIVE5");
	printf("\n");
	printf("LIVE6");
	printf("\n");
	printf("LIVE7");
	printf("\n");
	printf("LIVE8");
	printf("\n");
	printf("LIVE9");
	printf("\n");
	printf("LIVE11");
	printf("\n");
	printf("LIVE12");
	printf("\n");
	printf("LIVE13");
	printf("\n");
	if ((spl_a > 8))
	{
		printf("\n");
	}
	while (('a' == 'a'))
	{
		printf("LIVE14");
		printf("\n");
	};
	while ((7 == 7))
	{
		printf("LIVE15");
		printf("\n");
	};
	printf("LIVE16");
	printf("\n");
	printf("LIVE");
	printf("\n");
	do
	{
		printf("LIVE");
		printf("\n");
	} while ((7 == 7));
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_DeadCode();
	return 0;
}
