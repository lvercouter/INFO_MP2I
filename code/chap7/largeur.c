#include <stdlib.h>
#include "matriceAdjacence.h"
#include "fileInt.h"

fileInt *visiter(matriceAdjacence m, int sommet, int *etat,
                      fileInt *file) {
  etat[sommet] = 2;
  for (int i = 0; i < m.nbSommets; i++) {
    if ((m.arcs[sommet][i] != 0) && (etat[i] == 0)) {
      // si un voisin i est non atteint
      // il est marque atteint et mis dans la file
      etat[i] = 1;
      file = enfiler(file,i);
    }
  }
  // ...
  // faire ici d'autres operations necessaires sur sommet
  // ...
  return file;
}

void parcoursLargeur(matriceAdjacence m, int depart) {
  // l'etat d'un sommet est 0 = non atteint, 1 = atteint, 2 = visite
  int *etat = (int *)malloc(m.nbSommets*sizeof(int));
  // tous les sommets sont marques non atteints et
  // la file est initialise avec le sommet de depart
  for (int i = 0; i < m.nbSommets; i++)
    etat[i] = 0;
  fileInt *file = newFileInt();
  file = enfiler(file,depart);
  // tant que la file n'est pas vide, on defile un sommet
  // et on le visite
  while (!estFileVide(file)) {
    int next = obtenirElementFile(file);
    file = defiler(file);
    file = visiter(m,next,etat,file);
  }
  free(file);
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
  parcoursLargeur(m,1);
}
