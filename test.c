#include "huffman.h"

void print_codes(char** codes) {
    char* c;
    for(int i = 0; i<256; i++) {
        c = codes[i];
        if(c != NULL) {
            printf("char : %c, code : %s\n", i, c);
        }
    }
}

int main() {
    char* text = "abcaccabcbbaefgc";
    heap_t heap = build_heap_from_text(text);
    tree_t tree = build_code_from_heap(heap);
    print_tree(tree);

    char** codes = code_from_tree(tree);
    print_codes(codes);

    printf("avant l'encodage : %s\n",text);
    char* enc = encode(text, tree);
    printf("avant le décodage : %s\n", enc);
    char* dec = decode(enc, tree);
    printf("après le décodage : %s\n", dec);
    free_tree(tree);
    free_heap(heap);
    free_code(codes);
    free(enc);
    free(dec);
    return 0;
}