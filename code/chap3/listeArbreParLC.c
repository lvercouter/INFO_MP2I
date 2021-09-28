#include <stdlib.h>
#include "listeArbreParLC.h"
#include "arbreInt.h"

// constructeur pour creer une nouvelle liste vide
listeArbre* newListeArbre() {
  return NULL;
}

listeArbre* insererLA(listeArbre *l, int pos, arbre *val) {
  listeArbre *tete,*nouveau;
  // verification que la position est valide et le tableau non plein
  if ((pos < 0) || (pos > longueurLA(l)))
    return l;
  // creation du nouvel element
  nouveau = (listeArbre *)malloc(sizeof(listeArbre));
  nouveau->valeur = val;
  // si l'ajout est a l'indice 0, le nouvel element devient la tete
  // de liste et son suivant est l'ancienne tete de liste
  if (pos == 0) {
    tete = nouveau;
    nouveau->suivant = l;
  } else {
    // sinon le pointeur l avance jusque l'element avant lequel le
    // nouveau doit etre insere.
    tete = l;
    for (int i = 0; i < (pos-1); i++)
      l = l->suivant;
    // le nouveau est relie entre l et son suivant
    nouveau->suivant = l->suivant;
    l->suivant = nouveau;
  }
  return tete;
}

listeArbre* supprimerLA(listeArbre *l, int pos) {
  listeArbre *tete = l, *tmp;
  // verification que la position est valide
  if ((pos < 0) || (pos >= longueurLA(l)))
    return l;
  // si l'indice est 0 on supprime la tete de liste et la nouvelle
  // tete est l'element suivant
  if (pos == 0) {
    tete = l->suivant;
    free(l);
  } else {
    // sinon le pointeur l avance jusque l'element avant celui qui
    // doit etre supprime.
    for (int i = 0; i < (pos-1); i++)
      l = l->suivant;
    // il est reliee au suivant du suivant et celui a supprimer est
    // libere
    tmp = l-> suivant;
    l->suivant = l->suivant->suivant;
    free(tmp);
  }
  return tete;
}

int longueurLA(listeArbre *l) {
  int taille = 0;
  while (l != NULL) {
    taille = taille +1;
    l = l->suivant;
  }
  return taille;
}

int estVideLA(listeArbre *l) {
  if (l == NULL) return 0;
  else return 1;
}

arbre* elementALA(listeArbre *l, int pos) {
  for (int i = 0; i < (pos); i++)
    l = l->suivant;
  return l->valeur;
}
