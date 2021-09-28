#include<stdio.h>

int compare(char *nom1, char*nom2) {
  int nb = 0;
  FILE * f1 = fopen(nom1,"r");
  FILE * f2 = fopen(nom2,"r");
  if (f1 == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom1);
    return 0;
  } else if (f2 == NULL) {
    fprintf(stderr,"Erreur dans l'ouverture de %s\n",nom2);
    return 0;
  } else {
    while ((!feof(f1))&&(!feof(f2))) {
      if (fgetc(f1) == fgetc(f2))
        nb++;
    }
  }
  fclose(f1);
  fclose(f2);
  return nb;
}

int main(int argc, char **argv) {
  printf("%d",compare("fichierTest.txt","autreFichierTest.txt"));
}
