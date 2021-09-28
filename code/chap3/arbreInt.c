#include <stdlib.h>
#include "arbreInt.h"
#include "listeArbreParLC.h"

arbre* newArbreInt(int val) {
  arbre *a = (arbre*)malloc(sizeof(arbre));
  a->valeur = val;
  a->pere = NULL;
  a->fils = NULL;
  return a;
}

arbre* ajouterRacine(arbre *r, listeArbre *fils) {
  int nb = longueurLA(fils);
  // chaque arbre dans la liste fils est insere en
  // tete de la liste des fils de r qui devient son pere
  for (int i = 0; i < nb; i++) {
    arbre *noeud = elementALA(fils,i);
    r->fils = insererLA(r->fils,0,noeud);
    noeud->pere = r;
  }
  return r;
}

arbre* ajouterFils(arbre *r, arbre *fils) {
  fils->pere = r;
  r->fils = insererLA(r->fils,0,fils);
  return r;
}

arbre* retirerFils(arbre *r, arbre *fils) {
  int nb = longueurLA(r->fils);
  for (int i = 0; i < nb; i++) {
    if (elementALA(r->fils,i) == fils) {
      supprimerLA(r->fils,i);
      fils->pere = NULL;
      return r;
    }
  }
  return r;
}

int obtenirElementRacine(arbre *a) {
  return a->valeur;
}

listeArbre* obtenirFils(arbre *a) {
  return a->fils;
}

arbre* obtenirPere(arbre *a) {
  return a->pere;
}

int estArbreVide(arbre *a) {
  if (a == NULL) return 0;
  else return 1;
}
