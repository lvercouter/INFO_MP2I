#include "../../code/chap3/pileInt.h"

int somme(pileInt *p) {
  int som = 0;
  while (!estPileVide(p)) {
    som = som + obtenirElementPile(p);
    p = depiler(p);
  }
  return som;
}

pileInt *copie(pileInt *p) {
  pileInt *retour = newPileInt();
  pileInt *tmp = newPileInt();
  while (!estPileVide(p)) {
    tmp = empiler(tmp,obtenirElementPile(p));
    p = depiler(p);
  }
  while (!estPileVide(tmp)) {
    retour = empiler(retour,obtenirElementPile(tmp));
    tmp = depiler(tmp);
  }
  return retour;
}
