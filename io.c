#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//On compte le nombre de caractère du fichier
//pour pouvoir dimensionner correcte la chaine le contenant
int file_len(char* filename){
  FILE* f = fopen(filename, "r");
  int len = 0;
  int nb_values_found = 0;
  char char_content;
  while(nb_values_found != EOF){
    nb_values_found = fscanf(f, "%c", &char_content);
    len = len + 1;
  }
  fclose(f);
  return len;
}

char* read_file_as_string(char* filename){
  int n = file_len(filename);
  char* file_content = (char*)malloc(sizeof(char) * (n+1));
  //Ici, on va parcourir deux fois le fichier,
  //la première pour obtenir n
  //et la deuxième pour copier le contenu dans file_content
  FILE* f = fopen(filename, "r");
  int nb_values_found = 0;
  int current_pos = 0;
  char char_content;
  while(nb_values_found != EOF){
    //On lit caractère par caractère jusqu'à la fin
    nb_values_found = fscanf(f, "%c", &char_content);
    if(nb_values_found == 1){
      file_content[current_pos] = char_content;
      current_pos = current_pos + 1;
    }
  }
  fclose(f);
  file_content[current_pos] = '\0';
  return file_content;
}

void write_content_to_file(char* filename, char* content){
  FILE* f = fopen(filename, "w");
  int n = strlen(content);
  //Pour l'écriture c'est plus simple, un simple parcours de la chaîne
  for(int i = 0; i < n; i++){
    fprintf(f, "%c", content[i]);
  }
  fclose(f);
}