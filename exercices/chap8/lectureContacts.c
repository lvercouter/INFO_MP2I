#include<stdio.h>
#include<stdlib.h>
#include"contacts.h"

void affichePersonne(personne p) {
  printf("Nom = %s\n",p.nom);
  printf("Prenom = %s\n",p.prenom);
  printf("Telephone = %s\n",p.tel);
}

int main(int argc, char **argv) {
  FILE *f = fopen("contactfile","rb");
  personne p;
  while(!feof(f)) {
    fread(&p,sizeof(personne),1,f);
    affichePersonne(p);
  }
  fclose(f);
  return EXIT_SUCCESS;
}
