#include "shell.h"

/**
 * get_env - Func find a specific env var
 * @name: Environment variable to get.
 * Return: Pointer to the lenv var or 0 if there is no duplicate.
 */
char *get_env(const char *name)
{
	char **env_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int pa_length, env_length, length, i;
	/* Count the number of elements in the environ array */
	env_length = 0;
	while (environ[env_length] != NULL)
		env_length++;
	/* Create a copy of the environment variables */
	env_copy = NULL;
	env_copy = copy_env(env_copy, env_length);
	/* Calculate the length of the input environment variable name */
	length = str_len((char *)name);
	i = 0;
	/* Loop through the copied environment variables */
	while (env_copy[i] != NULL)
	{
		variable = env_copy[i];
		/* Compare the input name with the current environment variable */
		compare = str_ncmp((char *)name, variable, length);
		/* If there is a match */
		if (compare == 1)
		{
			/* Extract the value part of the environment variable */
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			/* Handle the case where the value is NULL */
			if (value == NULL)
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			/* Calculate the length of the value */
			pa_length = str_len(value);
			/* Allocate memory for the path variable */
			path = malloc(sizeof(char) * pa_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			/* Copy the value to the newly allocated memory */
			path = str_cpy(path, value);
			/* Free the copied environment variables */
			free_dp(env_copy, env_length);
			/* Return the path variable */
			return (path);
		}
		i++;
	}
	/* If no match is found, return NULL */
	return (NULL);
}

/**
 * copy_env - func generate a duplicate if the environment variables to avoid
 * of envt variables.
 * @env_copy: fPointer to the copy of environment variables.
 * @env_length: fLength of the environment variables.
 * Return: Double pointer to the copy of environment variables.
 */
char **copy_env(char **env_copy, unsigned int env_length)
{
	char *variable;
	unsigned int variable_length;
	unsigned int i;
	/* Allocate memory for the copy of environment variables */
	env_copy = malloc(sizeof(char **) * (env_length));
	if (env_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	i = 0;
	/* Loop through the original environment variables */
	while (i < env_length)
	{
		variable = environ[i];
		/* Calculate the length of the current environment variable */
		variable_length = str_len(variable);
		/* Allocate memory for the copy of the current environment variable */
		env_copy[i] = malloc(sizeof(char) * variable_length + 1);
		if (env_copy[i] == NULL)
		{
			errors(3);
			return (NULL);
		}
		/* Copy the original environment variable to the copy */
		str_cpy(env_copy[i], environ[i]);
		i++;
	}
	/* Return the copy of environment variables */
	return (env_copy);
}
