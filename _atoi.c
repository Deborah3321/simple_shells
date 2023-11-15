#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * dee_delim - checks if character is a delimeter
 * @h: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int dee_delim(char h, char *delim)
{
	while (*delim)
		if (*delim++ == h)
			return (1);
	return (0);
}

/**
 *_letter - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _letter(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@c: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *c)
{
	int n, sign = 1, flag = 0, outcome;
	unsigned int result = 0;

	for (n = 0;  c[n] != '\0' && flag != 2; n++)
	{
		if (c[n] == '-')
			sign *= -1;

		if (c[n] >= '0' && c[n] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		outcome = -result;
	else
		outcome = result;

	return (outcome);
}
