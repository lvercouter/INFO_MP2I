#ifndef TYPEARBREINT_H
#define TYPEARBREINT_H

struct sarbre;
struct sliste;

struct sarbre {
  int valeur;
  struct sarbre *pere;
  struct sliste *fils;
};

struct sliste {
  struct sarbre *valeur;
  struct sliste *suivant;
};

typedef struct sliste listeArbre;
typedef struct sarbre arbre;
#endif

#ifndef LISTEARBREPARLC_H
#define LISTEARBREPARLC_H

listeArbre* newlisteArbre();
listeArbre* insererLA(listeArbre *l, int pos, arbre *val);
listeArbre* supprimerLA(listeArbre *l, int pos);
int longueurLA(listeArbre *l);
int estVideLA(listeArbre *l);
arbre* elementALA(listeArbre *l, int pos);
#endif
