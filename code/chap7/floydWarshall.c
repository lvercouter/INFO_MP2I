#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "matriceAdjacence.h"

int cheminMinimum(int ij, int ik, int kj) {
  if ((ik == INT_MAX)||(kj == INT_MAX)) return ij;
  if (ij < (ik+kj)) return ij;
  else return ik+kj;
}

matriceAdjacence *floydWarshall(matriceAdjacence m) {
  matriceAdjacence *res =
    (matriceAdjacence *)malloc(sizeof(matriceAdjacence));
  res->nbSommets = m.nbSommets;
  // la matrice est copiee dans celle du resultat produit
  // INT_MAX correspond a la valeur infinie
  for (int i = 0; i < m.nbSommets; i++)
    for (int j = 0; j < m.nbSommets; j++)
      if (m.arcs[i][j] == 0 ) res->arcs[i][j] = INT_MAX;
      else res->arcs[i][j] = m.arcs[i][j];
  // l'algorithme de Floyd-Warshall met a jour les distances minimales
  for (int k = 0; k < m.nbSommets; k++) {
    for (int i = 0; i < m.nbSommets; i++)
      for (int j = 0; j < m.nbSommets; j++)
        res->arcs[i][j] = cheminMinimum(res->arcs[i][j],
                              res->arcs[i][k],res->arcs[k][j]);
  }
  return res;
}


void afficher(matriceAdjacence *res) {
  for (int i = 0; i < res->nbSommets; i++) {
    for (int j = 0; j < res->nbSommets; j++)
      printf("%d ", res->arcs[i][j]);
    printf("\n");
  }
  printf("-------\n");
}

int main(int argc, char **argv) {
  matriceAdjacence m;
/*  m.nbSommets = 4;
  m.arcs[0][2] = -2;
  m.arcs[1][2] = 3;m.arcs[1][0] = 4;
  m.arcs[2][3] = 2;
  m.arcs[3][1] = -1;*/
  m.nbSommets = 5;
  m.arcs[0][2] = 4;
  m.arcs[1][0] = 2;m.arcs[1][4] = 3;
  m.arcs[2][3] = 3;
  m.arcs[3][0] = -2;m.arcs[3][1] = 5;
  m.arcs[4][3] = -1;
  matriceAdjacence *res = floydWarshall(m);
  afficher(res);
}
