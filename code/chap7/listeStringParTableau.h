#ifndef LISTECHARPARTABLEAU_H
#define LISTECHARPARTABLEAU_H

#define TAILLE_MAX 10000

typedef struct {
  char *valeur[TAILLE_MAX];
  int taille;
} listeString;
#endif

listeString* newListeString();
listeString* insererLS(listeString *l, int pos, char *val);
listeString* supprimerLS(listeString *l, int pos);
int longueurLS(listeString *l);
int estVideLS(listeString *l);
char *elementALS(listeString *l, int pos);
