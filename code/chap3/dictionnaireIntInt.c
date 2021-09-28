#include <stdlib.h>
#include "dictionnaireIntInt.h"
#include "listeIntParTableau.h"

// constructeur
dictionnaireIntInt* newDictionnaireIntInt() {
  dictionnaireIntInt *d = (dictionnaireIntInt *)
                            malloc(sizeof(dictionnaireIntInt));
  d->cles = newListeInt();
  d->valeurs = newListeInt();
  return d;
}

dictionnaireIntInt* ajouterDictII(dictionnaireIntInt *d,
                                  int cle, int val) {
    int i = 0;
    while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
      i++;
    if (i == d->cles->taille) {
      // ici la cle n'existait pas dans le dictionnaire
      d->cles = insererLI(d->cles,i,cle);
      d->valeurs = insererLI(d->valeurs,i,val);
    } else {
      // la cle est deja presente, la valeur associee est modifiee
      d->valeurs->valeur[i] = val;
    }
    return d;
}

dictionnaireIntInt* retirerDictII(dictionnaireIntInt *d, int cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  if (i != d->cles->taille) {
    // la cle est trouvee a l'indice i
    d->cles = supprimerLI(d->cles,i);
    d->valeurs = supprimerLI(d->valeurs,i);
  }
  return d;
}

int obtenirElementDictII(dictionnaireIntInt *d, int cle) {
  int i = 0;
  while ((i < d->cles->taille) && (d->cles->valeur[i] != cle))
    i++;
  // la cle est trouvee a l'indice i
  if (i != d->cles->taille) return d->valeurs->valeur[i];
  // ou elle n'est pas trouvee
  else return 0;
}


int estPresentDictII(dictionnaireIntInt *d, int cle) {
  for (int i = 0; i < d->cles->taille; i++)
    if (d->cles->valeur[i] == cle) return 1;
  return 0;
}

listeInt* obtenirClesDictII(dictionnaireIntInt *d) {
  return d->cles;
}

listeInt* obtenirValeursDictII(dictionnaireIntInt *d) {
  return d->valeurs;
}
