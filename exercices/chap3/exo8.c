#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sAB {
  char *valeur;
  struct sAB *gauche;
  struct sAB *droit;
};
typedef struct sAB arbreBinaire;

float evaluer(arbreBinaire *a) {
  if (strcmp(a->valeur,"+") == 0)
    return evaluer(a->gauche) + evaluer(a->droit);
  else if (strcmp(a->valeur,"-") == 0)
    return evaluer(a->gauche) - evaluer(a->droit);
  else if (strcmp(a->valeur,"*") == 0)
    return evaluer(a->gauche) * evaluer(a->droit);
  else if (strcmp(a->valeur,"/") == 0)
    return evaluer(a->gauche) / evaluer(a->droit);
  else return atof(a->valeur);
}
