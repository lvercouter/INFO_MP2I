#include<stdio.h>

void afficherFichier(char *nom) {
  char car;
  FILE * f = fopen(nom,"r");
  if (f == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom);
  } else {
    while (!feof(f)) {
      car = fgetc(f);
      printf("%c",car);
    }
  }
  fclose(f);
}


int main(int argc, char **argv) {
  char nom[20];
  scanf("%s",nom);
  afficherFichier(nom);
}
