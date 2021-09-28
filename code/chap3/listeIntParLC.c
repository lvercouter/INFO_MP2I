#include <stdlib.h>
#include "listeIntParLC.h"

// constructeur pour creer une nouvelle liste vide
listeInt* newListeInt() {
  listeInt *l = (listeInt *)malloc(sizeof(listeInt));
  l->taille = 0;
  l->tete = NULL;
  return l;
}

listeInt* insererLI(listeInt *l, int pos, int val) {
  elementIntLC *elt,*nouveau;
  // verification que la position est valide et le tableau non plein
  if ((pos < 0) || (pos > longueurLI(l)))
    return l;
  // creation du nouvel element
  nouveau = (elementIntLC *)malloc(sizeof(elementIntLC));
  nouveau->valeur = val;
  // si l'ajout est a l'indice 0, le nouvel element devient la tete
  // de liste et son suivant est l'ancienne tete de liste
  if (pos == 0) {
    nouveau->suivant = l->tete;
    l->tete = nouveau;
  } else {
    // sinon le pointeur l avance jusque l'element avant lequel le
    // nouveau doit etre insere.
    elt = l->tete;
    for (int i = 0; i < (pos-1); i++)
      elt = elt->suivant;
    // le nouveau est relie entre elt et son suivant
    nouveau->suivant = elt->suivant;
    elt->suivant = nouveau;
  }
  l->taille++;
  return l;
}

listeInt* supprimerLI(listeInt *l, int pos) {
  elementIntLC *elt = l->tete, *tmp;
  // verification que la position est valide
  if ((pos < 0) || (pos >= longueurLI(l)))
    return l;
  // si l'indice est 0 on supprime la tete de liste et la nouvelle
  // tete est l'element suivant
  if (pos == 0) {
    elt = l->tete->suivant;
    free(l->tete);
    l->tete = elt;
  } else {
    // sinon le pointeur elt avance jusque l'element avant celui qui
    // doit etre supprime.
    for (int i = 0; i < (pos-1); i++)
      elt = elt->suivant;
    // il est reliee au suivant du suivant et celui a supprimer est
    // libere
    tmp = elt-> suivant;
    elt->suivant = elt->suivant->suivant;
    free(tmp);
  }
  l->taille--;
  return l;
}

int longueurLI(listeInt *l) {
  return l->taille;
}

int estVideLI(listeInt *l) {
  return (l->taille == 0);
}

int elementALI(listeInt *l, int pos) {
  elementIntLC *elt = l->tete;
  for (int i = 0; i < pos; i++)
    elt = elt->suivant;
  return elt->valeur;
}
