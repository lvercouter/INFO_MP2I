#ifndef LISTECHARPARTABLEAU_H
#define LISTECHARPARTABLEAU_H

#define TAILLE_MAX 10000

typedef struct {
  char valeur[TAILLE_MAX];
  int taille;
} listeChar;
#endif

listeChar* newListeChar();
listeChar* insererLC(listeChar *l, int pos, char val);
listeChar* supprimerLC(listeChar *l, int pos);
int longueurLC(listeChar *l);
int estVideLC(listeChar *l);
char elementALC(listeChar *l, int pos);
