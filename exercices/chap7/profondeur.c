#include <stdlib.h>
#include "matriceAdjacence.h"
#include "pileInt.h"

pileInt *visiter(matriceAdjacence m, int sommet, int *etat,
                      pileInt *pile) {
  etat[sommet] = 2;
  for (int i = 0; i < m.nbSommets; i++) {
    if ((m.arcs[sommet][i] != 0) && (etat[i] == 0)) {
      // si un voisin i est non atteint
      // il est marque atteint et mis dans la pile
      etat[i] = 1;
      pile = empiler(pile,i);
    }
  }
  // ...
  // faire ici d'autres operations necessaires sur sommet
  // ...
  return pile;
}

void parcoursProfondeur(matriceAdjacence m, int depart) {
  // l'etat d'un sommet est 0 = non atteint, 1 = atteint, 2 = visite
  int *etat = (int *)malloc(m.nbSommets*sizeof(int));
  // tous les sommets sont marques non atteints et
  // la pile est initialise avec le sommet de depart
  for (int i = 0; i < m.nbSommets; i++)
    etat[i] = 0;
  pileInt *pile = newPileInt();
  pile = empiler(pile,depart);
  // tant que la pile n'est pas vide, on depile un sommet qui est visite
  while (!estPileVide(pile)) {
    int next = obtenirElementPile(pile);
    pile = depiler(pile);
    pile = visiter(m,next,etat,pile);
  }
  free(pile);
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
