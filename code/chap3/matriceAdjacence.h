#ifndef MATRICEADJACENCE_H
#define MATRICEADJACENCE_H

#define MAX_SOMMETS 100

typedef struct {
  int arcs[MAX_SOMMETS][MAX_SOMMETS];
  int nbSommets;
} matriceAdjacence;
#endif
