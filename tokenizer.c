#include "shell.h"

/**
 * tokenizer - Strng into an array tokens.
 * @str: input string of user to be tokenized.
 * Return: Pointer to an array of tokens.
 */
char **tokenizer(char *str)
{
	char **tokens;         /* temper store the array of tokens */
	char *token;           /* var to get each token */
	unsigned int i;        /* Index var */
	/* malloc for the array of tokens */
	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3); /* Print error message and exit memory allocation */
		exit(EXIT_FAILURE);
	}
	/* func strtok to input str on delimiters("\n\t\r ") */
	token = strtok(str, "\n\t\r ");
	i = 0;
	/* Iterate variety and store them in the tokens array */
	while (token != NULL)
	{
		tokens[i] = token;  /* get more token in the array */
		token = strtok(NULL, "\n\t\r ");  /* Get the next token */
		i++;               /* Move to the next index */
	}
	tokens[i] = NULL;  /* get first element of array 0 mark end tokens */
	return (tokens);       /* Return the pointer to the array of tokens */
}
