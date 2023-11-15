#include "shell.h"

/**
 * **_strtor - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtor(char *str, char *delim)
{
	int a, b, c, n, w_count = 0;
	char **string;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!dee_delim(str[a], delim) && (dee_delim(str[a + 1], delim) || !str[a + 1]))
			w_count++;

	if (w_count == 0)
		return (NULL);
	string = malloc((1 + w_count) * sizeof(char *));
	if (!string)
		return (NULL);
	for (a = 0, b = 0; b < w_count; b++)
	{
		while (dee_delim(str[a], delim))
			a++;
		c = 0;
		while (!dee_delim(str[a + c], delim) && str[a + c])
			c++;
		string[b] = malloc((c + 1) * sizeof(char));
		if (!string[b])
		{
			for (c = 0; c < b; c++)
				free(string[c]);
			free(string);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			string[b][n] = str[a++];
		string[b][n] = 0;
	}
	string[b] = NULL;
	return (string);
}

/**
 * **_strtor2 - splits a string into words
 * @str: the input string
 * @delim: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **_strtor2(char *str, char delim)
{
	int a, b, c, n, w_count = 0;
	char **string;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != delim && str[a + 1] == delim) ||
		    (str[a] != delim && !str[a + 1]) || str[a + 1] == delim)
			w_count++;
	if (w_count == 0)
		return (NULL);
	string = malloc((1 + w_count) * sizeof(char *));
	if (!string)
		return (NULL);
	for (a = 0, b = 0; b < w_count; b++)
	{
		while (str[a] == delim && str[a] != delim)
			a++;
		c = 0;
		while (str[a + c] != delim && str[a + c] && str[a + c] != delim)
			c++;
		string[b] = malloc((c + 1) * sizeof(char));
		if (!string[b])
		{
			for (c = 0; c < b; c++)
				free(string[c]);
			free(string);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			string[c][n] = str[a++];
		string[b][n] = 0;
	}
	string[b] = NULL;
	return (string);
}
