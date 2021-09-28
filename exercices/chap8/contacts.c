#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

personne *saisiePersonne() {
  personne *p = (personne *)malloc(sizeof(personne));
  printf("Nom ? ");
  scanf("%s",p->nom);
  printf("Prenom ? ");
  scanf("%s",p->prenom);
  printf("Telephone ? ");
  scanf("%s",p->tel);
  return p;
}

int main(int argc, char **argv) {
  FILE *f = fopen("contactfile","ab");
  char encore;
  do {
    personne *p =saisiePersonne();
    fwrite(p,sizeof(personne),1,f);
    free(p);
    printf("Voulez-vous une autre saisie (o/n) ? ");
    fflush(stdin);
    scanf("%c",&encore);
  } while (encore == 'o');
  fclose(f);
  return EXIT_SUCCESS;
}
