#ifndef HEAP_H
#define HEAP_H

#include "tree.h"
struct heap_s {tree_t* data; int capacity; int size;};
//c'est un tableau redimensionnable contenant des arbres.
typedef struct heap_s* heap_t;

heap_t init_heap(); //création d'un tas vide

void free_heap(heap_t heap); //libération de la mémoire utilisée par un tas

void insert_heap(tree_t value, heap_t heap); //insertion d'un arbre dans le tas.
//la priorité utilisée est le champs weight de l'arbre value

tree_t extract_heap(heap_t heap); //extraction de l'arbre de poids le plus faible

int heap_size(heap_t heap);
#endif