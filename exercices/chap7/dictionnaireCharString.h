#include "listeCharParTableau.h"
#include "listeStringParTableau.h"

#ifndef DICTIONNAIRECHARSTRING_H
#define DICTIONNAIRECHARSTRING_H

typedef struct {
  listeChar *cles;
  listeString *valeurs;
} dictionnaireCharString;
#endif

dictionnaireCharString* newDictionnaireCharString();
dictionnaireCharString* ajouterDCS(dictionnaireCharString *d, char cle, char *val);
dictionnaireCharString* retirerDCS(dictionnaireCharString *d, char cle);
char *obtenirElementDCS(dictionnaireCharString *d, char cle);
int estPresentDCS(dictionnaireCharString *d, char cle);
listeChar* obtenirClesDCS(dictionnaireCharString *d);
listeString* obtenirValeursDCS(dictionnaireCharString *d);
