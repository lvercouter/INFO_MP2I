#include <stdlib.h>
#include<stdio.h>
#include "dictionnaireCharInt.h"
#include "listeCharParTableau.h"
#include "listeIntParTableau.h"

// constructeur
dictionnaireCharInt* newDictionnaireCharInt() {
  dictionnaireCharInt *d = (dictionnaireCharInt *)malloc(sizeof(dictionnaireCharInt));
  d->cles = newListeChar();
  d->valeurs = newListeInt();
  return d;
}

dictionnaireCharInt* ajouterDictCI(dictionnaireCharInt *d, char cle, int val) {
    int i = 0;
    while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
      i++;
    if (i == d->cles->taille) {
      // ici la cle n'existait pas dans le dictionnaire
      d->cles = insererLC(d->cles,i,cle);
      d->valeurs = insererLI(d->valeurs,i,val);
    } else {
      // la cle est deja presente, la valeur associee est modifiee
      d->valeurs->valeur[i] = val;
    }
    return d;
}

dictionnaireCharInt* retirerDictCI(dictionnaireCharInt *d, char cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  if (i != d->cles->taille) {
    // la cle est trouvee a l'indice i
    d->cles = supprimerLC(d->cles,i);
    d->valeurs = supprimerLI(d->valeurs,i);
  }
  return d;
}

int obtenirElementDictCI(dictionnaireCharInt *d, char cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  // la cle est trouvee a l'indice i
  if (i != d->cles->taille) return d->valeurs->valeur[i];
  // ou elle n'est pas trouvee
  else return 0;
}

int estPresentDictCI(dictionnaireCharInt *d, char cle) {
  for (int i = 0; i < d->cles->taille; i++)
    if (d->cles->valeur[i] == cle) return 1;
  return 0;
}

listeChar* obtenirClesDictCI(dictionnaireCharInt *d) {
  return d->cles;
}

listeInt* obtenirValeursDictCI(dictionnaireCharInt *d) {
  return d->valeurs;
}
