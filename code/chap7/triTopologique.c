#include <stdio.h>
#include <stdlib.h>
#include "matriceAdjacence.h"
#include "fileInt.h"

int *calculEntrants(matriceAdjacence m) {
  int *entrants = (int *)malloc(m.nbSommets*sizeof(int));
  // le nombre d'arcs entrants de chaque sommet est mis a 0
    for (int i = 0; i < m.nbSommets; i++)
      entrants[i] = 0;
  // pour chaque arc, le nombre d'entrants du sommet
  // de destination est incremente
  for (int i = 0; i < m.nbSommets; i++)
    for (int j = 0; j < m.nbSommets; j++)
      if (m.arcs[i][j] > 0) entrants[j]++;
  return entrants;
}

int *triTopologique(matriceAdjacence m) {
  int i = 0,j = 0;
  int *tri = (int*)malloc(m.nbSommets*sizeof(int));
  int *entrants = calculEntrants(m);
  fileInt *file = newFileInt();
  // un sommet de depart est trouve et ajoute a la file
  while (entrants[i] != 0) i++;
  enfiler(file,i);
  entrants[i] = -1;
  while (!estFileVide(file)) {
    // un sommet de la file est choisi et ajoute au tri
    tri[j] = obtenirElementFile(file);
    defiler(file);
    // le nombre d'entrants de ses successeurs est decremente
    for (int i = 0; i < m.nbSommets; i++) {
      if (m.arcs[tri[j]][i] > 0)
        entrants[i]--;
    }
    j++;
    // tout sommet sans entrant est ajoute a la file a visiter
    for (int i = 0; i < m.nbSommets; i++) {
      if (entrants[i] == 0) {
        enfiler(file,i);
        entrants[i] = -1;
      }
    }
  }
  free(entrants);
  return tri;
}

int main(int argc, char **argv) {
  matriceAdjacence m;
  m.nbSommets = 6;
  m.arcs[0][2] = 1;m.arcs[0][3] = 1;
  m.arcs[1][0] = 1;m.arcs[1][5] = 1;
  m.arcs[2][3] = 1;m.arcs[2][4] = 1;

  m.arcs[5][2] = 1;
  int *tri = triTopologique(m);
  for (int i = 0; i < m.nbSommets; i++)
    printf("%d\n",tri[i]+1);
  free(tri);
}
