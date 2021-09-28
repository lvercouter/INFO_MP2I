#include<stdio.h>
#include<stdlib.h>

struct elementLC {
  int valeur;
  struct elementLC *suivant;
};

void liberer(struct elementLC *l) {
  struct elementLC *next;
  while (l != NULL) {
    next = l->suivant;
    free(l);
    l = next;
  }
}

struct elementLC *supprimerNegatifs(struct elementLC *l) {
  struct elementLC *next, *tete;
  //on supprime tous les elements negatifs en tete de liste
  while ((l != NULL) && (l->valeur < 0)) {
    next = l->suivant;
    free(l);
    l = next;
  }
  tete = l;
  // puis on supprime tous les elements suivants negatifs
  while (l != NULL) {
    while((l->suivant != NULL) && (l->suivant->valeur < 0)) {
      next = l->suivant;
      l->suivant = next->suivant;
      free(next);
    }
  }
  return tete;
}
