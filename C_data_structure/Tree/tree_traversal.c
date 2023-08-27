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
        printf("%s", "No node to display\n");
        return;
    }
    for (count = 0; tree_node->children->next; count++) {
        dump_func(tree_node->children->value);
        tree_node->children = tree_node->children->next;
    }
}

bool init_tree(tree_t *tree_ptr, void *data)
{
    tree_ptr = malloc(sizeof (tree_t));

    if (tree_ptr == NULL)
        return false;
    (*tree_ptr)->data = data;
    (*tree_ptr)->children = NULL;
    (*tree_ptr)->pXarent = (tree_node_t*)tree_ptr;
    return (true);
}

tree_node_t *tree_add_child(tree_node_t *tree_node , void *data)
{
    list_t child = malloc(sizeof (list_t));

    if (child == NULL || tree_node == NULL)
        return NULL;
    child->value = data;
    child->next = NULL;
    if (tree_node->children == NULL)
        tree_node->children = child;
    else
        tree_node->children->next = child;
    tree_node->parent = tree_node;
    return (tree_node);
}

bool tree_destroy(tree_t *tree_ptr)
{
    int count_c = 0;
    int count_p = 0;
    tree_node_t* cast = (tree_node_t*)(tree_ptr);
    list_t tmp_c = NULL;
    tree_t tmp_p = NULL;

    if (cast == NULL)
        return false;
    for (count_p = 0; cast != NULL; count_p++ ) {
        for (count_c = 0; cast->children != NULL; count_c++) {
            tmp_c = cast->children;
            cast->children = cast->children->next;
            free(tmp_c);
        }
        tmp_p = cast;
        cast = cast->parent;
        free(tmp_p);
    }
    return true;
}

void    tree_traversal(tree_t tree, container_t *container, dump_func_t dump_func)
{
    int count = 0;

    for (count = 0; tree->parent != NULL; count++) {
        container->push_func(tree->parent, tree->data);
        dump_func(container->pop_func);
    }
}