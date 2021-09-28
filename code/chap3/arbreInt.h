#ifndef TYPEARBREINT_H
#define TYPEARBREINT_H

struct sarbre;
struct sliste;

struct sarbre {
  int valeur;
  struct sarbre *pere;
  struct sliste *fils;
};

struct sliste {
  struct sarbre *valeur;
  struct sliste *suivant;
};

typedef struct sliste listeArbre;
typedef struct sarbre arbre;
#endif

#ifndef ARBREINT_H
#define ARBREINT_H
#include "listeArbreParLC.h"

arbre* newArbreInt(int val);
arbre* ajouterRacine(arbre *r, listeArbre *fils);
arbre* ajouterFils(arbre *r, arbre *fils);
arbre* retirerFils(arbre *r, arbre *fils);
int obtenirElementRacine(arbre *a);
listeArbre* obtenirFils(arbre *a);
arbre* obtenirPere(arbre *a);
int estArbreVide(arbre *a);
#endif
