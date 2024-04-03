#include "tree.h"
#include "stack.h"

#include <stdlib.h>


stack_t init_stack(){
  //On initialise la pile avec une capacité initiale de 4 et une taille nulle
  stack_t result = (stack_t)malloc(sizeof(struct stack_s));
  result->size = 0;
  int capacity = 4;
  result->capacity = capacity;
  result->data = malloc(sizeof(tree_t) * capacity);
  return result;
}

void free_stack(stack_t stack){
  free(stack->data);
  free(stack);
}

void push_stack(tree_t value, stack_t stack){
  //Le dessus de la pile est à la droite du tableau
  stack->data[stack->size] = value;
  stack->size = stack->size + 1;
  if(stack->size == stack->capacity){
    //Quand il est trop plein, on double sa taille
    tree_t* new_data = (tree_t*)malloc(sizeof(struct tree_s) * stack->capacity * 2);
    for(int i = 0; i < stack->size; i++){
      new_data[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = new_data;
    stack->capacity = stack->capacity * 2;

  }
}

bool is_empty(stack_t stack){
  if(stack->size == 0){
    return true;
  }
  else{
    return false;
  }
}

tree_t pop_stack(stack_t stack){
  if(!is_empty(stack)){
    //L'élément au sommet est toujours à droite
    tree_t result = stack->data[stack->size - 1];
    //Et on met à jour la taille après extraction
    stack->size = stack->size -1;
    if(stack->size < stack->capacity / 4){
      //Quand il est trop vide, on la divise par deux
      tree_t* new_data = (tree_t*)malloc(sizeof(struct tree_s) * stack->capacity / 2);
      for(int i = 0; i < stack->size; i++){
        new_data[i] = stack->data[i];
      }
      free(stack->data);
      stack->data = new_data;
      stack->capacity = stack->capacity / 2;
    }
    return result;
  }
  else{
    return NULL;
  }
}
