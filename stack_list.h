#ifndef _STACK_LIST_
#define _STACK_LIST_

#include "monty.h"

#define ADD_NODE_AT_IDX		add_node_at_idx
stack_t *add_node_to_end(stack_t **head, const int n);
stack_t *add_node_to_beg(stack_t **head, const int n);
stack_t *add_node_at_idx(stack_t **h, unsigned int idx, int n);
#endif /* for _STACK_LIST_ */
