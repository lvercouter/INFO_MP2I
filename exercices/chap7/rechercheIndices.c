#include <stdio.h>
#include <string.h>
#include "listeIntParLC.h"

listeInt *rechercheIndices(char *txt, char c) {
  listeInt *liste = newListeInt();
  for (int i = 0; i < strlen(txt); i++)
    if (txt[i] == c) liste = insererLI(liste,0,i);
  return liste;
}

int main(int argc, char **argv) {
  listeInt *l = rechercheIndices("abracadabra",'a');
  elementIntLC *e = l->tete;
  while (e != NULL) {
      printf("%d\n",e->valeur);
      e = e->suivant;
  }
}
