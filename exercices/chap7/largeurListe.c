#include <stdio.h>
#include <stdlib.h>
#include "matriceAdjacence.h"
#include "fileInt.h"
#include "listeIntParLC.h"

void ajouteVoisins(matriceAdjacence m, int sommet, int *etat,
                      fileInt *file) {
  etat[sommet] = 2;
  for (int i = 0; i < m.nbSommets; i++) {
    if ((m.arcs[sommet][i] != 0) && (etat[i] == 0)) {
      etat[i] = 1;
      enfiler(file,i);
    }
  }
}

listeInt *parcoursLargeur(matriceAdjacence m, int depart) {
  listeInt *liste = newListeInt();
  int *etat = (int *)malloc(m.nbSommets*sizeof(int));
  for (int i = 0; i < m.nbSommets; i++)
    etat[i] = 0;
  fileInt *file = newFileInt();
  enfiler(file,depart);
  while (!estFileVide(file)) {
    int next = obtenirElementFile(file);
    liste = insererLI(liste,longueurLI(liste),next);
    file = defiler(file);
    ajouteVoisins(m,next,etat,file);
  }
  free(file);
  free(etat);
  return liste;
}

int main(int argc, char **argv) {
  matriceAdjacence m;
  m.nbSommets = 6;
  m.arcs[0][1] = 1;m.arcs[0][2] = 1;m.arcs[0][3] = 1;
  m.arcs[1][1] = 1;m.arcs[1][0] = 1;m.arcs[1][5] = 1;
  m.arcs[2][3] = 1;m.arcs[2][4] = 1;
  m.arcs[4][5] = 1;
  m.arcs[5][2] = 1;
  elementIntLC * e = parcoursLargeur(m,1)->tete;
  while (e != NULL) {
    printf("%d\n",e->valeur);
    e = e->suivant;
  }
}
