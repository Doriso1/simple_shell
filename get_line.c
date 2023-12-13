#include "shell.h"

/**
 * get_line - Func for reading line of user input.
 * success status.
 * Returns the size containing user input.
 * @fp: File stream (stdin or a file, depending on usage).
 * Return: i succeful return he user input buffer.
 */

char *get_line(FILE *fp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;  /* Initialize line to NULL to avoid undefined behavior */
	len = 0;            /* Initialize len to 0 */
	/* Read a line of input from the user into the buffer 'line' */
	read = getline(&line, &len, fp);
	/* Check if getline encountered an error or reached the end of file */
	if (read == -1)
	{
		free(line);     /* Free the memory allocated for the buffer */
		exit(EXIT_SUCCESS); /* Exit the program with success status */
	}
	return (line);      /* Return the buffer containing the user input */
}
