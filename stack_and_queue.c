#include "monty.h"

/* sets the list to store items on LIFO basis */
STACK {
	(NON)line_number;
	(NON)stack;
	misc_data.stack = TRUE;
}

/* sets the list to store items on FIFO basis */
QUEUE {
	(NON)line_number;
	(NON)stack;
	misc_data.stack = FALSE;
}
