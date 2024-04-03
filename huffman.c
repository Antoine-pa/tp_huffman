#include "huffman.h"
#include <string.h>

int* count_occurences(char* text) {
    int* occurences = malloc(sizeof(int)*256);
    int occ = 0;
    for(int i = 0; i<256; i++) {
        occ = 0;
        int j = 0;
        while(text[j] != '\0'){
            if(text[j] == i) {
                occ++;
            }
            j++;
        }
        occurences[i] = occ;
    }
    return occurences;
}

heap_t build_heap_from_text(char* text) {
    heap_t heap = init_heap();
    int* occ = count_occurences(text);
    for(int i = 0; i<256; i++) {
        if (occ[i] > 0) {
            insert_heap(init_tree(i, occ[i]), heap);
        }
    }
    free(occ);
    return heap;
}

tree_t build_code_from_heap(heap_t heap) {
    while(heap_size(heap)>1) {
        insert_heap(merge_trees(extract_heap(heap), extract_heap(heap)), heap);
    }
    return extract_heap(heap);
}

void code_from_tree_a(tree_t huffman_tree, char** codes, char* actual_code, int level) {
    if(huffman_tree == NULL) {
        return;
    }
    if(huffman_tree->is_leaf) {
        char* code = malloc(sizeof(char)*(level+1));
        strncpy(code, actual_code, level);
        code[level] = 0;
        codes[(int)huffman_tree->leaf_label] = code;
        return;
    }
    actual_code[level] = 48;
    code_from_tree_a(huffman_tree->left_child, codes, actual_code, level+1);
    actual_code[level] = 49;
    code_from_tree_a(huffman_tree->right_child, codes, actual_code, level+1);
}

char** code_from_tree(tree_t huffman_tree) {
    char** codes = (char**)malloc(sizeof(char*)*256);
    for(int i=0; i<256; i++) {
        codes[i] = NULL;
    }
    char* code = malloc(sizeof(char)*tree_height(huffman_tree));
    code_from_tree_a(huffman_tree, codes, code, 0);

    free (code);
    return codes;
}

char* encode(char* text, tree_t huffman_tree) {
    char** codes = code_from_tree(huffman_tree);
    
    int i = 0;
    int size = 0;
    while(text[i] != 0) {
        size = size+strlen(codes[(int)text[i]]); //calcul de la bonne taille du tableau final
        i++;
    }

    char* output = malloc(sizeof(char)*(size+1)); //+ 1 pour le "\0"

    i = 0; //parcours du text
    int j = 0; //parcours du tableau final
    int len; //longueur du code d'un char
    char* code; //le code d'un char
    while(text[i] != 0) {
        code = codes[(int)text[i]];
        len = strlen(code); //complexité en O(n)
        for(int k = 0; k<len; k++) {
            output[j+k] = code[k];
        }
        j = j+len;
        i++;
    }
    free_code(codes);
    output[size] = 0;
    return output;
}

int get_char(char* text, int index, tree_t huffman_tree, int* len) {
    if (huffman_tree->is_leaf) {
        return (int)huffman_tree->leaf_label;
    }
    *(len) = *(len) + 1;
    if (text[index] == 48) {
        return get_char(text, index+1, huffman_tree->left_child, len);
    }
    return get_char(text, index+1, huffman_tree->right_child, len);
}

char* decode(char* compressed_text, tree_t huffman_tree) {
    int size = 10000;
    char* output = malloc(sizeof(char)*(size+1));
    int i = 0;
    int j = 0;
    int len = 0;
    while(compressed_text[i] != 0) {
        int c = get_char(compressed_text, i, huffman_tree, &len);
        output[j] = c;
        i = i+len;
        len = 0;
        j++;
    }
    output[j] = 0;
    return output;
}

void free_code(char** code) {
    for(int i = 0; i<256; i++) {
        free(code[i]);
    }
    free(code);
}

