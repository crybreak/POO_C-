#ifndef STACK_H_
# define STACK_H_

# include "../Generic_list/generic_list.h"
#include <stdlib.h>


typedef list_t _stack_t;

/* Information */

unsigned int    stack_get_size(_stack_t stack);
bool            stack_is_empty(_stack_t stack);

/* Modification */

bool    stack_push(_stack_t *stack_ptr, void *elem);
bool    stack_pop(_stack_t *stack_ptr);

/* Access */

void    *stack_top(_stack_t stack);

#endif /* !STACK_H_ */
