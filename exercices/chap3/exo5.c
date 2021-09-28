#include "../../code/chap3/fileInt.h"
#include "../../code/chap3/pileInt.h"

fileInt *inverse(fileInt* f) {
  fileInt *retour = newFileInt();
  pileInt *tmp = newPileInt();
  while (!estFileVide(f)) {
    tmp = empiler(tmp,obtenirElementFile(f));
    f = defiler(f);
  }
  while (!estPileVide(tmp)) {
    retour = enfiler(retour,obtenirElementPile(tmp));
    tmp = depiler(tmp);
  }
  return retour;
}
