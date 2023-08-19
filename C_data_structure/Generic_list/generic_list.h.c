#include "generic_list.h"
#include <stdlib.h>
#include <stdio.h>


unsigned int    list_get_size(list_t list)
{
    int count = 0;

    if (list == NULL)
        return 0;

    for (count = 0; list->next != NULL; count++) {list = list->next;}
    return (count + 1) ;
}

bool list_is_empty(list_t list)
{
    return (list == NULL) ? true : false;

}

void list_dump(list_t list, value_displayer_t val_disp)
{
    for (int count = 0; list->next != NULL; count++) {
        val_disp(list->value);
        list = list->next;
    }
    val_disp(list->value);
}

bool    list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = (*front_ptr != NULL) ? *front_ptr : NULL;
    *front_ptr = new_node;
    return (true);
}
bool    list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t back_node = malloc(sizeof(list_t));
    list_t head = *front_ptr;

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

bool    list_del_elem_at_front(list_t *front_ptr)
{
    list_t head = *front_ptr;

    if (*front_ptr == NULL)
        return (false);
    *front_ptr = head->next;
    free(head);
    return (true);
}
bool    list_del_elem_at_back(list_t *front_ptr)
{
    list_t head = *front_ptr;
    list_t back_node = NULL;

    if (*front_ptr == NULL)
        return false;
    else if (head->next == NULL) {
        free(head);
        return true;
    }
    for (int i = 0; head->next != NULL; i++) {
        if (head->next->next == NULL)
            back_node = head;
        head = head->next;
    }
    back_node->next = NULL;
    free(head);
    return true;
}

static void int_displayer(void *data)
{
    int value = *((int *)data);
    printf("%d\n", value);
}

static void test_size(list_t list_head)
{
    printf("There are %u elements in the list\n", list_get_size(list_head));
    list_dump(list_head , &int_displayer);
}
static void test_del(list_t *list_head)
{
    list_del_elem_at_back(list_head);
    printf("There are %u elements in the list\n", list_get_size(*list_head));
    list_dump(*list_head , &int_displayer);
}

int main(void) {
    list_t list_head = NULL; int i = 5;
    int j = 42;
    int k = 3;
    list_add_elem_at_back(&list_head, &i);
    list_add_elem_at_back(&list_head, &j);
    list_add_elem_at_back(&list_head, &k);
    test_size(list_head);
    test_del(&list_head);
    return 0; }
