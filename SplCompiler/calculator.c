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

void prg_Calculator()
{
	char spl_space = 1, spl_period = 1, spl_bra = 1, spl_ket = 1;
	char spl_choice = 1;
	int spl_i = 1, spl_iA = 1, spl_iB = 1, spl_iRes = 1;
	double spl_rA = 1, spl_rB = 1, spl_rRes = 1;

	spl_space = 32;
	spl_period = 46;
	spl_bra = 40;
	spl_ket = 41;
	printf("Welcome%cto%ca%csimple%ccalculator%cimplemented%cin%cSPL%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period);
	printf("\n");
	printf("\n");
	do
	{
		printf("Please%cselect%can%coperation%c%cAddition%c%ca%c%c%cSubtraction%c%cs%c%c%cDivision%c%cd%c%c%cMultipulcation%c%cm%c%c%cPower%c%cp%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
		printf("\n");
		{
			char _spl_bDiscardedCharsFlag = 0;
			while (scanf(" %c", &spl_choice) != 1)
			{
				char c = getchar();
				if (c == '\n' || c == ' ' || c == EOF)
				{
					break;
				}
				if (_spl_bDiscardedCharsFlag == 0)
				{
					fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
					_spl_bDiscardedCharsFlag = 1;
				}
				fprintf(stderr,"%c", c);
			};
			_spl_flush_stdin();
		}
		if ((spl_choice == 'a'))
		{
			printf("Please%center%ca%ctype%cfor%cthe%cfirst%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
			printf("\n");
			do
			{
				{
					char _spl_bDiscardedCharsFlag = 0;
					while (scanf(" %c", &spl_choice) != 1)
					{
						char c = getchar();
						if (c == '\n' || c == ' ' || c == EOF)
						{
							break;
						}
						if (_spl_bDiscardedCharsFlag == 0)
						{
							fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
							_spl_bDiscardedCharsFlag = 1;
						}
						fprintf(stderr,"%c", c);
					};
					_spl_flush_stdin();
				}
				if ((spl_choice == 'i'))
				{
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_iRes = (spl_iA + spl_iB);
							printf("Answer%c%c%d", spl_period, spl_space, spl_iRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_iA + spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
				if ((spl_choice == 'r'))
				{
					printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%lf", &spl_rA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA + spl_iB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA + spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
			} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
		}
		if ((spl_choice == 's'))
		{
			printf("Please%center%ca%ctype%cfor%cthe%cfirst%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
			printf("\n");
			do
			{
				{
					char _spl_bDiscardedCharsFlag = 0;
					while (scanf(" %c", &spl_choice) != 1)
					{
						char c = getchar();
						if (c == '\n' || c == ' ' || c == EOF)
						{
							break;
						}
						if (_spl_bDiscardedCharsFlag == 0)
						{
							fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
							_spl_bDiscardedCharsFlag = 1;
						}
						fprintf(stderr,"%c", c);
					};
					_spl_flush_stdin();
				}
				if ((spl_choice == 'i'))
				{
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_iRes = (spl_iA - spl_iB);
							printf("Answer%c%c%d", spl_period, spl_space, spl_iRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_iA - spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
				if ((spl_choice == 'r'))
				{
					printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%lf", &spl_rA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA - spl_iB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA - spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
			} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
		}
		if ((spl_choice == 'd'))
		{
			printf("Please%center%ca%ctype%cfor%cthe%cfirst%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
			printf("\n");
			do
			{
				{
					char _spl_bDiscardedCharsFlag = 0;
					while (scanf(" %c", &spl_choice) != 1)
					{
						char c = getchar();
						if (c == '\n' || c == ' ' || c == EOF)
						{
							break;
						}
						if (_spl_bDiscardedCharsFlag == 0)
						{
							fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
							_spl_bDiscardedCharsFlag = 1;
						}
						fprintf(stderr,"%c", c);
					};
					_spl_flush_stdin();
				}
				if ((spl_choice == 'i'))
				{
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							if ((spl_iB != 0))
							{
								spl_iRes = (spl_iA / spl_iB);
								printf("Answer%c%c%d", spl_period, spl_space, spl_iRes);
								printf("\n");
							}
							else
							{
								printf("Cannot%cdivide%cby%czero%c", spl_space, spl_space, spl_space, spl_period);
								printf("\n");
							}
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							if ((spl_rB != 0))
							{
								spl_rRes = (spl_iA / spl_rB);
								printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
								printf("\n");
							}
							else
							{
								printf("Cannot%cdivide%cby%czero%c", spl_space, spl_space, spl_space, spl_period);
								printf("\n");
							}
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
				if ((spl_choice == 'r'))
				{
					printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%lf", &spl_rA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							if ((spl_iB != 0))
							{
								spl_rRes = (spl_rA / spl_iB);
								printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
								printf("\n");
							}
							else
							{
								printf("Cannot%cdivide%cby%czero%c", spl_space, spl_space, spl_space, spl_period);
								printf("\n");
							}
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							if ((spl_rB != 0))
							{
								spl_rRes = (spl_rA / spl_rB);
								printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
								printf("\n");
							}
							else
							{
								printf("Cannot%cdivide%cby%czero%c", spl_space, spl_space, spl_space, spl_period);
								printf("\n");
							}
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
			} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
		}
		if ((spl_choice == 'm'))
		{
			printf("Please%center%ca%ctype%cfor%cthe%cfirst%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
			printf("\n");
			do
			{
				{
					char _spl_bDiscardedCharsFlag = 0;
					while (scanf(" %c", &spl_choice) != 1)
					{
						char c = getchar();
						if (c == '\n' || c == ' ' || c == EOF)
						{
							break;
						}
						if (_spl_bDiscardedCharsFlag == 0)
						{
							fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
							_spl_bDiscardedCharsFlag = 1;
						}
						fprintf(stderr,"%c", c);
					};
					_spl_flush_stdin();
				}
				if ((spl_choice == 'i'))
				{
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_iRes = (spl_iA * spl_iB);
							printf("Answer%c%c%d", spl_period, spl_space, spl_iRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_iA * spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
				if ((spl_choice == 'r'))
				{
					printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%lf", &spl_rA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%ca%ctype%cfor%cthe%csecond%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
					printf("\n");
					do
					{
						{
							char _spl_bDiscardedCharsFlag = 0;
							while (scanf(" %c", &spl_choice) != 1)
							{
								char c = getchar();
								if (c == '\n' || c == ' ' || c == EOF)
								{
									break;
								}
								if (_spl_bDiscardedCharsFlag == 0)
								{
									fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
									_spl_bDiscardedCharsFlag = 1;
								}
								fprintf(stderr,"%c", c);
							};
							_spl_flush_stdin();
						}
						if ((spl_choice == 'i'))
						{
							printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%d", &spl_iB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA * spl_iB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
						if ((spl_choice == 'r'))
						{
							printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
							printf("\n");
							{
								char _spl_bDiscardedCharsFlag = 0;
								while (scanf("%lf", &spl_rB) != 1)
								{
									char c = getchar();
									if (c == '\n' || c == ' ' || c == EOF)
									{
										break;
									}
									if (_spl_bDiscardedCharsFlag == 0)
									{
										fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
										_spl_bDiscardedCharsFlag = 1;
									}
									fprintf(stderr,"%c", c);
								};
								_spl_flush_stdin();
							}
							spl_rRes = (spl_rA * spl_rB);
							printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
							printf("\n");
							spl_choice = 0;
						}
					} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
				}
			} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
		}
		if ((spl_choice == 'p'))
		{
			printf("Please%center%ca%ctype%cfor%cthe%cfirst%coperand%cof%cthe%cchosen%coperation%c%cInteger%c%ci%c%c%cReal%c%cr%c%c%cOr%cto%cquit%c%cq%c%c", spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_space, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_bra, spl_ket, spl_period, spl_space, spl_space, spl_space, spl_space, spl_bra, spl_ket, spl_period);
			printf("\n");
			do
			{
				{
					char _spl_bDiscardedCharsFlag = 0;
					while (scanf(" %c", &spl_choice) != 1)
					{
						char c = getchar();
						if (c == '\n' || c == ' ' || c == EOF)
						{
							break;
						}
						if (_spl_bDiscardedCharsFlag == 0)
						{
							fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
							_spl_bDiscardedCharsFlag = 1;
						}
						fprintf(stderr,"%c", c);
					};
					_spl_flush_stdin();
				}
				if ((spl_choice == 'i'))
				{
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iB) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					spl_iRes = spl_iA;
					for (spl_i = 1; 1 < 0 ? spl_i >= (spl_iB - 1) : spl_i <= (spl_iB - 1); spl_i += 1)
					{
						spl_iRes = (spl_iA * spl_iRes);
					}
					printf("Answer%c%c%d", spl_period, spl_space, spl_iRes);
					printf("\n");
					spl_choice = 0;
				}
				if ((spl_choice == 'r'))
				{
					printf("Please%center%ca%creal%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%lf", &spl_rA) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					printf("Please%center%can%cinteger%c", spl_space, spl_space, spl_space, spl_period);
					printf("\n");
					{
						char _spl_bDiscardedCharsFlag = 0;
						while (scanf("%d", &spl_iB) != 1)
						{
							char c = getchar();
							if (c == '\n' || c == ' ' || c == EOF)
							{
								break;
							}
							if (_spl_bDiscardedCharsFlag == 0)
							{
								fprintf(stderr, "\nWARNING: Discarding the following invalid input/extra characters from the stdin stream: ");
								_spl_bDiscardedCharsFlag = 1;
							}
							fprintf(stderr,"%c", c);
						};
						_spl_flush_stdin();
					}
					spl_rRes = spl_rA;
					for (spl_i = 1; 1 < 0 ? spl_i >= (spl_iB - 1) : spl_i <= (spl_iB - 1); spl_i += 1)
					{
						spl_rRes = (spl_rA * spl_rRes);
					}
					printf("Answer%c%c%lf", spl_period, spl_space, spl_rRes);
					printf("\n");
					spl_choice = 0;
				}
			} while ((((spl_choice != 'q')) && ((spl_choice != 0))));
		}
	} while ((spl_choice != 'q'));
}

int main()
{
	fprintf(stderr, "----------------RUNTIME WARNINGS & ERRORS----------------");
	prg_Calculator();
	return 0;
}
