#include <stdlib.h>
#include "listeChaineParTableau.h"

// constructeur pour creer une nouvelle liste vide
listeChaine* newListeChaine() {
  listeChaine *l = (listeChaine*)malloc(sizeof(listeChaine));
  l->taille = 0;
  return l;
}

listeChaine* insererChaine(listeChaine *l, int pos, char *val) {
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

listeChaine* supprimerChaine(listeChaine *l, int pos) {
  // verification que la position est valide
  if ((pos < 0) || (pos >= l->taille))
    return l;
  // on decale a l'indice d'avant toutes les valeurs
  // situees a un indice a partir de pos
  for (int i = pos; i < l->taille; i ++)
    l->valeur[i] = l->valeur[i+1];
  // on insere val a l'indice pos
  l->taille = l->taille - 1;
  return l;
}

int longueurListeChaine(listeChaine *l) {
  return l->taille;
}

int estVideListeChaine(listeChaine *l) {
  if (l->taille == 0) return 0;
  else return 1;
}

char* elementChaineA(listeChaine *l, int pos) {
  if ((pos < 0) || (pos >= l->taille))
    return 0;
  return l->valeur[pos];
}
