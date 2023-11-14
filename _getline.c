#include "shell.h"
/**
 * _getline - Reads a complete line from the specified file input stream.
 * @lineptr: Pointer to the buffer that holds the line being read.
 * @alloc_size: Pointer to the allocated buffer size.
 * @input: File input stream.
 * Return: The number of characters read, including the delimiter
 * character, excluding ('\0'). Returns -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *alloc_size, FILE *input)
{
char delim = '\n'; /* Delimiter */
size_t tracker = 0; /* Monitors the current position within the buffer */
int bytes_read; /* Stores the read result or EOF. */
char *new_buffer; /* Stores the address of newly allocated memory. */

if (lineptr == NULL || alloc_size == NULL || input == NULL)
	return (-1);
if (*lineptr == NULL || *alloc_size == 0)
{
	*alloc_size = BUFFSIZE; /* Initialize the buffer size to BUFFSIZE. */
	*lineptr = (char *)malloc(*alloc_size);
	if (*lineptr == NULL)
		return (-1); /* Allocation failure */
}
while (1)
{
	bytes_read = fgetc(input);
	if (bytes_read == EOF)
		return (_eof(lineptr, tracker));

	if (tracker + 1 >= *alloc_size)
	{
		new_buffer = (char *)_realloc(*lineptr, *alloc_size *= 2);
		if (new_buffer == NULL)
		{
			free(*lineptr); /* Free memory */
			return (-1); /* Memory reallocation failure */
		}
	}
	(*lineptr)[tracker++] = (char)bytes_read;
	if (tracker > 1 && (*lineptr)[tracker - 1] == '\n' &&
	(*lineptr)[tracker - 2] == '\n')
		return (0);
	if (bytes_read == delim)
	{
		(*lineptr)[tracker] = '\0'; /* Exclude the newline character */
		return (tracker); /* Line successfully read, excluding null terminator */
	}
}
}

/**
 * _eof - Handles the situation when EOF is encountered.
 * @lineptr: Pointer to the line buffer.
 * @tracker: Keeps track of characters read.
 * Return: Number of characters read, excluding '\0', otherwise -1 on error.
 */
ssize_t _eof(char **lineptr, size_t tracker)
{
	if (tracker == 0)
	{
		free(*lineptr); /* Free memory */
		return (-1); /* No character read (EOF) */
	}
	else
	{
		(*lineptr)[tracker] = '\0';
		return (tracker); /* Line successfully read, excluding null terminator */
	}
}
