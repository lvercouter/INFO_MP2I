#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"contacts.h"

void affichePersonne(personne p) {
  printf("Nom = %s\n",p.nom);
  printf("Prenom = %s\n",p.prenom);
  printf("Telephone = %s\n",p.tel);
}

int main(int argc, char **argv) {
  char nom[30];
  printf("Quel nom cherchez-vous ? ");
  scanf("%s",nom);
  FILE *f = fopen("contactfile","rb");
  personne p;
  while(!feof(f)) {
    fread(&p,sizeof(personne),1,f);
    if (strcmp(nom,p.nom) == 0) {
      affichePersonne(p);
      return EXIT_SUCCESS;
    }
  }
  fclose(f);
  printf("Le nom cherche n'est pas dans le fichier.\n");
  return EXIT_SUCCESS;
}
