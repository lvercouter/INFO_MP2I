#ifndef LISTEINTPARTABLEAU_H
#define LISTEINTPARTABLEAU_H

#define TAILLE_MAX_LISTEINTPT 10000

typedef struct {
  int valeur[TAILLE_MAX_LISTEINTPT];
  int taille;
} listeInt;
#endif

listeInt* newListeInt();
listeInt* insererLI(listeInt *l, int pos, int val);
listeInt* supprimerLI(listeInt *l, int pos);
int longueurLI(listeInt *l);
int estVideLI(listeInt *l);
int elementALI(listeInt *l, int pos);
