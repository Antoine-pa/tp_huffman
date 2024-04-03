#include "tree.h"

tree_t init_tree(char leaf_label, int weight) {
    tree_t tree = malloc(sizeof(struct tree_s));
    tree -> weight = weight;
    tree -> is_leaf = true;
    tree -> leaf_label = leaf_label;
    tree -> left_child = NULL;
    tree -> right_child = NULL;
    return tree;
}

tree_t merge_trees(tree_t left_child, tree_t right_child) {
    tree_t tree = malloc(sizeof(struct tree_s));
    tree -> weight = left_child->weight + right_child->weight;
    tree -> is_leaf = false;
    tree -> left_child = left_child;
    tree -> right_child = right_child;
    return tree;
}

void free_tree(tree_t tree) {
    if(tree == NULL) {
        return;
    }
    free_tree(tree->left_child);
    free_tree(tree->right_child);
    free(tree);
}

void print_tree(tree_t tree) {
    if(tree->is_leaf) {
        printf("%c ", tree->leaf_label);
        return;
    }
    print_tree(tree->left_child);
    print_tree(tree->right_child);
}

int tree_height(tree_t tree) {
    if(tree->is_leaf==true) {
        return 0;
    } 
    return 1+max(tree_height(tree->left_child), tree_height(tree->right_child));
}

int tree_size(tree_t t) {
    if(t->is_leaf) {
        return 1;
    }
    return 1+tree_size(t->left_child)+tree_size(t->right_child);
}