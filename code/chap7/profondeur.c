#include <stdlib.h>
#include "matriceAdjacence.h"

void visiter(matriceAdjacence m, int sommet, int *etat) {
  etat[sommet] = 1;
  for (int i = 0; i < m.nbSommets; i++) {
    if ((m.arcs[sommet][i] != 0) && (etat[i] == 0)) {
      // le parcours se poursuit vers un voisin non atteint
      visiter(m,i,etat);
    }
    // ...
    // faire ici d'autres operations necessaires sur sommet
    // ...
    etat[sommet] = 2;
  }
}

void parcoursProfondeur(matriceAdjacence m, int depart) {
  // l'etat d'un sommet est 0 = non atteint, 1 = atteint, 2 = visite
  int *etat = (int *)malloc(m.nbSommets*sizeof(int));
  // tous les sommets sont marques non atteints
  for (int i = 0; i < m.nbSommets; i++)
    etat[i] = 0;
  visiter(m,depart,etat);
  free(etat);
}

int main(int argc, char **argv) {
  matriceAdjacence m;
  m.nbSommets = 6;
  m.arcs[0][1] = 1;m.arcs[0][2] = 1;m.arcs[0][3] = 1;
  m.arcs[1][1] = 1;m.arcs[1][0] = 1;m.arcs[1][5] = 1;
  m.arcs[2][3] = 1;m.arcs[2][4] = 1;
  m.arcs[4][5] = 1;
  m.arcs[5][2] = 1;
  parcoursProfondeur(m,1);
}
