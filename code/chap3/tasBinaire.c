#define TAILLE_MAX_TB 1000

typedef struct {
  int noeud[TAILLE_MAX_TB];
  int taille;
} tasBinaire;

void ajouter(tasBinaire *tas, int nv_valeur) {
  int indiceNv, indicePere, tmp;
  // le nouveau noeud est ajoute en derniere position
  indiceNv = tas->taille;
  tas->noeud[indiceNv] = nv_valeur;
  tas->taille = tas->taille+1;
  while (indiceNv != 0) {
    // l'indice du pere est retrouve par une division
    // euclidienne par 2 de l'indice du noeud moins 1
    indicePere = (indiceNv-1)/2;
    if (tas->noeud[indicePere] < tas->noeud[indiceNv]) {
      tmp = tas->noeud[indicePere];
      tas->noeud[indicePere] = tas->noeud[indiceNv];
      tas->noeud[indiceNv] = tmp;
      indiceNv = indicePere;
    } else return;
  }
}

int retirer(tasBinaire *tas) {
  int racine = tas->noeud[0];
  int indiceNd = 0, filsdroit, filsgauche, tmp;
  tas->taille = tas->taille-1;
  if (tas->taille > 0) {
    //Le dernier noeud est mis en racine
    tas->noeud[0] = tas->noeud[tas->taille];
    filsgauche = 1;
    filsdroit = 2;
    // tant qu'un de ses fils est plus grand, on le permute
    // avec le fils de plus haute valeur
    while (((tas->taille>filsgauche)&&
            (tas->noeud[filsgauche] > tas->noeud[indiceNd]))||
           ((tas->taille>filsdroit)&&
            (tas->noeud[filsdroit] > tas->noeud[indiceNd]))) {
      if (tas->noeud[filsgauche] > tas->noeud[filsdroit]) {
        tmp = tas->noeud[filsgauche];
        tas->noeud[filsgauche] = tas->noeud[indiceNd];
        tas->noeud[indiceNd] = tmp;
        indiceNd = filsgauche;
      } else {
        tmp = tas->noeud[filsdroit];
        tas->noeud[filsdroit] = tas->noeud[indiceNd];
        tas->noeud[indiceNd] = tmp;
        indiceNd = filsdroit;
      }
    }
  }
  return racine;
}
