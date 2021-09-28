#ifndef ABR_H
#define ABR_H

struct sABR {
  int cle,valeur;
  struct sABR *gauche;
  struct sABR *droit;
};
typedef struct sABR ABR;
#endif
