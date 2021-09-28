#include<stdio.h>

int comptage(char *nom) {
  int nb = 0;
  FILE * f = fopen(nom,"r");
  if (f == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom);
    return 0;
  } else {
    while (!feof(f)) {
      fgetc(f);
      nb++;
    }
  }
  fclose(f);
  return nb;
}

int main(int argc, char **argv) {
  printf("%d",comptage("fichierTest.txt"));
}
