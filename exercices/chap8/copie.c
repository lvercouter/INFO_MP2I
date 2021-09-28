#include<stdio.h>

void copie(char *source, char *destination) {
  FILE * f1 = fopen(source,"r");
  FILE * f2 = fopen(destination,"w");
  if (f1 == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",source);
  } else if (f2 == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",destination);
  } else {
    while (!feof(f1)) {
      fputc(fgetc(f1),f2);
    }
  }
  fclose(f1);
  fclose(f2);
}

int main(int argc, char **argv) {
  copie("fichierTest.txt","nouveauFichierTest.txt");
}
