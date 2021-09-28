#include <stdlib.h>
#include "ABR.h"

ABR* ajouter(ABR *a, int cle, int valeur) {
    if (a == NULL) {
      // le parcours a atteint un noeud vide
      // un noeud est cree pour stocker la cle et la valeur
      a = (ABR *)malloc(sizeof(ABR));
      a->cle = cle;
      a->valeur = valeur;
      a->gauche = NULL;
      a->droit = NULL;
    } else if (a->cle == cle) {
      //le parcours a atteint un noeud ou la cle est
      //deja presente. La valeur est remplacee
      a->valeur = valeur;
    } else if (a->cle < cle) {
      //la cle du noeud est plus petite que celle a ajouter
      //on s'oriente vers le cote droit pour l'ajout
      a->droit = ajouter(a->droit,cle,valeur);
    } else {
      //sinon on s'oriente vers le cote gauche
      a->gauche = ajouter(a->gauche,cle,valeur);
    }
    return a;
}
