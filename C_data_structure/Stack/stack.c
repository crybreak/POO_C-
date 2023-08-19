#include "stack.h"
#include <stdio.h>

bool stack_push(_stack_t *stack_ptr, void *elem)
{
    _stack_t new_node = malloc(sizeof(_stack_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = (*stack_ptr != NULL) ? *stack_ptr : NULL;
    *stack_ptr = new_node;
    return (true);
}

bool   stack_pop(_stack_t *stack_ptr)
{
    _stack_t head = *stack_ptr;

    if (*stack_ptr == NULL)
        return (false);
    *stack_ptr = head->next;
    free(head);
    return (true);
}

void    *stack_top(_stack_t stack)
{
    return (stack->next == NULL) ? 0 : stack->value;
}
int main(void) {
    _stack_t stack = NULL;
    int i = 5;
    int j = 4;
    int *data = NULL;
    stack_push(&stack, &i);
    stack_push(&stack, &j);
    data = (int *)stack_top(stack);
    printf("%d\n", *data);
    return (0);
}
