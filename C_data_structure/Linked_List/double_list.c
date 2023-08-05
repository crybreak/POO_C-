#include "double_list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    int count = 0;

    for (count = 0; list->next != NULL; count++) {list = list->next;}
    return (count + 1);
}

bool double_list_is_empty(double_list_t list)
{
    return (list->next = NULL) ? true : false;
}

void double_list_dump(double_list_t list)
{
    double_list_t head = list;
    for (int count = 0; head->next != NULL; count++) {
        printf("%f\n", head->value);
        head = head->next;
    }
    printf("%f\n", head->value);
}

bool double_list_add_elem_at_front(double_list_t *front_ptr , double elem)
{
    double_list_t new_node = malloc(sizeof(double_list_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = (*front_ptr != NULL) ? *front_ptr : NULL;
    *front_ptr = new_node;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr , double elem)
{
    double_list_t back_node = malloc(sizeof(double_list_t));
    double_list_t head = *front_ptr;

    if (back_node == NULL)
        return false;
    else if (*front_ptr == NULL){
        back_node->next = NULL;
        back_node->value = elem;
        *front_ptr = back_node;
        return (true);
    } else {
        for (int count = 0; head->next != NULL; count++) {head = head->next;}
        head->next = (back_node != NULL) ? back_node : NULL;
        back_node->value = elem;
        back_node->next = NULL;
        return (true);
    }
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem, unsigned int position)
{
    double_list_t new_node = malloc(sizeof(double_list_t));
    double_list_t list = *front_ptr;
    double_list_t head = *front_ptr;
    int count = 0;

    if (new_node == NULL)
        return false;
    for (count = 0; list->next != NULL || (count < position - 1); count++)
        list = list->next;
    if (count < position - 1) { printf("%d", 5); return 0;}
    else {
        for (count = 0; count < position - 2 ; count++) { head = head->next;}
        new_node->value = elem;
        head->next = new_node;
        new_node->next = head;
    }
    return (true);
}

static void populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_front(list_head, 5.2);
    double_list_add_elem_at_front(list_head, 42.5);
    double_list_add_elem_at_front(list_head, 40.5);
    double_list_add_elem_at_front(list_head, 36.5);
    double_list_add_elem_at_front(list_head, 15.5);
    double_list_add_elem_at_back(list_head, 12.9);
    double_list_add_elem_at_back(list_head, 11.35);
    double_list_add_elem_at_front(list_head, 39.3);
    double_list_add_elem_at_front(list_head, 98.0);
    double_list_add_elem_at_position(list_head, 98.0, 2);

}

int main(void)
{
    double_list_t head = NULL;
    populate_list(&head);
    double_list_dump(head);
}