#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnaireCharInt.h"
#include "listeCharParTableau.h"

struct AB {
  char caractere;
  int frequence;
  struct AB *gauche;
  struct AB *droit;
};
typedef struct AB arbreBinaire;

dictionnaireCharInt *comptage(char *txt) {
  dictionnaireCharInt *dic = newDictionnaireCharInt();
  for (int i = 0; i < strlen(txt); i++) {
    if (estPresentDictCI(dic,txt[i])) {
      int cpt = obtenirElementDictCI(dic,txt[i]);
      ajouterDictCI(dic,txt[i],cpt + 1);
    } else ajouterDictCI(dic,txt[i],1);
  }
  return dic;
}

arbreBinaire *arbreHuffman(dictionnaireCharInt *dic) {
  listeChar *cles = obtenirClesDictCI(dic);
  int nb = cles->taille;
  arbreBinaire **noeuds = (arbreBinaire **)
                            malloc(nb*sizeof(arbreBinaire *));
  // creation des feuilles pour chaque caractere
  for (int i = 0; i < nb; i++) {
    noeuds[i] = (arbreBinaire *)malloc(sizeof(arbreBinaire));
    noeuds[i]->caractere = cles->valeur[i];
    noeuds[i]->frequence = obtenirElementDictCI(dic,cles->valeur[i]);
  }
  // l'arbre est construit en trouvant les deux noeuds de plus petite
  // frequence a chaque iteration et en leur creant un pere commun
  while (nb > 1) {
    int n1 = 0;
    for (int i = 1; i < nb; i++) {
      if (noeuds[i]->frequence < noeuds[n1]->frequence) {
        n1 = i;
      }
    }
    // le premier noeud est mis a la fin du tableau dont on reduit la
    // taille de 1 pour ne plus le prendre en compte
    arbreBinaire *tmp = noeuds[n1];
    noeuds[n1] = noeuds[nb-1];
    noeuds[nb-1] = tmp;
    nb--;
    // un second noeud de plus petite frequence est cherche
    int n2 = 0;
    for (int i = 1; i < nb; i++) {
      if (noeuds[i]->frequence < noeuds[n2]->frequence) {
        n2 = i;
      }
    }
    // un pere est cree pour les noeuds n1 et n2 et il est mis a la place
    // de n2 dans le tableau
    arbreBinaire *pere = (arbreBinaire *)malloc(sizeof(arbreBinaire));
    pere->frequence = noeuds[nb]->frequence + noeuds[n2]->frequence;
    pere->gauche = noeuds[nb];
    pere->droit = noeuds[n2];
    noeuds[n2] = pere;
  }
  return noeuds[0];
}

void afficherArbre(arbreBinaire *a) {
  if (a != NULL) {
    printf("%c %d\n",a->caractere,a->frequence);
    afficherArbre(a->gauche);
    afficherArbre(a->droit);
  }
}

int main(int argc, char **argv) {
  //dictionnaire *d = comptage("abracadabra");
  dictionnaireCharInt *d = comptage("je regarde taratata");
  listeChar *l = obtenirClesDictCI(d);
  for (int i = 0; i < l->taille; i++)
    printf("%c %d\n",l->valeur[i],obtenirElementDictCI(d,l->valeur[i]));
  printf("-----\n");
  arbreBinaire * ab = arbreHuffman(d);
  afficherArbre(ab);
  printf("-----\n");
}
