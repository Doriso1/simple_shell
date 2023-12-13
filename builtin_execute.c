#include "shell.h"

/**
 * main entry - built-in commands through provided tokens.
 * @tokens: Arg to be passed.
 * Return: successful  on the execution of intititual function.
 */
int buiilt_in_execu(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;
	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	/* find no command available */
	if (tokens[0] == NULL)
		return (1);
	/* check the size of the intial token (command) */
	length = str_len(tokens[0]);
	/* check no of built-in commands */
	num = shell_no_builtins(builtin);
	/* alter array of built-in commands */
	for (i = 0; i < num; i++)
	{
		/* doest available command same the current built-in command */
		if (str_cmp(tokens[0], builtin[i].name, length) == 0)
		{
			/* Execute the corresponding built-in function and store its return value */
			status = (builtin[i].p)();
			/* Return the status, indicating the success or failure */
			/* of the built-in function */
			return (status);
		}
	}
	/* If the command is not a built-in, return 1 (considered as a success) */
	return (1);
}

/**
 * shell_no_builtins - Counts the number of built-in commands in the array.
 * It iterates through the array until a NULL entry is encountered
 * and counts the number of built-in commands.
 * Returns the total number of built-in commands.
 * @builtin: Array of built-in commands.
 * Return: The number of built-in commands.
 */
int shell_no_builtins(built_s builtin[])
{
	unsigned int i = 0;
	/* Iterate through the array until a NULL entry is encountered, */
	/* counting the number of built-in commands */
	while (builtin[i].name != NULL)
		i++;
	/* Return the total number of built-in commands */
	return (i);
}
