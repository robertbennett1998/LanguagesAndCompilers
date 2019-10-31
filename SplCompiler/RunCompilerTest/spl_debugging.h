#ifndef SPL_DEBUGGING_H
#define SPL_DEBUGGING_H

#define HANDLE_WARNING(message, ...) { printf("/*WARNING (%d:%d): ", g_uiCurrentLineNumber, g_ulCurrentLinePosition); printf(message, ##__VA_ARGS__); printf("*/\n"); }

unsigned int g_uiCurrentLineNumber;
unsigned long g_ulCurrentLinePosition;
void PrintLinePositionUpdate();
void IncrementLinePosition(const int iTokenLength);
void ProcessEndOfLine();

#endif