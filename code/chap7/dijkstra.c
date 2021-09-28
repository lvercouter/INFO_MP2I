#include <stdio.h>
#include <stdlib.h>
#include "matriceAdjacence.h"

int plusPetiteDistance(int *visite, int *dist, int n) {
  // le sommet de plus petite distance est retire de l'ensemble
  // et renvoye
  int iRes = 0;
  while (visite[iRes]) iRes++;
  for (int i = 1; i < n; i++)
    if ((!visite[i])&&(dist[i] != -1)&&(dist[i] < dist[iRes]))
      iRes = i;
  visite[iRes] = 1;
  return iRes;
}

int *dijkstra(matriceAdjacence m, int source, int destination) {
  int *pred = (int *)malloc(m.nbSommets*sizeof(int));
  int *dist = (int *)malloc(m.nbSommets*sizeof(int));
  int *visite = (int *)malloc(m.nbSommets*sizeof(int));
  int nb = m.nbSommets;
  // les distances sont initialisees
  // -1 correspond a la valeur infinie
  for (int i = 0; i < m.nbSommets; i++) {
    visite[i] = 0;
    if (i != source) dist[i] = -1;
    else dist[i] = 0;
  }
  while (nb !=0) {
    int s = plusPetiteDistance(visite,dist,m.nbSommets);
    nb--;
    for (int d = 0; d < m.nbSommets; d++) {
      if (m.arcs[s][d] > 0) {
        if ((dist[d] == -1)||((dist[s] + m.arcs[s][d]) < dist[d])) {
          dist[d] = dist[s] + m.arcs[s][d];
          pred[d] = s;
        }
      }
    }
  }
  free(dist);
  free(visite);
  return pred;
}

int main(int argc, char **argv) {
  matriceAdjacence m;
  m.nbSommets = 9;
  m.arcs[0][1] = 4;m.arcs[0][2] = 2;
  m.arcs[1][3] = 3;
  m.arcs[2][3] = 1;m.arcs[2][4] = 6;
  m.arcs[3][5] = 7;m.arcs[3][6] = 5;
  m.arcs[4][6] = 4;
  m.arcs[5][8] = 9;
  m.arcs[6][7] = 2;
  m.arcs[7][8] = 3;
  int *pred = dijkstra(m,0,8);
  int s = 8;
  while (s !=0) {
    printf("%d\n",s);
    s = pred[s];
  }
}
