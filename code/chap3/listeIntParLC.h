#ifndef lISTEINTPARLC_H
#define lISTEINTPARLC_H

struct EILC {
  int valeur;
  struct EILC *suivant;
};
typedef struct EILC elementIntLC;

struct sliste {
  int taille;
  elementIntLC *tete;
};
typedef struct sliste listeInt;
#endif

listeInt* newListeInt();
listeInt* insererLI(listeInt *l, int pos, int val);
listeInt* supprimerLI(listeInt *l, int pos);
int longueurLI(listeInt *l);
int estVideLI(listeInt *l);
int elementALI(listeInt *l, int pos);
