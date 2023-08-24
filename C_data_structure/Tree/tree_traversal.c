#include "tree_traversal.h"
#include <stdlib.h>
#include <stdio.h>

bool    tree_is_empty(tree_t tree)
{
    return (tree == NULL) ? true : false;
}

void    tree_node_dump(tree_node_t *tree_node, dump_func_t dump_func)
{
    int count = 0;

    if (tree_node == NULL) {
        printf("%s", "No node to display");
    }
    for (count = 0; tree_node->children->next; count ++) {
        dump_func(tree_node->children->value);
        tree_node->children = tree_node->children->next;
    }
}

bool init_tree(tree_t *tree_ptr , void *data)
{
    tree_ptr = malloc(sizeof (tree_t));

    if (tree_ptr == NULL)
        return false;
    ((tree_node_t*)(tree_ptr))->data = data;
    ((tree_node_t*)(tree_ptr))->children = NULL;
    return (tree_ptr == NULL) ? true : false;
}

tree_node_t *tree_add_child(tree_node_t *tree_node , void *data)
{
    list_t child = malloc(sizeof (list_t));

    if (child == NULL)
        return NULL;
    child->value = data;
    child->next = NULL;
    (tree_node->children == NULL) ? (tree_node->children = child ): (tree_node->children->next = child);
    return tree_node;
}

bool tree_destroy(tree_t *tree_ptr)
{
    ret
}