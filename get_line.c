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

	line = NULL;  /* NULL line to avoid undefined behavior */
	len = 0;
	/* user input from the buffer line */
	read = getline(&line, &len, fp);
	/* if not successful getline or get to the file end */
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
