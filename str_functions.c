#include "shell.h"

/**
 * str_func - Comparison 2 strgs up.
 * @name: user prompt to search for.
 * @variable: Var difference.
 * @length: name size.
 * Return: 1 if str successful, -1 if otherwise.
 */
int str_cmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;
	/* find length of the var string. */
	var_length = str_len(variable);
	/* If lengths are not equal, strings can't be the same. */
	if (var_length != length)
		return (-1);
	i = 0;
	/* Compare characters until a mismatch or end of the strings. */
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1); /* Strings are not equal. */
		i++;
	}
	return (0); /* Strings are equal. */
}

/**
 * str_func - difference of 2 strgs.
 * @name: prompt entered by the user.
 * @variable: Var to compare against.
 * @length: size to compare up to.
 * Return: 1 if strings are equal, -1 if otherwise
 */
int str_ncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;

	/* Compare characters up to the specified length. */
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1); /* Strings are not equal. */
		i++;
	}
	return (1); /* Strings are equal. */
}

/**
 * str_func - Copies the stg pointed to by src to varto by dest.
 * @dest: String destination.
 * @src: Strh source.
 * Return: The pointer array.
 */
char *str_cpy(char *dest, char *src)
{
	int i;
	int j = str_len(src);
	/* Copy characters from src to dest. */
	for (i = 0; i <= j; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * str_len - Returns the length of the input string s. Counts characters until
 * the null terminator is encountered.
 * @s: Strg to be compatible.
 * Return: string size.
 */
int str_len(char *s)
{
	int i = 0;
	/* Count characters until the null terminator is encountered. */
	while (s[i] != '\0')
		i++;
	return (i);
}
