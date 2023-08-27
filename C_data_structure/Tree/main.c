# include "tree_traversal.h"
#include "../Stack/stack.h"
#include "../Queue/queue.h"
#include <stdlib.h>
#include <stdio.h>

void dump_int(void *data)
{
    printf("%d\n", *(int *)data);
}

bool generic_push_stack(void *container , void *data)
{
    return stack_push((_stack_t *)container , data);
}

void *generic_pop_stack(void *container) {
    void *data = stack_top((_stack_t )container);
    stack_pop((_stack_t *)container);
    return data;
}

void *generic_pop_queue(void *container) {
    void *data = queue_front((queue_t)container);
    queue_pop((queue_t *)container);
    return data;
}

bool generic_push_queue(void *container , void *data)
{
    return queue_push((queue_t *)container, data);
}

static void test_depth(tree_t tree) {
    container_t container;
    _stack_t stack = NULL;
    printf("Depth walk:\n");
    container.container = stack;
    container.push_func = &generic_push_stack;
    container.pop_func = &generic_pop_stack;
    tree_traversal(tree, &container, &dump_int);
}
static void test_width(tree_t tree) {
    container_t container;
    queue_t queue = NULL;
    printf("Width walk:\n");
    container.container = queue;
    container.push_func = &generic_push_queue;
    container.pop_func = &generic_pop_queue;
    tree_traversal(tree, &container, &dump_int);
}
