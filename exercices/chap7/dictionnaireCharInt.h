#include "listeCharParTableau.h"
#include "listeIntParTableau.h"

#ifndef DICTIONNAIRECHARINT_H
#define DICTIONNAIRECHARINT_H

typedef struct {
  listeChar *cles;
  listeInt *valeurs;
} dictionnaireCharInt;
#endif

dictionnaireCharInt* newDictionnaireCharInt();
dictionnaireCharInt* ajouterDictCI(dictionnaireCharInt *d, char cle, int val);
dictionnaireCharInt* retirerDictCI(dictionnaireCharInt *d, char cle);
int obtenirElementDictCI(dictionnaireCharInt *d, char cle);
int estPresentDictCI(dictionnaireCharInt *d, char cle);
listeChar* obtenirClesDictCI(dictionnaireCharInt *d);
listeInt* obtenirValeursDictCI(dictionnaireCharInt *d);
