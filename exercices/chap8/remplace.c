#include<stdio.h>

void remplace(char *nom, char ori, char nv) {
  FILE * f = fopen(nom,"r+");
  if (f == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom);
  } else {
    while (!feof(f)) {
      char c = fgetc(f);
      if (c == ori) {
        fseek(f,-1*sizeof(char),SEEK_CUR);
        fputc(nv,f);
      }
    }
    fclose(f);
  }
}

int main(int argc, char **argv) {
  remplace("autreFichierTest.txt",'e','z');
}
