#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dictionnaireCharString.h"
#include "listeStringParTableau.h"
#include "listeCharParTableau.h"

// constructeur
dictionnaireCharString* newDictionnaireCharString() {
  dictionnaireCharString *d = (dictionnaireCharString *)malloc(sizeof(dictionnaireCharString));
  d->cles = newListeChar();
  d->valeurs = newListeString();
  return d;
}

dictionnaireCharString* ajouterDCS(dictionnaireCharString *d, char cle, char *val) {
    int i = 0;
    while ((i < d->cles->taille) && (d->cles->valeur[i] !=cle))
      i++;
    if (i == d->cles->taille) {
      // ici la cle n'existait pas dans le dictionnaire
      d->cles = insererLC(d->cles,i,cle);
      d->valeurs = insererLS(d->valeurs,i,val);
    } else {
      // la cle est deja presente, la valeur associee est modifiee
      d->valeurs->valeur[i] = val;
    }
    return d;
}

dictionnaireCharString* retirerDCS(dictionnaireCharString *d, char cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  if (i != d->cles->taille) {
    // la cle est trouvee a l'indice i
    d->cles = supprimerLC(d->cles,i);
    d->valeurs = supprimerLS(d->valeurs,i);
  }
  return d;
}

char *obtenirElementDCS(dictionnaireCharString *d, char cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  // la cle est trouvee a l'indice i
  if (i != d->cles->taille) return d->valeurs->valeur[i];
  // ou elle n'est pas trouvee
  else return NULL;
}

int estPresentDCS(dictionnaireCharString *d, char cle) {
  for (int i = 0; i < d->cles->taille; i++) {
    if (d->cles->valeur[i] == cle) return 1;
  }
  return 0;
}

listeChar* obtenirClesDCS(dictionnaireCharString *d) {
  return d->cles;
}

listeString* obtenirValeursDCS(dictionnaireCharString *d) {
  return d->valeurs;
}
