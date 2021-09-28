#ifndef LISTEADJACENCE_H
#define LISTEADJACENCE_H

struct noeudListe {
  int sommet;
  struct noeudListe *suivant;
};
typedef struct noeudListe noeud;

typedef struct {
  noeud *tete;
  int nbVoisins;
} listeAdjacence;

typedef struct {
  listeAdjacence *liste;
  int nbSommets;
} listesAdjacence;
#endif
