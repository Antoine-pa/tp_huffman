#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "heap.h"
#include "tree.h"

int* count_occurences(char* text);
heap_t build_heap_from_text(char* text);
tree_t build_code_from_heap(heap_t heap);
char** code_from_tree(tree_t huffman_tree);
char* encode(char* text, tree_t huffman_tree);
char* decode(char* compressed_text, tree_t huffman_tree);
void free_code(char** code);

#endif