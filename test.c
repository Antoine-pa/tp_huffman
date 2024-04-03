#include "huffman.h"
int main() {
    /*f995-324746*/
    tree_t t1 = init_tree(65, 5);
    tree_t t2 = init_tree(66, 3);
    tree_t t3 = merge_trees(t1, t2);
    tree_t t4 = merge_trees(t3, init_tree(67, 9));
    int h = tree_height(t4);
    int n = tree_size(t4);
    print_tree(t4);
    printf("\n");
    printf("%d %d\n", h, n);
    free_tree(t4);

    char* text = "abcaccabcbbaefgc";
    heap_t heap = build_heap_from_text(text);
    tree_t tree = build_code_from_heap(heap);

    print_tree(tree);
    printf("\n");
    char** codes = code_from_tree(tree);
    char* c;
    for(int i = 0; i<256; i++) {
        c = codes[i];
        if(c != NULL) {
            printf("char : %c, code : %s\n", i, c);
        }
    }
    printf("%s\n",text);
    char* enc = encode(text, tree);
    char* dec = decode(enc, tree);
    printf("%s\n", enc);
    printf("%s\n", dec);
    free_tree(tree);
    free_heap(heap);
    free_code(codes);
    free(enc);
    free(dec);
    return 0;
}