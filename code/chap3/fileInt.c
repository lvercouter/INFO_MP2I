#include <stdlib.h>
#include "fileInt.h"

// constructeur qui cree un nouvel espace pour la file
fileInt* newFileInt() {
  fileInt * f = (fileInt *)malloc(sizeof(fileInt));
  f->tete = NULL;
  f->queue = NULL;
  return f;
}

fileInt* enfiler(fileInt *f, int val) {
  //un nouvel element est cree
  elementFileInt *e = (elementFileInt *)malloc(sizeof(elementFileInt));
  e->valeur = val;
  // et devient la tete de la file
  e->precedent = NULL;
  e->suivant = f->tete;
  // si la liste etait vide, il devient aussi la queue de liste
  if (f->tete == NULL)
    f->queue = e;
  else
    f->tete->precedent = e;
  f->tete = e;
  return f;
}

fileInt* defiler(fileInt *f) {
  elementFileInt *elt;
  if (estFileVide(f))
    return f;
  else {
    elt = f->queue;
    // si la file n'avait qu'un element elle devient vide
    if (f->queue->precedent == NULL)
      f->tete = NULL;
    else
      //l'element de queue est detache du precedent
      f->queue->precedent->suivant = NULL;
    f->queue = f->queue->precedent;
    free(elt);
  }
  return f;
}

int obtenirElementFile(fileInt *f) {
  return f->queue->valeur;
}

int estFileVide(fileInt *f) {
  return (f->tete == NULL);
}
