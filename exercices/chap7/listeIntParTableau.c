#include <stdlib.h>
#include "listeIntParTableau.h"

// constructeur pour creer une nouvelle liste vide
listeInt* newListeInt() {
  listeInt *l = (listeInt*)malloc(sizeof(listeInt));
  l->taille = 0;
  return l;
}

listeInt* insererLI(listeInt *l, int pos, int val) {
  // verification que la position est valide et le tableau non plein
  if ((pos < 0) || (pos > l->taille) ||
        (l->taille == TAILLE_MAX_LISTEINTPT))
    return l;
  // on decale a l'indice d'apres toutes les valeurs
  // situees a un indice a partir de pos
  for (int i = l->taille; i >= pos; i --)
    l->valeur[i+1] = l->valeur[i];
  // on insere val a l'indice pos
  l->valeur[pos] = val;
  l->taille = l->taille + 1;
  return l;
}

listeInt* supprimerLI(listeInt *l, int pos) {
  // verification que la position est valide
  if ((pos < 0) || (pos >= l->taille))
    return l;
  // on decale a l'indice d'avant toutes les valeurs
  // situees a un indice a partir de pos
  for (int i = pos; i < l->taille; i ++)
    l->valeur[i] = l->valeur[i+1];
  l->taille = l->taille - 1;
  return l;
}

int longueurLI(listeInt *l) {
  return l->taille;
}

int estVideLI(listeInt *l) {
  if (l->taille == 0) return 0;
  else return 1;
}

int elementALI(listeInt *l, int pos) {
  return l->valeur[pos];
}
