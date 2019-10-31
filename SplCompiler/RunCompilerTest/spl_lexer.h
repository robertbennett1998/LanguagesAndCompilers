#ifndef SPL_LEXER_H
#define SPL_LEXER_H

#define EXPAND(x) x
#define GET_PROCESS_GENERIC_TOKEN_MACRO(_1,_2,NAME,...) NAME
#define PROCESS_GENERIC_TOKEN(...) EXPAND(GET_PROCESS_GENERIC_TOKEN_MACRO(__VA_ARGS__, PROCESS_GENERIC_TOKEN_2, PROCESS_GENERIC_TOKEN_1)(__VA_ARGS__))	

#ifdef PRINT 
    #define PROCESS_GENERIC_TOKEN_1(token) 	{\
                                                PrintToken(#token);\
                                                IncrementLinePosition(strlen(#token));\
                                            }

    #define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint) 	{\
                                                                PrintTokenAndValue(#token, symbolToPrint);\
                                                                IncrementLinePosition(strlen(symbolToPrint));\
                                                            }

    #define ASSIGN_YYLVAL(x, y)
#else
    #define PROCESS_GENERIC_TOKEN_1(token)	{\
                                                IncrementLinePosition(strlen(#token));\
                                                return token;\
                                            }

    #define PROCESS_GENERIC_TOKEN_2(token, symbolToPrint)	{\
                                                IncrementLinePosition(strlen(symbolToPrint));\
                                                return token;\
                                            }

    #define ASSIGN_YYLVAL(x, y) yylval.x = y;
#endif

void PrintToken(const char* pToken);
void PrintTokenAndValue(const char* pToken, const char* pSymbolToPrint);

#endif