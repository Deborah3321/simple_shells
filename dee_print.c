#include "shell.h"

void dee_print(const char *print_function)
{
	write(STDOUT_FILENO, print_function, strlen(print_function));
}
