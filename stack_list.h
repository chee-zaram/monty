#ifndef _STACK_LIST_
#define _STACK_LIST_

#include "monty.h"

#define ADD_NODE_AT_IDX		add_node_at_idx
#define DEL_TOP			del_top
STACK_STRUCT *add_node_to_end(STACK_STRUCT **head, const _INT_ n);
STACK_STRUCT *add_node_to_beg(STACK_STRUCT **head, const _INT_ n);
STACK_STRUCT *add_node_at_idx(STACK_STRUCT **h, _UI_ idx, _INT_ n);
NON del_top(STACK_STRUCT **head);
#endif /* for _STACK_LIST_ */
