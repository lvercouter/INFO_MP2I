#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dictionnaireIntString.h"
#include "listeStringParTableau.h"
#include "listeIntParTableau.h"

// constructeur
dictionnaireIntString* newDictionnaireIntString() {
  dictionnaireIntString *d = (dictionnaireIntString *)malloc(sizeof(dictionnaireIntString));
  d->cles = newListeInt();
  d->valeurs = newListeString();
  return d;
}

dictionnaireIntString* ajouterDictIS(dictionnaireIntString *d, int cle, char *val) {
    int i = 0;
    while ((i < d->cles->taille) && (d->cles->valeur[i] !=cle))
      i++;
    if (i == d->cles->taille) {
      // ici la cle n'existait pas dans le dictionnaire
      d->cles = insererLI(d->cles,i,cle);
      d->valeurs = insererLS(d->valeurs,i,val);
    } else {
      // la cle est deja presente, la valeur associee est modifiee
      d->valeurs->valeur[i] = val;
    }
    return d;
}

dictionnaireIntString* retirerDictIS(dictionnaireIntString *d, int cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  if (i != d->cles->taille) {
    // la cle est trouvee a l'indice i
    d->cles = supprimerLI(d->cles,i);
    d->valeurs = supprimerLS(d->valeurs,i);
  }
  return d;
}

char *obtenirElementDictIS(dictionnaireIntString *d, int cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  // la cle est trouvee a l'indice i
  if (i != d->cles->taille) return d->valeurs->valeur[i];
  // ou elle n'est pas trouvee
  else return NULL;
}

int estPresentDictIS(dictionnaireIntString *d, int cle) {
  for (int i = 0; i < d->cles->taille; i++) {
    if (d->cles->valeur[i] == cle) return 1;
  }
  return 0;
}

listeInt* obtenirClesDictIS(dictionnaireIntString *d) {
  return d->cles;
}

listeString* obtenirValeursDictIS(dictionnaireIntString *d) {
  return d->valeurs;
}
