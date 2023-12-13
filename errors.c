#include "shell.h"

/**
 * er - func to print all error messages
 * The str_len func determine size error msg
 * @error: Error number associated with perror statement.
 * Return: void
 */

void errors(int error)
{
	switch (error)
	{
		case 1: 
			write(STDERR_FILENO, ERR_FORK, str_len(ERR_FORK));
			perror("Error");
			break;
		case 2: /* execve error to stderr */
			perror("Error");
			break;
		case 3: /* maloc error to stderr */
			write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
			break;
		case 4: /* empty path err to stderr */
			write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
			break;
		default:
			return;
	}
}
