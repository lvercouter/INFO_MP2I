#define NB_SOMMETS_MAX 1000

typedef struct {
  int adjacence[NB_SOMMETS_MAX][NB_SOMMETS_MAX];
  int nbSommets;
} graphe;

int sommetDePlusHautDegre(graphe *g) {
  int retour = -1, maxDegre = -1;
  for (int i = 0; i < g->nbSommets; i++) {
    int degre = 0;
    for (int j = 0; j < g->nbSommets; j++) {
      if (g->adjacence[i][j] > 0) degre = degre +1;
    }
    if (degre > maxDegre) {
      maxDegre = degre;
      retour = i;
    }
  }
  return retour;
}
