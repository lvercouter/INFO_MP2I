#include <stdlib.h>
#include "listeCharParTableau.h"

// constructeur pour creer une nouvelle liste vide
listeChar* newListeChar() {
  listeChar *l = (listeChar*)malloc(sizeof(listeChar));
  l->taille = 0;
  return l;
}

listeChar* insererLC(listeChar *l, int pos, char val) {
  // verification que la position est valide et le tableau non plein
  if ((pos < 0) || (pos > l->taille) || (l->taille == TAILLE_MAX))
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

listeChar* supprimerLC(listeChar *l, int pos) {
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

int longueurLC(listeChar *l) {
  return l->taille;
}

int estVideLC(listeChar *l) {
  if (l->taille == 0) return 0;
  else return 1;
}

char elementALC(listeChar *l, int pos) {
  return l->valeur[pos];
}
