#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int    queue_get_size(queue_t queue)
{
    int count = 0;

    if (queue == NULL)
        return 0;
    for (count = 0; queue->next != NULL; count++) {queue = queue->next;}
    return (count + 1) ;
}

bool queue_is_empty(queue_t queue)
{
    return (queue == NULL) ? true : false;
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    queue_t back_queue = malloc(sizeof(queue_t));
    queue_t head = *queue_ptr;

    if (back_queue == NULL)
        return false;
    else if (*queue_ptr == NULL){
        back_queue->next = NULL;
        back_queue->value = elem;
        *queue_ptr = back_queue;
        return (true);
    } else {
        for (int count = 0; head->next != NULL; count++) {head = head->next;}
        head->next = (back_queue != NULL) ? back_queue : NULL;
        back_queue->value = elem;
        back_queue->next = NULL;
        return (true);
    }
}

bool    queue_pop(queue_t *queue_ptr)
{
    queue_t head = *queue_ptr;
    queue_t back_queue = NULL;

    if (*queue_ptr == NULL)
        return false;
    else if (head->next == NULL) {
        free(head);
        return true;
    }
    for (int i = 0; head->next != NULL; i++) {
        if (head->next->next == NULL)
            back_queue = head;
        head = head->next;
    }
    back_queue->next = NULL;
    free(head);
    return true;
}