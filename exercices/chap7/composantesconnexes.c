#include <stdio.h>
#include <stdlib.h>
#include "matriceAdjacence.h"
#include "listeIntParLC.h"

listeInt *parcoursProfondeur(matriceAdjacence m, int sommet,
                              int *etat, listeInt *liste) {
  etat[sommet] = 1;
  liste = insererLI(liste,0,sommet);
  for (int i = 0; i < m.nbSommets; i++) {
    if (((m.arcs[sommet][i] != 0)||(m.arcs[i][sommet] != 0)) &&
          (etat[i] == 0))
      liste = parcoursProfondeur(m,i,etat,liste);
  }
  return liste;
}

listeInt **composantesConnexes(matriceAdjacence m) {
  // un tableau de pointeurs sur listeInt est cree
  // le nombre maximum de composantes connexes est
  // le nombre de nbSommets du graphe
  listeInt **listes = (listeInt **)
                        malloc((m.nbSommets+1)*sizeof(listeInt *));
  // l'etat marque les sommets visites (1) ou non (0)
  int *etat = (int*)malloc(m.nbSommets*sizeof(int));
  int i,j;
  for (i = 0; i < m.nbSommets; i++) etat[i] = 0;
  i = 0;j = 0;
  while (i < m.nbSommets) {
    if (etat[i] == 0) {
      // quand un sommet non marque est trouve une nouvelle
      // composante connexe est creee.
      listes[j] = newListeInt();
      // un parcours en profondeur depuis le sommet ajoute a
      // la liste et marque tous les sommets atteints
      listes[j] = parcoursProfondeur(m,i,etat,listes[j]);
      j++;
    }
    i++;
  }
  listes[j] = NULL; // marque la fin de la liste de listes
  return listes;
}

int main(int argc, char **argv) {
  matriceAdjacence m;
  m.nbSommets = 9;
  m.arcs[0][4] = 1;m.arcs[0][5] = 1;
  m.arcs[1][3] = 1;
  m.arcs[2][7] = 1;
  m.arcs[3][1] = 1;
  m.arcs[4][0] = 1;m.arcs[4][6] = 1;
  m.arcs[5][0] = 1;m.arcs[5][4] = 1;m.arcs[5][6] = 1;
  m.arcs[6][4] = 1;m.arcs[6][5] = 1;
  m.arcs[7][8] = 1;m.arcs[7][2] = 1;
  m.arcs[8][7] = 1;
  listeInt **listes = composantesConnexes(m);
  int i = 0;
  while (listes[i] != NULL) {
    elementIntLC *e = listes[i]->tete;
    while (e != NULL) {
      printf("%d ",e->valeur);
      e = e->suivant;
    }
    printf("\n");
    i++;
  }
}
