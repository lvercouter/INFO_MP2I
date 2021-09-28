#ifndef LISTECHAINEPARTABLEAU_H
#define LISTECHAINEPARTABLEAU_H

#define TAILLE_MAX 1000

typedef struct {
  char* valeur[TAILLE_MAX];
  int taille;
} listeChaine;
#endif

listeChaine* newListeChaine();
listeChaine* insererChaine(listeChaine *l, int pos, char *val);
listeChaine* supprimerChaine(listeChaine *l, int pos);
int longueurListeChaine(listeChaine *l);
int estVideListeChaine(listeChaine *l);
char* elementChaineA(listeChaine *l, int pos);
