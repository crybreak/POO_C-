#include <stdio.h>
#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(map_t map)
{
    int count = 0;

    if (map == NULL)
        return 0;
    for (count = 0; map->next != NULL; count++) {map = map->next;}
    return (count + 1);
}
bool           map_is_empty(map_t map)
{
    return (map_get_size(map) == 0) ? false : true;
}

static int key_comparator(void *first_key, void *second_key)
{
    if (*((int *)first_key) == (*((int *)second_key)))
        return 0;
    else if (*((int *)first_key) > (*((int *)second_key)))
        return 1;
    else
        return (-1);
}

key_comparator_t key_cmp_container(bool store, key_comparator_t new_key_cmp)
{
    return new_key_cmp;
}

int pair_comparator(void *first, void *second)
{
    return  0;
}

bool map_add_elem(map_t *map_ptr, void *key, void *value, key_comparator_t key_cmp)
{
    return (true);
}

void map_get_elem(map_t map, void *key, key_comparator_t key_cmp)
{

}

int main(void) {
    int a = 2;
    int b = 1;
    printf("%d", key_comparator(&a, &b));
    printf
}