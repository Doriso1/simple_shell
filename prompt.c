#include "shell.h"

/**
 * prompt - shell function interactive mode
 * Checks file charactr special file
 * (typically a terminal) by using the S_ISCHR macro.
 * @fd: File stream
 * @buf: Buffer containing file info.
 */
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts -  func that print shell prompt
 * find length of the input string by tr_len.
 * print the string to the standard output by write.
 * @str: print stng
 * Return: 0 if successful
 */
void _puts(char *str)
{
	unsigned int length;
	length = str_len(str);
	write(STDOUT_FILENO, str, length);
}
