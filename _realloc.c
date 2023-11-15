#include "shell.h"

/**
 * _realloc - Adjusts the allocation of a memory block..
 * @ptr: Pointer to the previous memory block.
 * @new_size: Updated size of the memory block..
 * Return: Pointer to the newly allocated memory block, or NULL in case of failure.
 */
void *_realloc(void *ptr, size_t new_size)
{
size_t prev_size, element_size, total_elements, i;
void *new_ptr;
char *prev_content, *new_content;
/* Verifies if new_size is NULL and allocates new memory if necessary. */
if (new_size == 0)  
{
	free(ptr);
	return (NULL);
}
/* Verifies if ptr is NULL and, if so, allocates new memory. */
if (ptr == NULL)  
	return (malloc(new_size));
/* Tries to allocate memory for the new block. */
new_ptr = malloc(new_size); 

if (new_ptr)
{
	/* Compute the size of each element and the total number of elements. */
	element_size = sizeof(((char *)ptr)[0]);
	total_elements = new_size / element_size;
	prev_size = total_elements * element_size;
	/* Use the smaller of the old and new sizes */
	if (new_size < prev_size)
	{
		prev_size = new_size;
	}
	prev_content = (char *)ptr;
	new_content = (char *)new_ptr;
	/* Replicate data from the old block to the new block. */
	for (i = 0; i < prev_size; i++)
	{
		new_content[i] = prev_content[i];
	}
    /* Release the old memory block. */
	free(ptr); 
	return (new_ptr);
}
else
{
    /* Unsuccessful memory allocation. */
	return (NULL); 
}
}
