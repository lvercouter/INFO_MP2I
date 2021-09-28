#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "dictionnaireStringInt.h"
#include "listeStringParTableau.h"
#include "listeIntParTableau.h"

// constructeur
dictionnaireStringInt* newDictionnaireStringInt() {
  dictionnaireStringInt *d = (dictionnaireStringInt *)malloc(sizeof(dictionnaireStringInt));
  d->cles = newListeString();
  d->valeurs = newListeInt();
  return d;
}

dictionnaireStringInt* ajouterDictSI(dictionnaireStringInt *d, char *cle, int val) {
    int i = 0;
    while ((i < d->cles->taille) && (strcmp(d->cles->valeur[i],cle)))
      i++;
    if (i == d->cles->taille) {
      // ici la cle n'existait pas dans le dictionnaire
      d->cles = insererLS(d->cles,i,cle);
      d->valeurs = insererLI(d->valeurs,i,val);
    } else {
      // la cle est deja presente, la valeur associee est modifiee
      d->valeurs->valeur[i] = val;
    }
    return d;
}

dictionnaireStringInt* retirerDictSI(dictionnaireStringInt *d, char *cle) {
  int i = 0;
  while ((i < d->cles->taille) && (strcmp(d->cles->valeur[i],cle)))
    i++;
  if (i != d->cles->taille) {
    // la cle est trouvee a l'indice i
    d->cles = supprimerLS(d->cles,i);
    d->valeurs = supprimerLI(d->valeurs,i);
  }
  return d;
}

int obtenirElementDictSI(dictionnaireStringInt *d, char *cle) {
  int i = 0;
  while ((i < d->cles->taille) && (strcmp(d->cles->valeur[i],cle)))
    i++;
  // la cle est trouvee a l'indice i
  if (i != d->cles->taille) return d->valeurs->valeur[i];
  // ou elle n'est pas trouvee
  else return 0;
}

int estPresentDictSI(dictionnaireStringInt *d, char *cle) {
  for (int i = 0; i < d->cles->taille; i++) {
    if (!strcmp(d->cles->valeur[i],cle)) return 1;
  }
  return 0;
}

listeString* obtenirClesDictSI(dictionnaireStringInt *d) {
  return d->cles;
}

listeInt* obtenirValeursDictSI(dictionnaireStringInt *d) {
  return d->valeurs;
}
