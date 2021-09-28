#include "listeStringParTableau.h"
#include "listeIntParTableau.h"

#ifndef DICTIONNAIREINTSTRING_H
#define DICTIONNAIREINTSTRING_H

typedef struct {
  listeInt *cles;
  listeString *valeurs;
} dictionnaireIntString;
#endif

dictionnaireIntString* newDictionnaireIntString();
dictionnaireIntString* ajouterDictIS(dictionnaireIntString *d, int cle, char *val);
dictionnaireIntString* retirerDictIS(dictionnaireIntString *d, int cle);
char *obtenirElementDictIS(dictionnaireIntString *d, int cle);
int estPresentDictIS(dictionnaireIntString *d, int cle);
listeInt* obtenirClesDictIS(dictionnaireIntString *d);
listeString* obtenirValeursDictIS(dictionnaireIntString *d);
