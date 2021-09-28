#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct AG {
  char *nom;
  char *prenom;
  int naissance, deces;
  struct AG *mere;
  struct AG *pere;
};
typedef struct AG genealogie;

int afficherFiliation(genealogie *g, char *nom, char *prenom) {
  int trouve = 0;
  if (g != NULL) {
    if ((!strcmp(nom,g->nom))&&(!strcmp(prenom,g->prenom))) {
      trouve = 1;
      printf("%s %s ne en %d",g->prenom, g->nom, g->naissance);
      // la valeur -1000 indique que la personne est encore vivante
      if (g->deces != -1000) printf(", mort en %d\n",g->deces);
      else printf("\n");
    } else {
      trouve = afficherFiliation(g->mere,nom,prenom);
      if (trouve == 1) {
        printf("mere de %s %s ne en %d",g->prenom, g->nom,
                                        g->naissance);
        if (g->deces != -1000) printf(", mort en %d\n",g->deces);
        else printf("\n");
      } else {
        trouve = afficherFiliation(g->pere,nom,prenom);
        if (trouve == 1) {
          printf("pere de %s %s ne en %d",g->prenom, g->nom,
                                          g->naissance);
          if (g->deces != -1000) printf(", mort en %d\n",g->deces);
          else printf("\n");
        }
      }
    }
  }
  return trouve;
}

genealogie *creer(char *p, char *n, int b, int d) {
  genealogie *g = (genealogie *)malloc(sizeof(genealogie));
  g->nom = n;
  g->prenom = p;
  g->naissance = b;
  g->deces = d;
  return g;
}

int main(int argc, char **argv) {
  char nom[100] = "a",prenom[100];
  genealogie *g = creer("Thomas","Durand",1974,-1000);
  g->mere = creer("Sylvie","Deschamps",1950,-1000);
  g->pere = creer("Stéphane","Durand",1945,-1000);
  g->mere->mere = creer("Louise","Albert",1935,1994);
  g->mere->pere = creer("Charles","Deschamps",1934,1996);
  g->pere->mere = creer("Odette","Martin",1945,-1000);
  g->pere->pere = creer("Achille","Durand",1928,1979);printf("a\n");
  while (strcmp(nom,"fin")) {
    scanf("%s",nom);
    scanf("%s",prenom);
    afficherFiliation(g,nom,prenom);
  }
}
