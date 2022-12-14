#include <unistd.h>
#include "monty.h"

CLOSE_FUNC
{
	fprintf(stderr, msg, line_number);
	free(misc_data.line);
	misc_data.line = NULL;
	fclose(misc_data.f_ptr);
	exit(EXIT_FAILURE);
}

FREE_STACK_FUNC
{
	if (stack)
	{
		FREE_STACK(stack->next);
		free(stack);
		stack = NULL;
	}
}

ISDIGIT_FUNC
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

CLEAN_FOR_MALLOC_FUNC
{
	fprintf(stderr, ERR_MALLOC);
	free(misc_data.line);
	misc_data.line = NULL;
	fclose(misc_data.f_ptr);
	FREE_STACK(stack);
}
