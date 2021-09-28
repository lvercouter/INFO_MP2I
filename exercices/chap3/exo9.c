#define NB_SOMMETS_MAX 1000

typedef struct {
  int adjacence[NB_SOMMETS_MAX][NB_SOMMETS_MAX];
  int nbSommets;
} graphe;
