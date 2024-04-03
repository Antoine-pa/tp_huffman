#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a,b) (a>=b?a:b)

struct tree_s {
    int weight;
    struct tree_s* left_child;
    struct tree_s* right_child;
    bool is_leaf;
    char leaf_label;
};
typedef struct tree_s* tree_t;

tree_t init_tree(char leaf_label, int weight);
tree_t merge_trees(tree_t left_child, tree_t right_child);
void print_tree(tree_t tree);
void free_tree(tree_t tree);
int tree_height(tree_t tree);
int tree_size(tree_t t);

#endif