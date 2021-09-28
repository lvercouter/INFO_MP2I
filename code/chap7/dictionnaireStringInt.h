#include "listeStringParTableau.h"
#include "listeIntParTableau.h"

#ifndef DICTIONNAIRESTRINGINT_H
#define DICTIONNAIRESTRINGINT_H

typedef struct {
  listeString *cles;
  listeInt *valeurs;
} dictionnaireStringInt;
#endif

dictionnaireStringInt* newDictionnaireStringInt();
dictionnaireStringInt* ajouterDictSI(dictionnaireStringInt *d, char *cle, int val);
dictionnaireStringInt* retirerDictSI(dictionnaireStringInt *d, char *cle);
int obtenirElementDictSI(dictionnaireStringInt *d, char *cle);
int estPresentDictSI(dictionnaireStringInt *d, char *cle);
listeString* obtenirClesDictSI(dictionnaireStringInt *d);
listeInt* obtenirValeursDictSI(dictionnaireStringInt *d);
