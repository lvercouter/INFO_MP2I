#include "listeIntParTableau.h"

#ifndef DICTIONNAIREINTINT_H
#define DICTIONNAIREINTINT_H

typedef struct {
  listeInt *cles;
  listeInt *valeurs;
} dictionnaireIntInt;
#endif

dictionnaireIntInt* newDictionnaireIntInt();
dictionnaireIntInt* ajouterDictII(dictionnaireIntInt *d,
                                  int cle, int val);
dictionnaireIntInt* retirerDictII(dictionnaireIntInt *d, int cle);
int obtenirElementDictII(dictionnaireIntInt *d, int cle);
int estPresentDictII(dictionnaireIntInt *d, int cle);
listeInt* obtenirClesDictII(dictionnaireIntInt *d);
listeInt* obtenirValeursDictII(dictionnaireIntInt *d);
