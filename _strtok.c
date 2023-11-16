#include "shell.h"

/**
 * _strtok - Splits a string into tokens using specified delimiters.
 *
 * @input: The string to be tokenized
 * @delim: The delimiter
 * Return: A reference to the next token or NULL if no tokens remain.
 */

char *_strtok(char *input, const char *delim)
{
    /* Maintains the last input location across consecutive calls. */
    static char *tracker;
    char *token;

    if (input != NULL)
        /* Initialize the tracker to the input string. */
        tracker = input; 

    /* Verify whether the tracker is NULL or points to a delimiter at the beginning. */
    while ((tracker != NULL) && (_strchr(delim, *tracker) != NULL) &&
           (*tracker != '\0'))
        tracker++;
    /* Commence storing the current token. */
    token = tracker;

    if (tracker == NULL || *tracker == '\0')
        /* No remaining tokens. */
        return (NULL);

    /* Determine the endpoint of the current token. */
    while (*tracker != '\0')
    {
        if (_strchr(delim, *tracker) != NULL)
        {
            /* A delimiter has been detected. */
            *tracker = '\0'; /* Conclude the current token. */
            tracker++;       /* Advance to the character following the delimiter. */
            return (token);
        }
        tracker++;
    }

    /* Verify if the end of the string has been reached. */
    if (*tracker == '\0')
    {
        tracker = NULL; /* Reset the tracker if there are no remaining tokens. */
        return (token); /* Provide the final token. */
    }
    return (NULL); /* Return NULL if there are no remaining tokens. */
}
