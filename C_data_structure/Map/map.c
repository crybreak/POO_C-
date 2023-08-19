#include <stdio.h>
#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(map_t map)
{
    int count = 0;

    if (map == NULL)
        return 0;
    for (count = 0; map->next != NULL; count++) {map = map->next;}
    return (count + 1) ;
}

bool            map_is_empty(map_t map)
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
        return -1;
}

int main(void) {
    int a = 2;
    int b = 1;
    printf("%d", key_comparator(&a, &b));
}